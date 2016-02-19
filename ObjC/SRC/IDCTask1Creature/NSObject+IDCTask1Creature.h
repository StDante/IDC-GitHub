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

@property (atomic, retain, readonly)    NSArray<IDCCreature *> *children;
@property (nonatomic, copy)             NSString  *name;
@property (nonatomic, assign, readonly) IDCGender gender;
@property (nonatomic, assign)           NSNumber  *age;
@property (nonatomic, assign)           NSNumber  *weight;

- (instancetype)initWithName:(NSString *)name gender:(IDCGender)gender;

- (void)startFighting;
- (void)stopFighting;

- (instancetype)bornChildwithName:(NSString *)name gender:(IDCGender)gender;

- (void)addChild:(IDCCreature *)child;
- (void)removeChild:(IDCCreature *)child;

- (void)sayHi;

@end
