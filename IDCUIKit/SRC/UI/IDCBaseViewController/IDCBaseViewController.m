//
//  IDCBaseViewController.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 19.04.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCBaseViewController.h"

@interface IDCBaseViewController ()
@property (nonatomic, readonly) IDCSquareView   *rootView;

@end

@implementation IDCBaseViewController

#pragma mark -
#pragma mark Accessors

IDCRootViewIfReturnNilMacro(IDCSquareView);

#pragma mark -
#pragma mark Controller Lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];
}

#pragma mark -
#pragma mark Interface Handler

- (IBAction)onPressButton:(id)sender {
    [self.rootView moveLabel];
}

@end
