//
//  NSObject+IDCTask1Creature.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 18.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "NSObject+IDCTask1Creature.h"

@interface IDCCreature ()

@property (nonatomic, retain) NSMutableArray<IDCCreature *> *mutableChildren;

@property (nonatomic, assign, readwrite) IDCGender gender;

@end

@implementation IDCCreature

#pragma mark -
#pragma mark Initialization and Deallocation

- (void)dealloc {
    self.name            = nil;
    self.mutableChildren = nil;
    
    [super dealloc];
}

- (instancetype)initWithName:(NSString *)name gender:(IDCGender)gender {
    self        = [[[IDCCreature  alloc] init] autorelease];
    if (self) {
        self.name   = name;
        self.gender = gender;
    }

    return self;
}

#pragma mark -
#pragma mark Accessor

#pragma mark -
#pragma mark Public

- (instancetype)bornChildwithName:(NSString *)name gender:(IDCGender)gender {
    if (self.gender == kIDCFemale) {
        IDCCreature *child = [self initWithName:name gender:gender];
        
        return child;
    }
    
    NSLog(@"Real man doesn't give a birth, real man take lifes");
    [self startFighting];
        
    return nil;
}

- (void)startFighting {
// Idea for method realesation: Man going to war, he can die randomly.
// If he die's  send - release, else - stop fight
}
- (void)stopFighting {
// When Man comeback from war send method sayHi
}

- (void)addChild:(IDCCreature *)child {
    
}
- (void)removeChild:(IDCCreature *)child {
    
}

- (void)sayHi {
    
}


#pragma mark -
#pragma mark Private

@end
