//
//  main.m
//  ObjC
//
//  Created by Alexandr Altukhov on 18.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCCreatureTest.h"
#import "NSString+IDCRandomString.h"
#import "IDCEnterprise.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        IDCEnterprise *carWash = [IDCEnterprise enterpriseWithTitle:@"CarWash"];
    }
    
    return 0;
}
