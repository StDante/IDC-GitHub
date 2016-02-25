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

@implementation NSString (IDCRandomString)

#pragma mark -
#pragma mark Class Methods

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

+ (instancetype)alphabetString:(NSString *)alphabet{
    uint32_t length = arc4random_uniform(kIDCLength);
    
    return [self alphabetString:alphabet withLength:length];
}

+ (instancetype)alphabetString:(NSString *)alphabet withLength:(NSUInteger)length {
    NSString * string = [NSString string];
    
    for (uint32_t index = 0; index <= length; index++) {
        uint32_t charIndex = arc4random_uniform((uint32_t)alphabet.length - 1);
        unichar symbol = [alphabet characterAtIndex:charIndex];
        string = [string stringByAppendingFormat:@"%C", symbol];
    }
    
    return string;
}

+ (instancetype)alphabetString:(NSString *)alphabet1 withAlphabetString:(NSString *)alphabet2 {
    return [[self alphabetString:alphabet1] stringByAppendingString:([self alphabetString:alphabet2])];
}

+ (instancetype)alphabetString:(NSString *)alphabet1 withCombainAlphabet:(NSString *)alphabet2 {
    NSString * string = [NSString string];
    uint32_t length = arc4random_uniform(kIDCLength);
    
    for (uint32_t index = 0; index <= length; index++) {
        unichar firstSymbol = [alphabet1 charFromAlphabet:alphabet1];
        unichar secondSymbol = [alphabet2 charFromAlphabet:alphabet2];
        
        string = [string stringByAppendingFormat:@"%C%C", firstSymbol, secondSymbol];
    }
    
    return string;
}

#pragma mark -
#pragma mark Private Implementation

- (unichar)charFromAlphabet:(NSString *)alphabet {
    uint32_t charIndex = arc4random_uniform((uint32_t)alphabet.length - 1);
    
    return [alphabet characterAtIndex:charIndex];
}

@end
