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
        NSArray *carsArray = [NSMutableArray objectsWithCount:20 class:[IDCCar class]];
        for (IDCCar *car in carsArray) {
          car.isDirty = TRUE;
            car.money = kIDCWashCost;
        }
        
        IDCEnterprise *carWash = [IDCEnterprise enterpriseWithTitle:@"CarWash"];
        
        for (NSUInteger i = 0; i < carsArray.count; i++) {
            [carWash washCar:carsArray[i]];
        }
        
        NSRunLoop *loop = [NSRunLoop mainRunLoop];
        [loop run];
    }
    
    return 0;
}
