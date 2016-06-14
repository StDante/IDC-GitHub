//
//  IDCArrayModel.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 15.05.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCArrayModel.h"

static NSString * const kIDCArrayCoderKey    = @"array";

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
    @synchronized (self) {
        [self.arrayObjects addObject:object];
        IDCStateModel *model = [self modelWithState:kIDCObjectAddState index:(self.count - 1)];
        [self setState:kIDCChangeObjectState withObject:model];
    }
}

- (void)addObjects:(NSArray *)array {
    @synchronized (self) {
        return [self.arrayObjects addObjectsFromArray:array];
    }
}

- (void)removeObject:(id)object {
    @synchronized (self) {
        [self.arrayObjects removeObject:object];
        IDCStateModel *model = [self modelWithState:kIDCObjectRemoveState index:[self indexOfObject:object]];
        [self setState:kIDCChangeObjectState withObject:model];
    }
}

- (void)removeObjectAtIndex:(NSUInteger)index {
    @synchronized (self) {
        [self.arrayObjects removeObjectAtIndex:index];
        IDCStateModel *model = [self modelWithState:kIDCObjectRemoveState index:index];
        [self setState:kIDCChangeObjectState withObject:model];
    }
}

- (void)removeAllObjects {
    @synchronized (self) {
        NSUInteger count = self.count;
        for (NSUInteger index = 0; index < count; index++) {
            IDCStateModel *model = [self modelWithState:kIDCObjectRemoveState index:index];
            [self setState:kIDCChangeObjectState withObject:model];
        }
    
        [self.arrayObjects removeAllObjects];
    }
}

- (void)replaceObjectsWithArray:(NSArray *)array {
    return [self.arrayObjects setArray:array];
}

- (void)insertObject:(id)object atIndex:(NSUInteger)index {
    NSUInteger insertIndex = index + 1;
    [self.arrayObjects insertObject:object atIndex:insertIndex];
    IDCStateModel *model = [IDCStateModel modelWithState:kIDCObjectAddState index:insertIndex];
    [self setState:kIDCModelChangeState withObject:model];
}

- (void)moveCellFromIndex:(NSUInteger)fromIndex toIndex:(NSUInteger)toIndex {
    [self.arrayObjects exchangeObjectAtIndex:fromIndex withObjectAtIndex:toIndex];
}

#pragma mark -
#pragma mark NSFastEnumeration Protocol

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(__unsafe_unretained id*)buffer
                                    count:(NSUInteger)len
{
    return [self.arrayObjects countByEnumeratingWithState:state objects:buffer count:len];
}

#pragma mark -
#pragma mark NSCoding Protocol

- (instancetype)initWithCoder:(NSCoder *)aDecoder {
    self = [super init];
    if (self) {
        self.arrayObjects = [aDecoder decodeObjectForKey:kIDCArrayCoderKey];
    }
    
    return self;
}

- (void)encodeWithCoder:(NSCoder *)aCoder {
    [aCoder encodeObject:self.arrayObjects forKey:kIDCArrayCoderKey];
}



@end
