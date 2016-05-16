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

typedef NS_ENUM(NSUInteger, IDCArrayModelState) {
    kIDCChangeObjectState
};

@interface IDCArrayModel : IDCObserver
@property (nonatomic, readonly) NSArray *objects;

+ (instancetype)arrayModelWithObject:(id)object;
+ (instancetype)arrayModelWithArray:(NSArray *)objects;

- (instancetype)initWithObject:(id)object;
- (instancetype)initWithArray:(NSArray *)objects;

- (id)objectAtIndex:(NSUInteger)index;
- (id)objectAtIndexedSubscript:(NSUInteger)index;

- (void)addObject:(id)object;
- (void)removeObject:(id)object;
- (void)removeObjectAtIndex:(NSUInteger)index;
- (void)removeAllObjects;

- (NSUInteger)count;
- (NSUInteger)indexOfObject:(id)object;

- (void)moveCellFromIndex:(NSUInteger)fromIndex toIndex:(NSUInteger)toIndex ;

@end
