//
//  NSString+IDCRandomString.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 25.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "NSString+IDCRandomString.h"

static const unichar kIDCCharNumber    = 97;
static const NSUInteger kIDCCharRange  = 25;
static const NSUInteger kIDCLength     = 30;

@interface NSString (IDCPrivateRandomString)

+ (NSString *)stringWithRange:(NSRange)range;
+ (NSString *)stringWithSymbolsFromRange:(unichar)firstChar lastChar:(unichar)lastChar;
- (unichar)charFromAlphabet:(NSString *)alphabet;

@end

@implementation NSString (IDCRandomString)

#pragma mark -
#pragma mark Class Methods

+ (instancetype)capitalLetterAlphabet {
    return [self stringWithSymbolsFromRange:'A' lastChar:'Z'];
}

+ (instancetype)lowercaseLetterAlphabet {
    return [self stringWithSymbolsFromRange:'a' lastChar:'z'];
}

+ (instancetype)numericAlphabet {
    return [self stringWithSymbolsFromRange:'0' lastChar:'9'];
}

+ (instancetype)fullAlphabetWithNumeric {
    NSString *string = [NSString string];
    NSString *capitalAphabet = [NSString capitalLetterAlphabet];
    NSString *lowercaseAphabet = [NSString lowercaseLetterAlphabet];
    NSString *numericAlphabet = [NSString numericAlphabet];
    
    for (NSUInteger index = 0; index < capitalAphabet.length; index++) {
        
        unichar capitalCharIndex = [capitalAphabet characterAtIndex:index];
        string = [string stringByAppendingString:[NSString stringWithFormat:@"%c", capitalCharIndex]];
        
        unichar lowercaseCharIndex = [lowercaseAphabet characterAtIndex:index];
        string = [string stringByAppendingString:[NSString stringWithFormat:@"%c ", lowercaseCharIndex]];
    
    }
    
    for (NSUInteger index = 0; index < numericAlphabet.length; index++) {
        unichar numericCharIndex = [numericAlphabet characterAtIndex:index];
        string = [string stringByAppendingString:[NSString stringWithFormat:@"%c", numericCharIndex]];
    }
    
    return string;
}

+ (instancetype)randomString {
    uint32_t length = arc4random_uniform(kIDCLength);
    
    return [self randomStringWithLength:length];
}

+ (instancetype)randomStringWithLength:(NSUInteger)length {
    NSString * string = [NSString string];
    
    for (uint32_t index = 0; index <= length; index++) {
        unichar symbol = arc4random_uniform(kIDCCharRange) + kIDCCharNumber;
        string = [string stringByAppendingFormat:@"%C", symbol];
    }
    
    return string;
}

+ (instancetype)alphabetString:(NSString *)alphabet {
    uint32_t length = arc4random_uniform(kIDCLength);
    
    return [self alphabetString:alphabet withLength:length];
}

+ (instancetype)alphabetString:(NSString *)alphabet withLength:(NSUInteger)length {
    NSString * string = [NSString string];
    
    for (uint32_t index = 0; index <= length; index++) {
        uint32_t charIndex = arc4random_uniform((uint32_t)alphabet.length - 1);
        unichar symbol = [alphabet characterAtIndex:charIndex];
        string = [string stringByAppendingFormat:@"%c", symbol];
    }
    
    return string;
}

+ (instancetype)alphabetString:(NSString *)alphabet1 withAlphabetString:(NSString *)alphabet2 {
    return [[self alphabetString:alphabet1] stringByAppendingString:([self alphabetString:alphabet2])];
}

+ (instancetype)alphabetString:(NSString *)alphabet1 combainAlphabet:(NSString *)alphabet2 {
    NSString * string = [NSString string];
    uint32_t length = arc4random_uniform(kIDCLength);
    
    for (uint32_t index = 0; index <= length; index++) {
        unichar firstSymbol = [alphabet1 charFromAlphabet:alphabet1];
        unichar secondSymbol = [alphabet2 charFromAlphabet:alphabet2];
        
        string = [string stringByAppendingFormat:@"%c%c", firstSymbol, secondSymbol];
    }
    
    return string;
}

#pragma mark -
#pragma mark Private Implementation

- (unichar)charFromAlphabet:(NSString *)alphabet {
    uint32_t charIndex = arc4random_uniform((uint32_t)alphabet.length - 1);
    
    return [alphabet characterAtIndex:charIndex];
}

+ (NSString *)stringWithSymbolsFromRange:(unichar)firstChar lastChar:(unichar)lastChar {
    NSRange range = NSMakeRange(firstChar, lastChar - firstChar);
    
    return [NSString stringWithRange:range];
}

+ (NSString *)stringWithRange:(NSRange)range {
    NSString *string = [NSString string];
    for (NSUInteger index = range.location; index <= range.location + range.length; index++) {
        string = [string stringByAppendingString:[NSString stringWithFormat:@"%c", (unichar)index]];
    }
    
    return string;
}

@end
