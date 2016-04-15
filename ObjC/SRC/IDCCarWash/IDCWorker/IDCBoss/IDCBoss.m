//
//  IDCBoss.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 28.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCBoss.h"

@implementation IDCBoss

#pragma mark -
#pragma mark Private

- (void)completeWork {
    NSLog(@"PROFIT is %lu", self.money);
    self.state = kIDCWorkerFree;
}

@end
