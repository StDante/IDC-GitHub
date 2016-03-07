//
//  NSObject+IDCAlphabet.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 07.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (IDCAlphabet)

+ (instancetype)alphabetWithRange:(NSRange)range;
+ (instancetype)alphabetWithCharRange:(unichar)firstValue lastValue:(unichar)lastValue;
+ (instancetype)alphabetWithString:(NSString *)string;
+ (instancetype)alphabetWithAlphabets:(NSArray *)alphabets;

@end
