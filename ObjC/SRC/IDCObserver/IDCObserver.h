//
//  IDCObserver.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 28.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^IDCComplitionHandler)(void);

@interface IDCObserver : NSObject
@property (nonatomic, readonly) NSArray     *observers;
@property (nonatomic, assign)   NSUInteger  state;
@property (nonatomic, retain)   NSMutableDictionary *handlersDictionary;

- (instancetype)initWithState:(NSUInteger)state;

- (void)addObserver:(id)observer;
- (void)removeObserver:(id)observer;

- (SEL)selectorForState:(NSUInteger)state;
- (void)notifyObserversWithSelector:(SEL)selector;
- (void)notifyObservers;
- (BOOL)observedObject:(id)object;

- (void)addHandler:(IDCComplitionHandler)workerHandler forState:(NSUInteger)state object:(id)object;
- (void)removeHandlerForState:(NSUInteger)state object:(id)object;
- (void)removeHandlerForObject:(id)object;

@end

