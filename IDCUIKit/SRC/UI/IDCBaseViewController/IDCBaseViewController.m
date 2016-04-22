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

//- viewWillDisappear {
//    
//}
//
//- viewDidDisappear {
//    
//}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
