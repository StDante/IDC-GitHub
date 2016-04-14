//
//  IDCEnterprise.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 10.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCEnterprise.h"
#import "IDCQueue.h"
#import "IDCDispatcher.h"

@interface IDCEnterprise ()
@property (nonatomic, retain) IDCDispatcher  *washerDispatcher;
@property (nonatomic, retain) IDCDispatcher  *accountantDispatcher;
@property (nonatomic, retain) IDCDispatcher  *bossDispatcher;

- (void)hireStaff;
- (void)addHandlerForStandby:(NSArray *)staff;

@end

@implementation IDCEnterprise

#pragma mark -
#pragma mark Class

+ (instancetype)enterpriseWithTitle:(NSString *)title {
    return [[[self alloc] initWithTitle:title] autorelease];
}

#pragma mark -
#pragma mark Initialization and Deallocation

- (void)dealloc {
    self.washerDispatcher = nil;
    self.accountantDispatcher = nil;
    self.bossDispatcher = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        [self hireStaff];
    }
    
    return self;
}

- (instancetype)initWithTitle:(NSString *)title {
    self = [self init];
    
    return self;
}

#pragma mark -
#pragma mark Private

- (void)hireStaff {
    
    NSArray *carWashers = [IDCCarWasher objectsWithCount:kIDCWashersCount];
    self.washerDispatcher = [[[IDCDispatcher alloc] initWithStaff:carWashers] autorelease];
    [self addHandlerForStandby:carWashers];
    
    NSArray *accountants = [IDCAccountant objectsWithCount:kIDCAccountantCount];
    self.accountantDispatcher = [[[IDCDispatcher alloc] initWithStaff:accountants] autorelease];
    [self addHandlerForStandby:accountants];
    
    NSArray *boss = [IDCBoss objectsWithCount:kIDCBossCount];
    self.bossDispatcher = [[[IDCDispatcher alloc] initWithStaff:boss] autorelease];
}

#pragma mark -
#pragma mark Public

- (void)washCar:(IDCCar *)car {
    @synchronized (self) {
        [self.washerDispatcher addObjectToQueue:car];
    }
}

#pragma mark -
#pragma mark IDCWorker Protocol

- (void)workerStandby:(id)object {
    if ([self.washerDispatcher containsObject:object]) {
        [self.accountantDispatcher addObjectToQueue:object];
    }
    
    if ([self.accountantDispatcher containsObject:object]) {
        [self.bossDispatcher addObjectToQueue:object];
    }
}

#pragma mark -
#pragma mark HandlersLogic

- (void)addHandlerForStandby:(NSArray *)staff {
    @synchronized(self) {
        for (IDCWorker *worker in staff) {
            [worker addHandler:^{
                [self workerStandby:worker];
            } forState:kIDCWorkerStandby object:self];
            
            [worker addHandler:^{
                NSLog(@"Testing Handler");
            } forState:kIDCWorkerStandby object:self];
            
        }
    }
}

@end
