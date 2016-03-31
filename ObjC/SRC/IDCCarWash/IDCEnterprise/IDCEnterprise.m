//
//  IDCEnterprise.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 10.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCEnterprise.h"

@interface IDCEnterprise ()
@property (nonatomic, retain) NSMutableArray *staff;
@property (nonatomic, retain) NSMutableArray *cars;

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
    self.cars = nil;
    
    [super dealloc];
}

- (instancetype)initWithTitle:(NSString *)title {
    self = [super init];
    
    if (self) {
        self.title = title;
        self.money = 0;
        self.cars  = [NSMutableArray object];
        [self hireStaff];
    }
    
    return self;
}

#pragma mark -
#pragma mark Private

- (void)hireStaff {
    IDCAccountant *accountant = [[[IDCAccountant alloc] initWithRandomName] autorelease];
    IDCBoss *boss = [[[IDCBoss alloc] initWithRandomName] autorelease];
    [accountant addObserver:boss];
    
    NSMutableArray *staff = [NSMutableArray object];
    staff = [[@[accountant, boss] mutableCopy] autorelease];
    
    NSArray *carWashers = [self objectsWithCount:kIDCWorkersCount class:[IDCCarWasher class]];
    for (IDCCarWasher *carWasher in carWashers) {
        carWasher.name = [[IDCRandomNamesArray randomNamesArray] nameFromArray];
        [carWasher addObserver:accountant];
    }
    
    [staff addObjectsFromArray:carWashers];
    
    self.staff = staff;

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
    if (car.isDirty) {
        [self.cars addObject:car];
        IDCCarWasher *carWasher =  [self vacantWorkerOfClass:[IDCCarWasher class]];
        
        @synchronized (carWasher) {
                if (carWasher) {
                    IDCCar *car = [self.cars lastObject];
                    [self.cars removeLastObject];
                    [carWasher performWork:car];
                }
        }
    }
}

@end
