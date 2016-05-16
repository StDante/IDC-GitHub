//
//  IDCArrayModel.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 15.05.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCArrayModel.h"

@interface IDCArrayModel ()
@property (nonatomic, strong) NSMutableArray *arrayObjects;

- (IDCStateModel *)modelWithState:(IDCObjectState)state index:(NSUInteger)index;

@end

@implementation IDCArrayModel

#pragma mark -
#pragma mark Class Methods

+ (instancetype)arrayModelWithObject:(id)object {
    return [[self alloc] initWithObject:object];
}

+ (instancetype)arrayModelWithArray:(NSArray *)objects {
    return [[self alloc] initWithArray:objects];
}

#pragma mark -
#pragma mark Initialization and Deallocation

- (instancetype)init {
    self = [super init];
    if (self) {
        self.arrayObjects = [NSMutableArray array];
    }
    
    return self;
}

- (instancetype)initWithObject:(id)object {
    self = [self init];
    if (self) {
        [self.arrayObjects addObject:object];
    }
    
    return self;
}

- (instancetype)initWithArray:(NSArray *)objects {
    self = [self init];
    if (self) {
        [self.arrayObjects addObjectsFromArray:objects];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSArray *)objects {
    return [self.arrayObjects copy];
}

#pragma mark -
#pragma mark Private

- (IDCStateModel *)modelWithState:(IDCObjectState)state index:(NSUInteger)index {
    IDCStateModel *stateModel = [IDCStateModel new];
    stateModel.state = state;
    stateModel.index = index;
    
    return stateModel;
}

#pragma mark -
#pragma mark Public

- (NSUInteger)indexOfObject:(id)object {
    return [self.arrayObjects indexOfObject:object];
}

- (NSUInteger)count {
    return self.arrayObjects.count;
}

- (id)objectAtIndex:(NSUInteger)index {
    return self.arrayObjects[index];
}

- (id)objectAtIndexedSubscript:(NSUInteger)index {
    return [self.arrayObjects objectAtIndex:index];
}

- (void)addObject:(id)object {
    [self.arrayObjects addObject:object];
    IDCStateModel *model = [self modelWithState:kIDCObjectAddState index:self.count];
    [self setState:kIDCChangeObjectState withObject:model];
}

- (void)removeObject:(id)object {
    [self.arrayObjects removeObject:object];
    IDCStateModel *model = [self modelWithState:kIDCObjectRemoveState index:[self indexOfObject:object]];
    [self setState:kIDCChangeObjectState withObject:model];
}

- (void)removeObjectAtIndex:(NSUInteger)index {
    [self.arrayObjects removeObjectAtIndex:index];
    IDCStateModel *model = [self modelWithState:kIDCObjectRemoveState index:index];
    [self setState:kIDCChangeObjectState withObject:model];
}

- (void)removeAllObjects {
    NSUInteger count = self.count;
    for (NSUInteger index = 0; index < count; index++) {
        IDCStateModel *model = [self modelWithState:kIDCObjectRemoveState index:index];
        [self setState:kIDCChangeObjectState withObject:model];
    }
    
    [self.arrayObjects removeAllObjects];
}

- (void)moveCellFromIndex:(NSUInteger)fromIndex toIndex:(NSUInteger)toIndex {
    [self.arrayObjects exchangeObjectAtIndex:fromIndex withObjectAtIndex:toIndex];
}


@end
