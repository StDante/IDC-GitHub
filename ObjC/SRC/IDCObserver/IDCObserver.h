//
//  IDCObserver.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 28.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDCObserversState.h"

typedef void (^IDCCompletionHandler)(id object);

@interface IDCObserver : NSObject
@property (nonatomic, readonly) NSArray    *observers;
@property (nonatomic, assign)   NSUInteger state;
@property (nonatomic, strong)   id         object;

- (instancetype)initWithState:(NSUInteger)state;

- (void)addObserver:(id)observer;
- (void)removeObserver:(id)observer;
- (void)setState:(NSUInteger)state withObject:(id)object;

- (SEL)selectorForState:(NSUInteger)state;
- (void)notifyObserversWithSelector:(SEL)selector;
- (void)notifyObservers;
- (BOOL)observedObject:(id)object;


- (void)addHandler:(IDCCompletionHandler)workerHandler forState:(NSUInteger)state object:(id)object;
- (void)removeHandlersForState:(NSUInteger)state object:(id)object;
- (void)removeHandlersForObject:(id)object;

@end

