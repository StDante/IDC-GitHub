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
#import "IDCCarWasher.h"
#import "IDCAccountant.h"
#import "IDCBoss.h"

@interface IDCEnterprise ()
@property (nonatomic, retain)   NSMutableArray *staff;

- (void)hireStaff;
- (void)dismissWorker:(IDCWorker *)worker;
- (void)dismissStaff;
- (id)vacantWorkerOfClass:(Class)class;

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
    [self dismissStaff];
    self.title = nil;
    
    [super dealloc];
}

- (instancetype)initWithTitle:(NSString *)title {
    self = [super init];
    
    if (self) {
        self.title = title;
        self.money = 0;
        self.staff = nil;
        [self hireStaff];
    }
    
    return self;
}

#pragma mark -
#pragma mark Private

- (void)hireStaff {
    IDCCarWasher *carWasher = [[[IDCCarWasher alloc] initWithRandomName] autorelease];
    IDCAccountant *accountant = [[[IDCAccountant alloc] initWithRandomName] autorelease];
    IDCBoss *boss = [[[IDCBoss alloc] initWithRandomName] autorelease];
    
    [carWasher addObserver:accountant];
    [accountant addObserver:boss];
    
    self.staff = [[@[carWasher, accountant, boss] mutableCopy] autorelease];

}

- (void)dismissWorker:(IDCWorker *)worker {
    for (NSUInteger index = 0; index < self.staff.count; index++) {
        IDCWorker *observer = self.staff[index];
        if ([worker observedObject:observer]) {
            [worker removeObserver:observer];
        }
    }
    
    [self.staff removeObject:worker];
}


- (void)dismissStaff {
    NSArray *staff = [[self.staff copy] autorelease];
    for (IDCWorker *worker in staff) {
        [self dismissWorker:worker];
    }
}

- (id)vacantWorkerOfClass:(Class)class {
    for (IDCWorker *worker in self.staff) {
        if ([worker isMemberOfClass:class] && worker.state == kIDCWorkerFree) {
            
            return worker;
        }
    }
    
    return nil;
}

#pragma mark -
#pragma mark Public

- (void)washCar:(IDCCar *)car {
    IDCCarWasher *carsWasher =  [self vacantWorkerOfClass:[IDCCarWasher class]];
    [carsWasher performWork:car];
}

@end
