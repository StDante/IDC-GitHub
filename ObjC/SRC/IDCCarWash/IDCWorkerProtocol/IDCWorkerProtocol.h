//
//  IDCWorkerProtocol.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 28.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol IDCWorkerProtocol <NSObject>

@optional
- (void)workerFree:(id)worker;
- (void)workerBusy:(id)worker;
- (void)workerStandby:(id)worker;

@end
