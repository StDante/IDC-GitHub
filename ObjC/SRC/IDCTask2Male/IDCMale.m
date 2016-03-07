//
//  IDCMale.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 22.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCMale.h"

@implementation IDCMale

- (void)performGenderSpecificOperation {
    [self startFighting];
}

- (void)startFighting {
    NSLog(@"I'm going to war, shall come back to dinner!");
}

@end
