//
//  NSObject+IDCAlphabet.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 07.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "NSObject+IDCAlphabet.h"


@implementation NSObject (IDCAlphabet)

@dynamic alphabetString;

#pragma mark -
#pragma mark Class Methods

+ (instancetype)alphabetWithRange:(NSRange)range {
    return [[[self alloc] initWithRange:range] autorelease];
}

+ (instancetype)alphabetWithCharRange:(unichar)firstValue lastValue:(unichar)lastValue {
    return [[[self alloc] initWithCharRange:firstValue lastValue:lastValue] autorelease];
}

+ (instancetype)alphabetWithString:(NSString *)string {
    return [[[self alloc] initWithString:string] autorelease];
}

+ (instancetype)alphabetWithAlphabets:(NSArray *)alphabets {
    return [[[self alloc] initWithAlphabets:alphabets] autorelease];
}

#pragma mark -
#pragma mark Initialization and Deallocation

- (instancetype)initWithRange:(NSRange)range {
    [self autorelease];
    
    return [[[IDCRangeAlphabet alloc] initWithRange:range] autorelease];
}

- (instancetype)initWithCharRange:(unichar)firstValue lastValue:(unichar)lastValue {
    [self autorelease];
    
    return [[[IDCRangeAlphabet alloc] initWithRange:NSMakeRange(firstValue, lastValue - firstValue + 1)]
                                                                                            autorelease];
}

- (instancetype)initWithString:(NSString *)string {
    [self autorelease];
    
    return [[[IDCStringAlphabet alloc] initWithString:string] autorelease];
}

- (instancetype)initWithAlphabets:(NSArray *)alphabets {
    [self autorelease];
    
    return [[[IDCClusterAlphabet alloc] initWithAlphabets:alphabets] autorelease];
    
}

#pragma mark -
#pragma mark Alphabets

+ (instancetype)lowercaseAlphabet {
    return [self alphabetWithCharRange:'a' lastValue:'z'];
}

+ (instancetype)uppercaseAlphabet {
    return [self alphabetWithCharRange:'A' lastValue:'Z'];
}

+ (instancetype)numericAlphabet {
    return [self alphabetWithCharRange:'0' lastValue:'9'];
}

@end
