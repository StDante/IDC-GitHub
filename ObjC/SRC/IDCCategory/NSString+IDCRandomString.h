//
//  NSString+IDCRandomString.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 25.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>

//alphabets for randomString
static const NSString *kIDCNumbers         = @"1234567890";
static const NSString *kIDCLovercaseVowels = @"aeiouy";
static const NSString *kIDCCapitalVowels   = @"AEIOY";

@interface NSString (IDCRandomString)

+ (instancetype)randomString;
+ (instancetype)randomStringWithLength:(NSUInteger)length;
+ (instancetype)alphabetString:(NSString *)alphabet;
+ (instancetype)alphabetString:(NSString *)alphabet withLength:(NSUInteger) length;
+ (instancetype)alphabetString:(NSString *)alphabet1 withAlphabetString:(NSString *)alphabet2;
+ (instancetype)alphabetString:(NSString *)alphabet1 withCombainAlphabet:(NSString *)alphabet2;

@end
