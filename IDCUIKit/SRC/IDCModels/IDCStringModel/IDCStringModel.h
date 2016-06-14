//
//  IDCStringModel.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 09.05.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NSString+IDCRandomString.h"

@class UIImage;

@interface IDCStringModel : NSObject <NSCoding>
@property (nonatomic, readonly) NSString    *string;
@property (nonatomic, readonly) NSString    *urlString;

+ (instancetype)randomStringModel;
+ (instancetype)stringModelWithString:(NSString *)string;
+ (NSArray *)randomStringsModels;

- (instancetype)initWithString:(NSString *)string;

@end
