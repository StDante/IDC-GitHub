//
//  IDCEnterprise.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 10.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDCWorker.h"
#import "IDCCarWasher.h"
#import "IDCAccountant.h"
#import "IDCBoss.h"
#import "IDCConstants.h"
#import "IDCCar.h"

@interface IDCEnterprise : NSObject <IDCWorkerProtocol>
@property (nonatomic, copy)   NSString   *title;
@property (nonatomic, assign) NSUInteger money;

+ (instancetype)enterpriseWithTitle:(NSString *)title;
- (instancetype)initWithTitle:(NSString *)title;

- (void)washCar:(IDCCar *)car;

@end
