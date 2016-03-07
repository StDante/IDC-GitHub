//
//  IDCStringAlphabet.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 07.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCStringAlphabet.h"

@interface IDCStringAlphabet ()
@property (nonatomic, copy) NSString *string;

@end

@implementation IDCStringAlphabet

#pragma mark -
#pragma mark Initializationd and Deallocation

- (void)dealloc {
    self.string = nil;
    
    [super dealloc];
}

- (instancetype)initWithString:(NSString *)string {
    self = [super init];
    if (self) {
        self.string = string;
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSString *)alphabetString {
    return [[self.string copy] autorelease];
}

- (NSUInteger)count {
    return self.string.length;
}

@end
