//
//  NSObject+IDCTask1Creature.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 18.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IDCCreature : NSObject;

typedef enum {
    kIDCUnknownGender,
    kIDCMale,
    kIDCFemale
} IDCGender;

@property (nonatomic, copy, readonly)    NSArray   *children;
@property (nonatomic, copy)              NSString  *name;
@property (nonatomic, assign, readonly)  IDCGender gender;
@property (nonatomic, assign)            NSNumber  *age;
@property (nonatomic, assign)            NSNumber  *weight;

+ (instancetype)creatureWithName:(NSString *)name gender:(IDCGender)gender;

- (instancetype)initWithName:(NSString *)name gender:(IDCGender)gender;

- (instancetype)birthChildwithName:(NSString *)name gender:(IDCGender)gender;
- (NSArray *)getChildren;
- (void)addChild:(IDCCreature *)child;
- (void)removeChild:(IDCCreature *)child;
- (void)startFighting;
- (void)sayHi;
- (void)allSayHi;

@end
