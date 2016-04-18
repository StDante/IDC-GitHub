//
//  IDCDispatcher.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 06.04.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCDispatcher.h"

@interface IDCDispatcher ()
@property (nonatomic, retain) IDCQueue       *queue;
@property (nonatomic, retain) NSMutableArray *staff;


- (IDCWorker *)vacantWorker;
- (void)workWithObject:(id)objedt;
- (void)workerFree:(id)worker;

@end

@implementation IDCDispatcher

#pragma mark -
#pragma mark Initialization and Deallocation

- (void)dealloc {
    [self.staff makeObjectsPerformSelector:@selector(removeObserver:) withObject:self];
    self.staff = nil;
    self.queue = nil;
    
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.queue = nil;
        self.staff = nil;
    }
    
    return self;
}

- (instancetype)initWithStaff:(NSArray *)staff {
    self = [self init];
    if (self)   {
        self.queue = [IDCQueue object];
        self.staff = [staff mutableCopy];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accesors

- (void)setStaff:(NSMutableArray *)staff {
    if (_staff != staff) {
        _staff = staff;
        
        for (IDCWorker *worker in staff) {
            IDCWeakifyMacro
            [worker addHandler:^{
                IDCStrongifyReturnIfNillMacro;
                [strongSelf workerFree:worker];
            } forState:kIDCWorkerFree object:self];
            
        }
    }
}

#pragma mark -
#pragma mark Private

- (IDCWorker *)vacantWorker {
    @synchronized(self) {
        for (IDCWorker *worker in self.staff) {
            if (worker.state == kIDCWorkerFree) {
                return worker;
            }
        }
    }
    
    return nil;
}

- (void)workWithObject:(id)object {
    [self.queue pushObject:object];
    IDCWorker *worker = [self vacantWorker];
    if (worker && object) {
        [worker performWork:[self.queue popObject]];
    }
}

#pragma mark -
#pragma mark Public

- (void)addObjectToQueue:(id)object {
    [self workWithObject:object];
}

- (BOOL)containsObject:(id)object   {
    return [self.staff containsObject:object];
}

#pragma mark -
#pragma mark VBObserverProtocol

- (void)workerFree:(id)worker {
    [self workWithObject:[self.queue popObject]];
}

@end
