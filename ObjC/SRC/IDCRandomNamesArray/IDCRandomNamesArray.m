//
//  IDCRandomNamePool.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 28.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCRandomNamesArray.h"

@implementation IDCRandomNamesArray

#pragma mark -
#pragma mark Class

+ (instancetype)randomNamesArray {
    return [[[self alloc] initWithNamesArray] autorelease];
}

#pragma mark -
#pragma mark Initialization and Deallocation

- (void)dealloc {
    self.nameArray = nil;
    
    [super dealloc];
}

- (instancetype)initWithNamesArray {
    self = [super init];
    if (self) {
        self.nameArray = [[@[@"Vern",
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

- (NSString *)nameFromArray {
    NSUInteger index = arc4random_uniform(20);
    
    return [[[self.nameArray objectAtIndex:index] copy] autorelease];
}

@end
