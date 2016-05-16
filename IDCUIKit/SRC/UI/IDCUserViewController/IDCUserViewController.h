//
//  IDCUserViewController.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 09.05.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IDCUserView.h"
#import "IDCObjCMacro.h"
#import "IDCArrayModel.h"
#import "IDCStringModel.h"
#import "IDCUserViewCell.h"

@interface IDCUserViewController : UIViewController <UIToolbarDelegate, UITableViewDataSource>
@property (nonatomic, strong) IDCArrayModel *arrayModel;

- (IBAction)onUpdateCellsButton:(id)sender;
- (IBAction)onStartEditingSwitch:(id)sender;

@end
