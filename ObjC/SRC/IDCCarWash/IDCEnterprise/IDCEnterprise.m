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

#pragma mark -
#pragma mark Private

- (instancetype)initWithTitle:(NSString *)title {
    self = [self init];
    
    return self;
}

#pragma mark -
#pragma mark Private

- (void)hireStaff {
    
    NSArray *carWashers = [IDCCarWasher objectsWithCount:kIDCWashersCount observer:self];
    self.washerDispatcher = [[[IDCDispatcher alloc] initWithStaff:carWashers] autorelease];
    
    NSArray *accountants = [IDCAccountant objectsWithCount:kIDCAccountantCount observer:self];
    self.accountantDispatcher = [[[IDCDispatcher alloc] initWithStaff:accountants] autorelease];
    
    NSArray *boss = [IDCBoss objectsWithCount:kIDCBossCount observer:self];
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

@end
