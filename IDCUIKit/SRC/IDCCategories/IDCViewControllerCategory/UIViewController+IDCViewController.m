//
//  UIViewController+IDCViewController.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 02.05.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "UIViewController+IDCViewController.h"

@implementation UIViewController (IDCViewController)

+ (instancetype)controllerFromNib {
    return [self controllerFromNibWithName:NSStringFromClass([self class])];
}

+ (instancetype)controllerFromNibWithName:(NSString *)className {
    return [[[self class] alloc] initWithNibName:className bundle:[NSBundle mainBundle]];
}

@end
