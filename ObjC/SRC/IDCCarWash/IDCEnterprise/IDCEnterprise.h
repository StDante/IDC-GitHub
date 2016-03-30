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

@class IDCCar;

@interface IDCEnterprise : NSObject
@property (nonatomic, copy)   NSString   *title;
@property (nonatomic, assign) NSUInteger money;

- (void)washCar:(IDCCar *)car;

@end
