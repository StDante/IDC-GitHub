//
//  IDCWorker.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 10.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "IDCObserver.h"
#import "IDCEnterprise.h"
#import "IDCCar.h"
#import "IDCWorkerProtocol.h"
#import "IDCMoneyProtocol.h"
#import "IDCRandomNamePool.h"

@interface IDCWorker : IDCObserver <IDCMoneyProtocol, IDCWorkerProtocol>
@property (nonatomic, assign) NSString   *name;
@property (nonatomic, assign) NSUInteger money;

- (void)performWork:(id)object;

@end
