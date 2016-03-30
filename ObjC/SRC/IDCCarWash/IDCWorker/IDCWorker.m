//
//  IDCWorker.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 10.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCWorker.h"
#import "IDCCar.h"
#import "IDCAccountant.h"
#import "IDCCarWasher.h"
#import "IDCBoss.h"

@interface IDCWorker ()

- (void)completeWorkWithObject:(id)object;
- (void)completeWork;

@end

@implementation IDCWorker

@synthesize money = _money;

#pragma mark -
#pragma mark Class

+ (instancetype)workerWithRandomName {
    return [[[self alloc] initWithRandomName] autorelease];
}

#pragma mark -
#pragma mark Initialization and Deallocation

- (instancetype)initWithRandomName {
    self = [super init];
    if (self) {
        NSString *name = [[IDCRandomNamesArray randomNamesArray] nameFromArray];
        self.name = name;
        self.state = kIDCWorkerFree;
    }
    
    return  self;
}

#pragma mark -
#pragma mark Public

- (SEL)selectorForState:(NSUInteger)state {
    switch (state) {
        case kIDCWorkerFree:
            return @selector(workerFree:);
            
        case kIDCWorkerBusy:
            return @selector(workerBusy:);
            
        case kIDCWorkerStandby:
            return @selector(workerStandby:);
            
        default:
            return [super selectorForState:state];
    }
}

- (void)performWork:(id)object {
    self.state = kIDCWorkerBusy;
    [self takeMoney:[object giveMoney]];
    [self completeWorkWithObject:object];
    [self completeWork];
    
}

- (void)sayNameProfession {
    NSString *name = self.name;
    NSString *profession = [[self className] substringFromIndex:3];
    NSLog(@"My name is %@. I'm %@.", name, profession);
}

#pragma mark -
#pragma mark Private

- (void)completeWorkWithObject:(id)object {
    IDCWorker *worker = (IDCWorker *)object;
    worker.state = kIDCWorkerFree;
}

- (void)completeWork {
    self.state = kIDCWorkerStandby;
}

#pragma mark -
#pragma mark IDCMoneyProtocol

- (NSUInteger)giveMoney {
    NSUInteger payment = self.money;
    self.money = 0;
    
    return payment;
}

- (void)takeMoney:(NSUInteger)money {
    self.money += money;
}

#pragma mark -
#pragma mark IDCWorkerProtocol

- (void)workerStandby:(id)worker {
    [self performWork:worker];
}

@end
