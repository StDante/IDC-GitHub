//
//  IDCStringModel.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 09.05.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCStringModel.h"

static const NSInteger kIDCDefaultStringCount = 10;

static NSString * const kIDCStringCoderKey    = @"string";
static NSString * const kIDCStringURL         = @"https://i.imgflip.com/eb6.jpg";

@interface IDCStringModel()
@property (nonatomic, copy)     NSString    *string;
@property (nonatomic, copy)     NSString    *urlString;

@end

@implementation IDCStringModel

#pragma mark -
#pragma mark Class Methods

+ (instancetype)randomStringModel {
    return [[self class] new];
}

+ (instancetype)stringModelWithString:(NSString *)string {
    return [[[self class] alloc] initWithString:string];
}

+ (NSArray *)randomStringsModels {
    NSMutableArray *array = [NSMutableArray array];
    
    for (NSUInteger index = 0; index < arc4random_uniform(kIDCDefaultStringCount) + 1; index++) {
        [array addObject:[self randomStringModel]];
    }
    
    return [array copy];
}

#pragma mark -
#pragma mark Initialization and Deallocation

- (instancetype)init {
    self = [super init];
    if (self) {
        self.string = [NSString randomString];
    }
    
    return self;
}

- (instancetype)initWithString:(NSString *)string {
    self = [self init];
    if (self) {
        self.string = [string copy];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSString *)urlString {
    return kIDCStringURL;
}

#pragma mark -
#pragma mark NSCoding Protocol

- (instancetype)initWithCoder:(NSCoder *)aDecoder {
    self = [self init];
    if (self) {
        self.string = [aDecoder decodeObjectForKey:kIDCStringCoderKey];
    }
    
    return self;
}

- (void)encodeWithCoder:(NSCoder *)aCoder {
    [aCoder encodeObject:self.string forKey:kIDCStringCoderKey];
}

@end
