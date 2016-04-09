//
//  IDCCarWasher.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 28.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCCarWasher.h"

@implementation IDCCarWasher

#pragma mark -
#pragma mark Private

- (void)performWork:(IDCCar *)car {
    if (car.isDirty) {
        [super performWork:car];
    }
}

- (void)completeWorkWithObject:(IDCCar *)car {
    car.isDirty = 0;
}


@end
