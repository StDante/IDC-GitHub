//
//  IDCClusterAlphabet.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 07.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCClusterAlphabet.h"

@interface IDCClusterAlphabet ()
@property (nonatomic, retain) NSArray *alphabets;

@end

@implementation IDCClusterAlphabet

#pragma mark -
#pragma mark Initialization and Deallocation

- (void)dealloc {
    self.alphabets = nil;
    
    [super dealloc];
}

- (instancetype)initWithAlphabets:(NSArray *)alphabets {
    self = [super init];
    if (self) {
        self.alphabets = alphabets;
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSString *)alphabetString {
        NSMutableString *mutableString = [NSMutableString string];
        
        for (IDCAlphabet *alphabet in self.alphabets) {
            [mutableString appendString:alphabet.alphabetString];
        }
        
        return [[mutableString copy] autorelease];
}

@end
