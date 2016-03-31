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
        self.isDirty = isDirty;
    }
    
    return self;
}

@end
