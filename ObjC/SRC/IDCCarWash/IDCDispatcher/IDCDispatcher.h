//
//  IDCDispatcher.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 06.04.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDCQueue.h"
#import "IDCWorker.h"

@interface IDCDispatcher : NSObject <IDCWorkerProtocol>

- (instancetype)initWithStaff:(NSArray *)staff;

- (void)addObjectToQueue:(id)object;
- (BOOL)containsObject:(id)object;

@end
