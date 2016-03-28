//
//  IDCCar.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 10.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCCar.h"

@implementation IDCCar

#pragma mark -
#pragma mark Class

+ (instancetype)carWithModel:(NSString *)model money:(NSUInteger)money dirt:(BOOL)isDirty {
    return [[[self alloc] initWithModel:model money:money dirt:isDirty] autorelease];
}

#pragma mark -
#pragma mark Initialization and Deallocation

- (void)dealloc {
    self.model = nil;
    
    [super dealloc];
}

- (instancetype)initWithModel:(NSString *)model money:(NSUInteger)money dirt:(BOOL)isDirty {
    self = [super init];
    
    if (self) {
        self.model = model;
        self.money = money;
        self.isDirty = TRUE;
    }
    
    return self;
}

#pragma mark -
#pragma mark Private

- (void)carWashed {
    self.money = self.money - kIDCWashCost;
    self.isDirty = FALSE;
}

- (BOOL)isWashing {
    NSUInteger balance = self.money - kIDCWashCost;
    
    return balance || !self.isDirty;
}

@end
