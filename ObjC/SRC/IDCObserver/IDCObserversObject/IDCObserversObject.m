//
//  IDCObserversObject.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 13.04.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCObserversObject.h"

@implementation IDCObserversObject

#pragma mark -
#pragma mark Class

+ (instancetype)observerObjectWithObject:(id)object handler:(IDCCompletionHandler)handler {
    return [[IDCObserversObject alloc] initWithObject:object handler:handler];
}

#pragma mark -
#pragma mark Intialization and Deallocation

- (instancetype)initWithObject:(id)object handler:(IDCCompletionHandler)handler {
    self = [super init];
    if (self) {
        self.object = object;
        self.handler = handler;
    }
    
    return self;
}

@end

