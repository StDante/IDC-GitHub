//
//  IDCObserver.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 28.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCObserver.h"

@interface IDCObserver ()
@property (nonatomic, assign) NSHashTable         *mutableObservers;
@property (nonatomic, retain) NSMutableArray *observerStatesObjects;


- (IDCObserversState *)objectForState:(NSUInteger)state;
- (void)performHandler;

@end

@implementation IDCObserver

@dynamic observers;

#pragma mark -
#pragma mark Initializations and Deallocatins

- (void)dealloc {
    self.mutableObservers = nil;
    self.observerStatesObjects = nil;
    self.object = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableObservers = [NSHashTable weakObjectsHashTable];
        self.observerStatesObjects = [NSMutableArray array];
        self.object = nil;
    }
    
    return self;
}

- (instancetype)initWithState:(NSUInteger)state {
    self = [self init];
    if (self) {
        self.state = state;
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSArray *)observers {
    return [self.mutableObservers allObjects];
}

- (void)setState:(NSUInteger)state {
    @synchronized (self) {
        if (_state != state) {
            _state = state;
            
//          [self notifyObservers];
            [self performHandler];
        }
    }
}

- (void)setObject:(id)object {
    if (_object != object) {
        _object = object;
    }
}

- (void)setState:(NSUInteger)state withObject:(id)object {
    @synchronized(self) {
        if (_object != object) {
            _object = object;
        }

        if (_state != state) {
            _state = state;
        }
        
        [self performHandler];
    }
}
  

#pragma mark -
#pragma mark Public

- (void)addObserver:(id)observer {
    [self.mutableObservers addObject:observer];
}

- (void)removeObserver:(id)observer {
    [self.mutableObservers removeObject:observer];
}

- (SEL)selectorForState:(NSUInteger)state {
    return nil;
}

- (void)notifyObserversWithSelector:(SEL)selector {
    for (id observer in self.observers) {
        if ([observer respondsToSelector:selector]) {
            [observer performSelector:selector withObject:self];
        }
    }
}

- (void)notifyObservers {
    SEL selector = [self selectorForState:self.state];
    [self notifyObserversWithSelector:selector];
}

- (BOOL)observedObject:(id)object {
    return [self.mutableObservers containsObject:object];
}

//////////////////////////////////////////////////////////////Handlers

- (void)addHandler:(IDCCompletionHandler)workerHandler forState:(NSUInteger)state object:(id)object {
    if (object) {
        IDCObserversState *stateObject = [self objectForState:state];
        [stateObject addHandler:workerHandler object:object];
    }
}

- (void)removeHandlersForState:(NSUInteger)state object:(id)object {
    for (IDCObserversState *stateObject in self.observerStatesObjects) {
        if (stateObject.state == state) {
            [self.observerStatesObjects removeObject:stateObject];
        }
    }
}

- (void)removeHandlersForObject:(id)object {
    if (object) {
        for (IDCObserversState *stateObject in self.observerStatesObjects) {
            [stateObject removeHandlersForObject:object];
        }
    }
}

#pragma mark -
#pragma mark Private

- (IDCObserversState *)objectForState:(NSUInteger)state {
    for (IDCObserversState *stateObject in self.observerStatesObjects) {
        if (stateObject.state == state) {
            return stateObject;
        }
    }
    
    IDCObserversState *newStateObject = [IDCObserversState observerStateObjectWithState:state];
    [self.observerStatesObjects addObject:newStateObject];
    
    return newStateObject;
}


- (void)performHandler {
    for (IDCObserversState *stateObject in self.observerStatesObjects) {
        if (stateObject.state == self.state) {
            for (IDCCompletionHandler handler in stateObject.handlers) {
                handler(self.object);
            }
        }
    }
}

@end
