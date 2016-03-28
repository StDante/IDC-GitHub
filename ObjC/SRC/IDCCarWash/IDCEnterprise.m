//
//  IDCEnterprise.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 10.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCEnterprise.h"
#import "IDCWorker.h"
#import "IDCCar.h"

@implementation IDCEnterprise

#pragma mark -
#pragma mark Class

+ (instancetype)enterpriseWithTitle:(NSString *)title {
    return [[[self alloc] initWithTitle:title] autorelease];
}

#pragma mark -
#pragma mark Initialization and Deallocation

- (void)dealloc {
    self.title = nil;
    
    [super dealloc];
}

- (instancetype)initWithTitle:(NSString *)title {
    self = [super init];
    
    if (self) {
        self.cleaner = [IDCWorker workerWithName:@"Cleaner"];
        self.bookkeeper = [IDCWorker workerWithName:@"Bookkeeper"];
        self.boss = [IDCWorker workerWithName:@"Boss"];
        self.money = 0;
    }
    
    return self;
}

#pragma mark -
#pragma mark Work

- (void)performCarWash:(IDCCar *)car {
    if ([car isWashing]) {
        [self carWashing:car];
        [self calculateMoney];
        [self bossJob];
    }
}

- (void)carWashing:(IDCCar *)car {
    [self.cleaner carWashing:car];
    [self.cleaner giveMoneyTo:self.bookkeeper];
}

- (void)calculateMoney {
    [self.bookkeeper calculateMoney];
    [self.bookkeeper giveMoneyTo:self.boss];
}

- (void)bossJob {
    [self.boss bossJob];
    self.money = self.boss.cashFlow;
}

@end
