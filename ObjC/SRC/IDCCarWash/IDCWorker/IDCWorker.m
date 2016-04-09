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
    return [[[self alloc] init] autorelease];
}

+ (NSArray *)objectsWithCount:(NSUInteger)count observer:(id)observer {
    NSArray *array = [self objectsWithCount:count];
    for (IDCWorker *worker in array) {
        [worker addObserver:observer];
    }
    
    return [[array copy] autorelease];
}

#pragma mark -
#pragma mark Initialization and Deallocation

- (void)dealloc {
    [self.workersQueue dealloc];
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        NSString *name = [[IDCRandomNamesArray randomNamesArray] nameFromArray];
        self.name = name;
        self.workersQueue = [IDCQueue object];
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

- (void)sayNameProfession {
    NSString *name = self.name;
    NSString *profession = [[self className] substringFromIndex:3];
    NSLog(@"My name is %@. I'm %@.", name, profession);
}

- (void)performWork:(id<IDCMoneyProtocol>)object {
    self.state = kIDCWorkerBusy;
    [self performSelectorInBackground:@selector(performWorkWithObjectInBackground:)
                           withObject:object];
}

#pragma mark -
#pragma mark Private

- (void)performWorkWithObjectInBackground:(id<IDCMoneyProtocol>)object {
    @synchronized (self) {
        usleep(arc4random_uniform(100000) + 1000);
        [self workWithObject:object];
//        NSLog(@"%@ gave me money", object);
        [self performSelectorOnMainThread:@selector(completeWork) withObject:nil waitUntilDone:0];
    }
}

- (void)workWithObject:(id)object {
    [self takeMoney:[object giveMoney]];
    [self completeWorkWithObject:object];
}

- (void)completeWorkWithObject:(IDCWorker *)worker {
    worker.state = kIDCWorkerFree;
}

- (void)completeWork {
    self.state = kIDCWorkerStandby;
}

#pragma mark -
#pragma mark IDCMoneyProtocol

- (NSUInteger)giveMoney {
    @synchronized (self) {
        NSUInteger payment = self.money;
        self.money = 0;
        
        return payment;
    }
}

- (void)takeMoney:(NSUInteger)payment {
    @synchronized (self) {
        self.money += payment;
//        NSLog(@"payment is %lu", payment);
    }
}

@end
