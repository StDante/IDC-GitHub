//
//  IDCObserversArray.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 13.04.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCObserversArray.h"

@interface IDCObserversArray()
@property (nonatomic, retain) NSMutableArray *mutableObserverObjects;

@end

@implementation IDCObserversArray

#pragma mark -
#pragma mark Intialization and Deallocation

- (void)dealloc {
    self.mutableObserverObjects = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableObserverObjects = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSArray *)observerObjects {
    return [[self.mutableObserverObjects copy] autorelease];
}

#pragma mark -
#pragma mark Public

- (void)addHandler:(IDCCompletionHandler)handler forObject:(id)object {
    IDCObserversObject *observerObject = [IDCObserversObject observerObjectWithObject:object
                                                                              handler:handler];
    [self.mutableObserverObjects addObject:observerObject];
}

- (void)removeHandlersForObject:(id)object {
    NSArray *observerObjects = self.observerObjects;
    for (IDCObserversObject *observerObject in observerObjects) {
        if (observerObject.object == object) {
            [self.mutableObserverObjects removeObject:observerObject];
        }
    }
}

- (void)removeAllHandlers {
    [self.mutableObserverObjects removeAllObjects];
}


@end
