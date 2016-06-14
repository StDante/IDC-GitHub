//
//  UITableView+IDCUITableView.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 25.05.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UITableView (IDCUITableView)

- (UITableViewCell *)dequeueReusableCellWithClass:(Class)theClass;
- (id)dequeueReusableCellFromNibWithClass:(Class)theClass;

@end
