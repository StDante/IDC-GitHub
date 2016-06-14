//
//  IDCUserViewCell.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 09.05.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IDCStringModel.h"

@class IDCImageView;

@interface IDCUserViewCell : UITableViewCell
@property (nonatomic, strong) IBOutlet UIView             *cellBackgroundView;
@property (nonatomic, strong) IBOutlet UILabel            *cellLabel;
@property (nonatomic, strong) IBOutlet IDCImageView       *cellImage;

- (void)fillWithModel:(id)theModel;

@end
