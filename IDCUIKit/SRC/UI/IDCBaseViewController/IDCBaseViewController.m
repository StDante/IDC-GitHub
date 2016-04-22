//
//  IDCBaseViewController.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 19.04.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCBaseViewController.h"

@interface IDCBaseViewController ()
@property (nonatomic, strong) IBOutlet IDCSquareView  *rootView;
@property (nonatomic, strong) IBOutlet      UIButton  *button;

@end

@implementation IDCBaseViewController

#pragma mark -
#pragma mark Accessors

- (IDCSquareView *)rootView {
    IDCGetRootViewAndReturnNilMacro(IDCSquareView);
}

#pragma mark -
#pragma mark Controller Lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.rootView = [[IDCSquareView alloc] init];
    self.rootView.backgroundColor = [UIColor redColor];
    
}

#pragma mark -
#pragma mark Interface Handler

- (IBAction)onPressButton:(id)sender {
    [self.rootView setSquarePosition:kIDCLowerLeft];
    [self.rootView setSquarePosition:kIDCUpperRight animated:YES];
}

@end
