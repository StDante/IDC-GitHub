//
//  IDCQueue.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 06.04.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCQueue.h"

@interface IDCQueue ()
@property (nonatomic, retain) NSMutableArray *queueArray;

@end

@implementation IDCQueue

#pragma mark -
#pragma mark Initialization and Deallocation

- (void)dealloc {
    [self.queueArray removeAllObjects];
    self.queueArray = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.queueArray = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSArray *)queue {
    return [[self.queueArray copy] autorelease];
}

#pragma mark -
#pragma mark Public

- (void)pushObject:(id)object {
    @synchronized (self) {
        if (object) {
            [self.queueArray addObject:object];
        }
    }
}

- (id)popObject {
    @synchronized (self) {
        id object = [self.queueArray firstObject];
        if (object) {
            [self.queueArray removeObject:object];
        }
        
        return object;
    }
}

@end
