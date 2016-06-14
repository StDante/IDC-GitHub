//
//  UINib+IDCUINib.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 25.05.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "UINib+IDCUINib.h"

@implementation UINib (IDCUINib)

+ (id)objectFromNibOfClass:(Class)theClass {
    UINib *nib = [UINib nibWithNibName:NSStringFromClass([theClass class]) bundle:[NSBundle mainBundle]];
    NSArray *objects = [nib instantiateWithOwner:[theClass class] options:nil];
    for (id object in objects) {
        if ([object isMemberOfClass:theClass]) {
            return object;
        }
    }
    
    return nil;
}

@end
