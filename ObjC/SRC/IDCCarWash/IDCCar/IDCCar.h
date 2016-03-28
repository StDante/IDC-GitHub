//
//  IDCCar.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 10.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDCConstants.h"

@interface IDCCar : NSObject 
@property (nonatomic, copy)   NSString   *model;
@property (nonatomic, assign) NSUInteger money;
@property (nonatomic, assign) BOOL       isDirty;

+ (instancetype)carWithModel:(NSString *)model money:(NSUInteger)money dirt:(BOOL)isDirty;
- (instancetype)initWithModel:(NSString *)model money:(NSUInteger)money dirt:(BOOL)isDirty;


@end
