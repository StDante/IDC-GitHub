//
//  UIViewController+IDCViewController.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 02.05.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIViewController (IDCViewController)

+ (instancetype)controllerFromNib;
+ (instancetype)controllerFromNibWithName:(NSString *)className;

@end
