//
//  IDCWorker.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 10.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCWorker.h"

@implementation IDCWorker

#pragma mark -
#pragma mark Class

+ (instancetype)workerWithName:(NSString *)name {
    return [[[self alloc] initWithName:name] autorelease];
}

#pragma mark -
#pragma mark Initialization and Deallocation

- (void)dealloc {
    self.name = nil;
    
    [super dealloc];
}

- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    
    self.name = name;
    self.cashFlow = 0;
    
    return self;
}

#pragma mark -
#pragma mark Work

- (void)carWashing:(IDCCar *)car {
    [car carWashed];
}

- (void)calculateMoney {
    NSLog(@"Cleaner gave me %lu", self.cashFlow);
}

- (void)bossJob {
    NSLog(@"I'm BigBoss, I have %lu $", self.cashFlow);
}

- (void)giveMoneyTo:(IDCWorker *)worker {
    worker.cashFlow = worker.cashFlow + self.cashFlow;
    self.cashFlow = 0;
}

@end
