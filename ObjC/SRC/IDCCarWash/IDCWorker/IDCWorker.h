//
//  IDCWorker.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 10.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDCObserver.h"
#import "IDCCar.h"
#import "IDCWorkerProtocol.h"
#import "IDCMoneyProtocol.h"
#import "IDCRandomNamesArray.h"
#import "IDCQueue.h"

typedef enum IDCWorkerState : NSUInteger {
    kIDCWorkerUndefinedState,
    kIDCWorkerFree,
    kIDCWorkerBusy,
    kIDCWorkerStandby
} IDCWorkerState;

@interface IDCWorker : IDCObserver <IDCMoneyProtocol, IDCWorkerProtocol>
@property (nonatomic, retain) IDCQueue *workersQueue;
@property (nonatomic, assign) NSString   *name;

+ (instancetype)workerWithRandomName;
+ (NSArray *)objectsWithCount:(NSUInteger)count observer:(id)observer;
- (instancetype)init;

- (void)performWork:(id)object;
- (void)sayNameProfession;

@end
