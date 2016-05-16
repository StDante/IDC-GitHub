//
//  IDCObserversObject.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 13.04.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^IDCCompletionHandler)(id object);

@interface IDCObserversObject : NSObject
@property (nonatomic, weak) id                   object;
@property (nonatomic, copy) IDCCompletionHandler handler;

+ (instancetype)observerObjectWithObject:(id)object handler:(IDCCompletionHandler)handler;
- (instancetype)initWithObject:(id)object handler:(IDCCompletionHandler)handler;

@end
