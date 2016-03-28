//
//  IDCRandomNamePool.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 28.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCRandomNamePool.h"

@implementation IDCRandomNamePool

#pragma mark -
#pragma mark Class

+ (instancetype)namePool {
    return [[[self alloc] initWithNamePool] autorelease];
}

#pragma mark -
#pragma mark Initialization and Deallocation

- (void)dealloc {
    self.namePool = nil;
    
    [super dealloc];
}

- (instancetype)initWithNamePool {
    self = [super init];
    if (self) {
        self.namePool = [[@[@"Vern",
                           @"Erich",
                           @"Patrick",
                           @"Benjamin",
                           @"Ned",
                           @"Willis",
                           @"Alan",
                           @"Basil",
                           @"Lesley",
                           @"Fernando",
                           @"Hollis",
                           @"Hyman",
                           @"Antoine",
                           @"Clay",
                           @"Karl",
                           @"Pablo",
                           @"Vito",
                           @"Keneth",
                           @"Salvatore",
                           @"Cyril"] copy] autorelease];
    }
    
    return self;
}

#pragma mark - 
#pragma mark Public

- (NSString *)nameFromPool {
    NSUInteger index = arc4random_uniform(20);
    
    return [[[self.namePool objectAtIndex:index] copy] autorelease];
}

@end
