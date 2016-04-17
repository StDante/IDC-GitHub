//
//  IDCObserversArray.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 13.04.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDCObserversObject.h"

@interface IDCObserversArray : NSObject
@property (nonatomic, readonly) NSArray *observerObjects;

- (void)addHandler:(IDCCompletionHandler)handler forObject:(id)object;
- (void)removeHandlersForObject:(id)object;
- (void)removeAllHandlers;

@end
