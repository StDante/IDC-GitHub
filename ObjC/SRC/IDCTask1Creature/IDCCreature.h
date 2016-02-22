//
//  IDCCreature.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 22.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IDCCreature : NSObject;

typedef enum {
    kIDCUnknownGender,
    kIDCMale,
    kIDCFemale
} IDCGender;

@property (nonatomic, readonly)  NSArray   *children;
@property (nonatomic, copy)      NSString  *name;
@property (nonatomic, readonly)  IDCGender gender;
@property (nonatomic, retain)    NSNumber  *age;
@property (nonatomic, retain)    NSNumber  *weight;

+ (instancetype)creatureWithName:(NSString *)name gender:(IDCGender)gender;
+ (Class)classFromGender:(IDCGender)gender;

- (instancetype)initWithName:(NSString *)name;

- (void)addChild:(IDCCreature *)child;
- (void)removeChild:(IDCCreature *)child;
- (void)sayHi;
- (void)allSayHi;
- (void)performGenderSpecificOperation;

@end

