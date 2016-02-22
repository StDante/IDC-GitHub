//
//  NSObject+IDCTask1CreatureTest.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 19.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "NSObject+IDCTask1CreatureTest.h"

@implementation IDCCreatureTest

#pragma mark -
#pragma mark Class

+ (void)performCreatureTesting {
    [IDCCreatureTest performCreationTest];
    [IDCCreatureTest performStartFightOrBornChildTest];
    [IDCCreatureTest performAddAndRemoveChildTest];
}

#pragma mark -
#pragma mark Private

+ (void)performCreationTest {
    IDCCreature *manFirst    = [IDCCreature creatureWithName:@"Sam" gender:kIDCMale];
    IDCCreature *manSecond   = [IDCCreature creatureWithName:@"Bam" gender:kIDCMale];
    IDCCreature *womanFirst  = [IDCCreature creatureWithName:@"Ada" gender:kIDCFemale];
    IDCCreature *womanSecond = [IDCCreature creatureWithName:@"Eva" gender:kIDCFemale];

    NSLog(@"Creation test complite");
}

+ (void)performStartFightOrBornChildTest {
    IDCCreature *manFirst     = [IDCCreature creatureWithName:@"Sam" gender:kIDCMale];
    IDCCreature *manSecond    = [IDCCreature creatureWithName:@"Bam" gender:kIDCMale];
    IDCCreature *womanFirst   = [IDCCreature creatureWithName:@"Ada" gender:kIDCFemale];
    IDCCreature *womanSecond  = [IDCCreature creatureWithName:@"Eva" gender:kIDCFemale];
    NSArray *creatureArray    = [NSArray arrayWithObjects:manFirst,
                                                        womanFirst,
                                                        manSecond,
                                                        womanSecond,
                                                        nil];
    
    NSEnumerator *enumerator   = [creatureArray objectEnumerator];
    IDCCreature *firstCreature = [creatureArray objectAtIndex:0];

    while (firstCreature = [enumerator nextObject]) {
        [firstCreature sayHi];
        
        if (firstCreature.gender == kIDCMale) {
            [firstCreature startFighting];
        } else {
            NSString *name     = [NSString stringWithFormat:@"Child of %@", firstCreature.name];
            IDCGender gender   = (arc4random_uniform(2) + 1);
            IDCCreature *child = [firstCreature birthChildwithName:name
                                                gender:gender];
            NSLog(@"I had a baby. It's name is %@ and gender is %u", child.name, child.gender);
        }
    }
    
    NSLog(@"StartFight, BirthChild methods test complite");
}

+ (void)performAddAndRemoveChildTest {
    IDCCreature *parent       = [IDCCreature creatureWithName:@"Big Brother" gender:kIDCMale];
    IDCCreature *childFirst   = [IDCCreature creatureWithName:@"Nuf-Nuf" gender:kIDCMale];
    IDCCreature *childSecond  = [IDCCreature creatureWithName:@"Naf-Naf" gender:kIDCFemale];
    IDCCreature *childThird   = [IDCCreature creatureWithName:@"Nif-Nif" gender:kIDCFemale];
    
    [parent addChild:childFirst];
    [parent addChild:childSecond];
    [parent addChild:childThird];
    
    NSLog(@"Parent %@ has 3 children. Their names are: %@", parent.name,
                                                            [parent getChildren]);
    
    [parent removeChild:childSecond];
    
    NSLog(@"One of his childrens die. Now he has 2 children: %@", [parent getChildren]);
}

//+ (void)performSayHiTest {
//    
//}

@end
