//
//  NSObject+IDCTask1Creature.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 18.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "NSObject+IDCTask1Creature.h"

@interface IDCCreature ()

@property (nonatomic, retain)            NSMutableArray *mutableChildren;
@property (nonatomic, assign, readwrite) IDCGender      gender;

@end

@implementation IDCCreature

#pragma mark -
#pragma mark Class

+ (instancetype)creatureWithName:(NSString *)name gender:(IDCGender)gender {
    IDCCreature *creature = [[[self alloc] init] autorelease];
    
    if (creature) {
        creature.name            = name;
        creature.gender          = gender;
        creature.mutableChildren = [NSMutableArray array];
    }
    
    return creature;
}

#pragma mark -
#pragma mark Initialization and Deallocation

- (void)dealloc {
    self.name            = nil;
    self.mutableChildren = nil;
    
    [super dealloc];
}

- (instancetype)initWithName:(NSString *)name gender:(IDCGender)gender {
    self = [[[IDCCreature  alloc] init] autorelease];
    
    if (self) {
        self.name            = name;
        self.gender          = gender;
        self.mutableChildren = [NSMutableArray array];
    }

    return self;
}

#pragma mark -
#pragma mark Accessor

- (NSArray *)getChildren {
    return [NSArray arrayWithArray:self.mutableChildren];
}

#pragma mark -
#pragma mark Public

- (instancetype)birthChildwithName:(NSString *)name gender:(IDCGender)gender {
    IDCCreature *child = [self initWithName:name gender:gender];
        
    return child;
}

- (void)startFighting {
    NSLog(@"I'm going to war, shall come back to dinner!");
}

- (void)addChild:(IDCCreature *)child {
    [self.mutableChildren addObject:child];
}

- (void)removeChild:(IDCCreature *)child {
    [self.mutableChildren removeObject:child];
}

- (void)sayHi {
    NSString *name = self.name;
    NSLog(@"Hi! My name is %@", name);
}

- (void)allSayHi {
    IDCCreature *creature = self;
    [creature sayHi];
    for (creature in creature.mutableChildren) {
        [creature.mutableChildren allSayHi];
    }
}


#pragma mark -
#pragma mark Private

@end
