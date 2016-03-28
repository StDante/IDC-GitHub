//
//  IDCWorker.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 10.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>
@class IDCCar;

@interface IDCWorker : NSObject
@property (nonatomic, copy)   NSString   *name;
@property (nonatomic, assign) NSUInteger cashFlow;

+ (instancetype)workerWithName:(NSString *)name;
- (instancetype)initWithName:(NSString *)name;
- (void)carWashing:(IDCCar *)car;
- (void)calculateMoney;
- (void)bossJob;
- (void)giveMoneyTo:(IDCWorker *)worker;

@end
