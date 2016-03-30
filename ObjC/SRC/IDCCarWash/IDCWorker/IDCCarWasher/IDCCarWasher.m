//
//  IDCCarWasher.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 28.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCCarWasher.h"

@implementation IDCCarWasher

#pragma mark
#pragma mark Accessors

- (void)setState:(NSUInteger)state {
    if (self.state != state) {
        self.state = state;
        
        NSNumber *key = [NSNumber numberWithUnsignedInteger:state];
        void (^carWasherHandler)(void) = [self.handlersDictionary objectForKey:key];
        if (carWasherHandler) {
            carWasherHandler();
        } else {
            [self notifyObservers];
        }
    }
}

#pragma mark -
#pragma mark Private

- (void)performWork:(IDCCar *)car {
    if (car.isDirty) {
        [super performWork:car];
    }
}

- (void)completeWorkWithObject:(IDCCar *)car {
    car.isDirty = FALSE;
}

#pragma mark
#pragma mark Handlers Method

- (void)addHandler:(IDCCarWasherHandler)carWasherHandler forState:(NSUInteger)state {
    [self removeHandlerForState:state];
    
    NSNumber *key = [NSNumber numberWithUnsignedInteger:state];
    [self.handlersDictionary setObject:[[carWasherHandler copy] autorelease] forKey:key];
}

- (void)removeHandlerForState:(NSUInteger)state {
    NSNumber *key = [NSNumber numberWithUnsignedInteger:state];
    
    [self.handlersDictionary removeObjectForKey:key];
}

@end
