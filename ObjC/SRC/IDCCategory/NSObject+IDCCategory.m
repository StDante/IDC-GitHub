//
//  NSObject+IDCCategory.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 25.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "NSObject+IDCCategory.h"

@implementation NSObject (IDCCategory)

+ (instancetype)object {
    return [[[[self class] alloc] init] autorelease];
}

- (NSArray *)objectsWithCount:(NSUInteger)count class:(Class)objectClass {
    NSMutableArray *objects = [NSMutableArray object];
    for (NSUInteger index = 0; index < count; index++) {
        [objects addObject:[objectClass object]];
    }
    
    return objects;
}

@end
