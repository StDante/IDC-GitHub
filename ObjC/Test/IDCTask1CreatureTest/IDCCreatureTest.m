//
//  IDCCreatureTest.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 22.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCCreatureTest.h"

@implementation IDCCreatureTest

#pragma mark -
#pragma mark Class

+ (void)performCreatureTesting {
    [IDCCreatureTest creatureArray];
}

#pragma mark -
#pragma mark Private

+ (void)creatureArray {
    IDCMale *manFirst = [IDCMale creatureWithName:@"Sam" gender:kIDCMale];
    IDCMale *manSecond = [IDCMale creatureWithName:@"Max" gender:kIDCMale];
    IDCFemale *womanFirst = [IDCFemale creatureWithName:@"Eva" gender:kIDCFemale];
    IDCFemale *womanSecond = [IDCFemale creatureWithName:@"Ada" gender:kIDCFemale];
    
    NSArray *creaturs = [NSArray arrayWithObjects:manFirst,
                                                  womanFirst,
                                                  manSecond,
                                                  womanSecond,
                                                  nil];
    for (IDCCreature *creature in creaturs) {
        [creature performGenderSpecificOperation];
    }
    
}


//+ (void)performCreationTest {
//    IDCCreature *manFirst    = [IDCCreature creatureWithName:@"Sam" gender:kIDCMale];
//    IDCCreature *manSecond   = [IDCCreature creatureWithName:@"Bam" gender:kIDCMale];
//    IDCCreature *womanFirst  = [IDCCreature creatureWithName:@"Ada" gender:kIDCFemale];
//    IDCCreature *womanSecond = [IDCCreature creatureWithName:@"Eva" gender:kIDCFemale];
//    
//    NSLog(@"Creation test complite");
//}
//
//+ (void)performStartFightOrBornChildTest {
//    IDCCreature *manFirst     = [IDCCreature creatureWithName:@"Sam" gender:kIDCMale];
//    IDCCreature *manSecond    = [IDCCreature creatureWithName:@"Bam" gender:kIDCMale];
//    IDCCreature *womanFirst   = [IDCCreature creatureWithName:@"Ada" gender:kIDCFemale];
//    IDCCreature *womanSecond  = [IDCCreature creatureWithName:@"Eva" gender:kIDCFemale];
//    NSArray *creatureArray    = [NSArray arrayWithObjects:manFirst,
//                                 womanFirst,
//                                 manSecond,
//                                 womanSecond,
//                                 nil];
//    
//    NSEnumerator *enumerator   = [creatureArray objectEnumerator];
//    IDCCreature *creature = [creatureArray objectAtIndex:0];
//    
//    while (creature = [enumerator nextObject]) {
//        [creature sayHi];
//        
//        if (creature.gender == kIDCMale) {
//            [creature startFighting];
//        } else {
//            NSString *name     = [NSString stringWithFormat:@"Child of %@", creature.name];
//            IDCGender gender   = (arc4random_uniform(2) + 1);
//            IDCCreature *child = [creature birthChildWithName:name
//                                                            gender:gender];
//            NSLog(@"I had a baby. It's name is %@ and gender is %u", child.name, child.gender);
//        }
//    }
//    
//    NSLog(@"StartFight, BirthChild methods test complite");
//}
//
//+ (void)performAddRemoveChildAllSayHiTest {
//    IDCCreature *parent       = [IDCCreature creatureWithName:@"Big Brother" gender:kIDCMale];
//    IDCCreature *childFirst   = [IDCCreature creatureWithName:@"Nuf-Nuf" gender:kIDCMale];
//    IDCCreature *childSecond  = [IDCCreature creatureWithName:@"Naf-Naf" gender:kIDCFemale];
//    IDCCreature *childThird   = [IDCCreature creatureWithName:@"Nif-Nif" gender:kIDCFemale];
//    IDCCreature *grandChild   = [IDCCreature creatureWithName:@"Wolf" gender:kIDCFemale];
//    
//    [parent addChild:childFirst];
//    [parent addChild:childSecond];
//    [parent addChild:childThird];
//    [childFirst addChild:grandChild];
//    
//    NSLog(@"Parent %@ has 3 children. Their names are: %@", parent.name,
//          [parent children]);
//    [parent allSayHi];
//    [parent removeChild:childSecond];
//    
//    NSLog(@"One of his childrens die. Now he has 2 children: %@", [parent children]);
//    
//    NSLog(@"Add and Remove Child, AllSayHi methods test complite");
//}

@end

