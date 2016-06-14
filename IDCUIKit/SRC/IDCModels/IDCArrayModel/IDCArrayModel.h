//
//  IDCArrayModel.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 15.05.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCObserver.h"
#import "IDCStateModel.h"
#import "IDCStringModel.h"
#import "IDCStateUniversalModel.h"

typedef NS_ENUM(NSUInteger, IDCArrayModelState) {
    kIDCChangeObjectState
};

@interface IDCArrayModel : IDCStateUniversalModel <NSFastEnumeration, NSCoding>
@property (nonatomic, readonly) NSArray *objects;

+ (instancetype)arrayModelWithObject:(id)object;
+ (instancetype)arrayModelWithArray:(NSArray *)objects;

- (instancetype)initWithObject:(id)object;
- (instancetype)initWithArray:(NSArray *)objects;

- (id)objectAtIndex:(NSUInteger)index;
- (id)objectAtIndexedSubscript:(NSUInteger)index;

- (void)addObject:(id)object;
- (void)addObjects:(NSArray *)array;
- (void)replaceObjectsWithArray:(NSArray *)array;
- (void)insertObject:(id)object atIndex:(NSUInteger)index;
- (void)removeObject:(id)object;
- (void)removeObjectAtIndex:(NSUInteger)index;
- (void)removeAllObjects;

- (NSUInteger)count;
- (NSUInteger)indexOfObject:(id)object;

- (void)moveCellFromIndex:(NSUInteger)fromIndex toIndex:(NSUInteger)toIndex ;

@end
