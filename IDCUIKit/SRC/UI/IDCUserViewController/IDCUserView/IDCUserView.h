//
//  IDCUserView.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 09.05.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IDCUserViewCell.h"

@interface IDCUserView : UIView
@property (nonatomic, strong) IBOutlet UITableView  *tableView;
@property (nonatomic, retain) IBOutlet UIButton     *reloadButton;
@property (nonatomic, strong) IBOutlet UISwitch     *editSwitch;


@end
