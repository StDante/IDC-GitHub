//
//  IDCAlphabet.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 07.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCAlphabet.h"
#import "IDCRangeAlphabet.h"
#import "IDCStringAlphabet.h"
#import "IDCClusterAlphabet.h"

@implementation IDCAlphabet

@dynamic alphabetString;
@dynamic count;

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

#pragma mark -
#pragma mark FastEnumeration

- (NSString *)objectAtIndexedSubscript:(NSUInteger)index {
    return [NSString stringWithFormat:@"%c", [self.alphabetString characterAtIndex:index]];
}

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id [])buffer
                                    count:(NSUInteger)lenght
{
    state->mutationsPtr = (unsigned long *)self;
    NSUInteger stateCount = state->state;
    NSUInteger resultCount = MIN(self.count - stateCount, lenght);
    NSUInteger finalCount = stateCount + resultCount;
    
    for (NSUInteger index = stateCount; index < finalCount; index++) {
        buffer[index - stateCount] = self[index];
    }
    
    state->state = finalCount;
    state->itemsPtr = buffer;
    
    return resultCount;
}


@end
