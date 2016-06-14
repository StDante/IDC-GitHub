//
//  IDCImageView.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 12.06.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCImageView.h"
#import "IDCImageModel.h"

@interface IDCImageView ()
@property (nonatomic, strong) UIImageView               *imageView;
@property (nonatomic, strong) UIActivityIndicatorView   *spinner;
@property (nonatomic, strong) IDCImageModel              *model;

- (void)performSpinnerAnimation;
- (void)baseInit;
- (void)load;
- (void)dump;

@end

@implementation IDCImageView

#pragma mark -
#pragma mark Initializations & Deallocations

- (instancetype)initWithCoder:(NSCoder *)coder {
    self = [super initWithCoder:coder];
    if (self) {
        [self baseInit];
    }
    
    return self;
}

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        [self baseInit];
    }
    
    return self;
}

- (void)baseInit {
    UIImageView *imageView = [[UIImageView alloc] initWithFrame:self.bounds];
    [self addSubview:imageView];
    self.imageView = imageView;
    [self performSpinnerAnimation];
    self.model = [IDCImageModel new];
}

#pragma mark -
#pragma mark Accessors

- (void)setModel:(IDCImageModel *)model {
    if (_model != model) {
        _model = model;
        
        IDCWeakifyMacro;
        [_model addHandler:^(UIImage *image){
            IDCStrongifyReturnIfNillMacro(IDCImageView);
            strongSelf.imageView.image = image;
            [strongSelf.spinner stopAnimating];
        } forState:kIDCModelLoadedState
                    object:self];
        
        [_model addHandler:^(UIImage *image){
            IDCStrongifyReturnIfNillMacro(IDCImageView);
            strongSelf.model.URL = strongSelf.URL;
        } forState:kIDCModelFailedState
                    object:self];
    }
}

- (void)setURL:(NSURL *)URL {
    if (_URL != URL) {
        _URL = URL;
        
        [self dump];
        [self load];
    }
}

#pragma mark -
#pragma mark Private

- (void)dump {
    self.imageView.image = nil;
}

- (void)load {
    [self.spinner startAnimating];
    self.model.URL = self.URL;
}

- (void)performSpinnerAnimation {
    UIActivityIndicatorView *spinner = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhite];
    
    spinner.color = [UIColor blackColor];
    UIImageView *imageView = self.imageView;
    [imageView addSubview:spinner];
    spinner.center = imageView.center;
    spinner.hidesWhenStopped = YES;
    self.spinner = spinner;
}

@end


