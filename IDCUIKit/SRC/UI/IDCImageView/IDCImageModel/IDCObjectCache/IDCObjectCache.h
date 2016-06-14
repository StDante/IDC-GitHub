//
//  IDCObjectCache.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 12.06.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSFileManager+IDCNSFilemManagerCategory.h"
#import <UIKit/UIKit.h>

@interface IDCObjectCache : NSObject <NSCoding>

+ (instancetype)sharedObject;

- (void)setObject:(id)object forKey:(id)key;
- (void)removeObjectForKey:(id)key;

- (BOOL)isCachedWithKey:(id)key;
- (id)objectForKey:(id)key;
- (id)keyForObject:(id)object;

@end
