//
//  IDCFemale.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 22.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCFemale.h"

@implementation IDCFemale

- (IDCCreature *)performGenderSpecificOperation {
    NSString *name = [NSString stringWithFormat:@"Child of %@", self.name];
    IDCGender gender = (arc4random_uniform(2) + 1);
    IDCCreature *child = [self birthChildWithName:name gender:gender];
    NSLog(@"I have a child %@, its name is %@", child, child.name);
    
    return child;
}

- (IDCCreature *)birthChildWithName:(NSString *)name gender:(IDCGender) gender {
    return [IDCCreature creatureWithName:name gender:gender];
}

@end
