//
//  IDCObserversState.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 13.04.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDCObserversArray.h"

@interface IDCObserversState : NSObject
@property (nonatomic, readonly) NSUInteger state;
@property (nonatomic, readonly) NSArray    *handlers;

+ (instancetype)observerStateObjectWithState:(NSUInteger)state;
- (instancetype)initWithState:(NSUInteger)state NS_DESIGNATED_INITIALIZER;

- (void)addHandler:(IDCCompletionHandler)handler object:(id)object;
- (void)removeHandlersForObject:(id)object;
- (void)removeAllHandlers;

@end
