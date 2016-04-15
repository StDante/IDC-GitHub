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
        NSArray *carsArray = [IDCCar objectsWithCount:2000];
        for (IDCCar *car in carsArray) {
          car.isDirty = TRUE;
            car.money = kIDCWashCost;
        }
        
        IDCEnterprise *carWash = [IDCEnterprise object];
        
        for (NSUInteger i = 0; i < carsArray.count; i++) {
            [carWash washCar:carsArray[i]];
        }
        
        NSRunLoop *loop = [NSRunLoop mainRunLoop];
        [loop run];
    }
    
    return 0;
}
