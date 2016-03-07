//
//  IDCCreature.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 22.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCCreature.h"

@interface IDCCreature ()

@property (nonatomic, retain)            NSMutableArray *mutableChildren;
@property (nonatomic, assign, readwrite) IDCGender      gender;

@end

@implementation IDCCreature

@class IDCMale;
@class IDCFemale;

#pragma mark -
#pragma mark Class

+ (instancetype)creatureWithName:(NSString *)name gender:(IDCGender)gender {
    Class classOfCreature = [IDCCreature classFromGender:gender];
    return [[[classOfCreature alloc] initWithName:name] autorelease];
}

+ (Class)classFromGender:(IDCGender)gender {
    if (gender == kIDCMale) {
        return [IDCMale class];
    }
    
    return [IDCFemale class];
}

#pragma mark -
#pragma mark Initialization and Deallocation

- (void)dealloc {
    self.name            = nil;
    self.mutableChildren = nil;
    
    [super dealloc];
}

- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    self.name = name;
    self.mutableChildren = [NSMutableArray array];
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSArray *)children {
    return [NSArray arrayWithArray:self.mutableChildren];
}

#pragma mark -
#pragma mark Public

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
    [self sayHi];
    for (self in self.mutableChildren) {
        [self allSayHi];
    }
}

- (void)performGenderSpecificOperation {
    
}

#pragma mark -
#pragma mark Private

@end

