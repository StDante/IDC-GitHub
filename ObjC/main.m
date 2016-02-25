//
//  main.m
//  ObjC
//
//  Created by Alexandr Altukhov on 18.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCCreatureTest.h"
#import "NSString+IDCRandomString.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSLog(@"%@", [NSString alphabetString:(NSString *)kIDCLovercaseVowels]);
    }
    
    return 0;
}
