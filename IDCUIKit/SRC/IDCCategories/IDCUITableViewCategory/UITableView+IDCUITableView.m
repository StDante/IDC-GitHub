//
//  UITableView+IDCUITableView.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 25.05.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "UITableView+IDCUITableView.h"
#import "UINib+IDCUINib.h"

@implementation UITableView (IDCUITableView)


- (UITableViewCell *)dequeueReusableCellWithClass:(Class)theClass {
    UITableViewCell *cell = [self dequeueReusableCellWithIdentifier:NSStringFromClass([theClass class])];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault
                                      reuseIdentifier:NSStringFromClass([theClass class])];
    }
    
    return cell;
}

- (id)dequeueReusableCellFromNibWithClass:(Class)theClass {
    id cell = [self dequeueReusableCellWithIdentifier:NSStringFromClass([theClass class])];
    if (!cell) {
        cell = [UINib objectFromNibOfClass:[theClass class]];
    }
    
    return cell;
}

@end
