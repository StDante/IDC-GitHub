//
//  IDCLoadingView.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 13.06.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCLoadingView.h"
#import "IDCSpinnerView.h"
#import "UINib+IDCUINib.h"


static NSString * const kIDCDefaultLodingText = @"Loading. Please wait!";
static CGFloat    const kIDCDefaultDuration   = 1.0;
static CGFloat    const kIDCLoadingAlpha      = 0.8;
static CGFloat    const kIDCRemovingAlpha     = 0.2;

@interface IDCLoadingView ()
@property (nonatomic, strong) IDCSpinnerView *loadingView;

@end

@implementation IDCLoadingView

#pragma mark -
#pragma mark Public

- (void)showLoadingView {
    [self showLoadingViewWithText:nil];
}

- (void)showLoadingViewWithDefaultText {
    [self showLoadingViewWithDefaultTextAnimated:NO];
}

- (void)showLoadingViewWithDefaultTextAnimated:(BOOL)animated {
    [self showLoadingViewWithText:kIDCDefaultLodingText animated:animated];
}

- (void)showLoadingViewWithText:(NSString *)text {
    [self showLoadingViewWithText:text animated:NO];
}

- (void)showLoadingViewWithText:(NSString *)text animated:(BOOL)animated {
    IDCSpinnerView *view = self.loadingView;
    if (!view) {
        view = [UINib objectFromNibOfClass:[IDCSpinnerView class]];
        view.frame = self.frame;
        view.label.text = text;
        self.loadingView = view;
        
        [UIView animateWithDuration:animated ? kIDCDefaultDuration : 0
                         animations:^{
                             view.alpha = kIDCLoadingAlpha;
                             [self addSubview:view];
                         }];
    }
}

- (void)removeLoadingView {
    [self removeLoadingViewAnimated:NO];
}

- (void)removeLoadingViewAnimated:(BOOL)animated {
    IDCSpinnerView *loadingView = self.loadingView;
    [UIView animateWithDuration:animated ? kIDCDefaultDuration : 0
                     animations:^{
                         loadingView.alpha = kIDCRemovingAlpha;
                     } completion:^(BOOL finished) {
                         [loadingView removeFromSuperview];
                         self.loadingView = nil;
                     }];
}

@end
