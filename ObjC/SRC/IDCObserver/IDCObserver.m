//
//  IDCObserver.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 28.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCObserver.h"

@interface IDCObserver ()
@property (nonatomic, assign) NSHashTable *mutableObservers;

@end

@implementation IDCObserver

@dynamic observers;

#pragma mark -
#pragma mark Initializations and Deallocatins

- (void)dealloc {
    self.mutableObservers = nil;
    self.handlersDictionary = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableObservers = [NSHashTable weakObjectsHashTable];
        self.handlersDictionary = [NSMutableDictionary object];
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

//////////////////////////////////////////////////////////////Handlers


#pragma mark -
#pragma mark Accessors

- (NSArray *)observers {
    return [self.mutableObservers allObjects];
}

- (void)setState:(NSUInteger)state {
    if (_state != state) {
        _state = state;
        
        [self notifyObservers];
    }
}

//////////////////////////////////////////////////////////////Handlers

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

- (void)addHandler:(IDCComplitionHandler)workerHandler ForState:(NSUInteger)state object:(id)object {
    
}

- (void)removeHandlerForState:(NSUInteger)state object:(id)object {
    
}

- (void)removeHandlerForObject:(id)object {
    
}

@end
