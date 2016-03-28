//
//  IDCEnterprise.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 10.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IDCWorker;
@class IDCCar;

@interface IDCEnterprise : NSObject
@property (nonatomic, copy)   NSString   *title;
@property (nonatomic, assign) IDCWorker  *cleaner;
@property (nonatomic, assign) IDCWorker  *bookkeeper;
@property (nonatomic, assign) IDCWorker  *boss;
@property (nonatomic, assign) NSUInteger money;

+ (instancetype)enterpriseWithTitle:(NSString *)title;
- (instancetype)initWithTitle:(NSString *)title;
- (void)performCarWash:(IDCCar *)car;
- (void)carWashing:(IDCCar *)car;
- (void)calculateMoney;
- (void)bossJob;

@end
