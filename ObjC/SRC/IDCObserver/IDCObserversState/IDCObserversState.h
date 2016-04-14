//
//  IDCObserversState.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 13.04.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDCObserver.h"
#import "IDCObserversArray.h"

@interface IDCObserversState : NSObject
@property (nonatomic, assign) NSUInteger        state;
@property (nonatomic, retain) IDCObserversArray *observerArray;

@end
