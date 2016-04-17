//
//  IDCObserversState.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 13.04.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCObserversState.h"

@interface IDCObserversState()
@property (nonatomic, assign) NSUInteger        state;
@property (nonatomic, retain) IDCObserversArray *observersArray;

@end

@implementation IDCObserversState

#pragma mark -
#pragma mark Class

+ (instancetype)observerStateObjectWithState:(NSUInteger)state {
    return [[[IDCObserversState alloc] initWithState:state] autorelease];;
}


#pragma mark -
#pragma mark Intialization and Deallocation

- (void)dealloc {
    [self removeAllHandlers];
    self.observersArray = nil;
    
    [super dealloc];
}

- (instancetype)init {
    return [self initWithState:0];
}

- (instancetype)initWithState:(NSUInteger)state {
    self = [super init];
    if (self) {
        self.state = state;
        self.observersArray = [IDCObserversArray object];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSArray *)handlers {
    [self.observersArray removeHandlersForObject:nil];
    
    NSMutableArray *handlers = [NSMutableArray array];
    for (IDCObserversObject *object in self.observersArray.observerObjects) {
        [handlers addObject:object.handler];
    }
    
    return [[handlers copy] autorelease];
}

#pragma mark -
#pragma mark Public

- (void)addHandler:(IDCCompletionHandler)handler object:(id)object {
    IDCObserversArray *observersArray = [IDCObserversArray object];
    [observersArray addHandler:handler forObject:object];
    self.observersArray = observersArray;
}

- (void)removeHandlersForObject:(id)object {
    [self.observersArray removeHandlersForObject:object];
    
}

- (void)removeAllHandlers {
    [self.observersArray removeAllHandlers];
}

@end
