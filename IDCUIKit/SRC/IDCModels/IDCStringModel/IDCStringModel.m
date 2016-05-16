//
//  IDCStringModel.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 09.05.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCStringModel.h"

static const NSInteger kIDCDefaultStringCount = 10;
static NSString * const kIDCCellImagePath = @"/Users/Altukhov/Documents/Курсы/Программирование/IDC GitHub/IDCUIKit/Assets.xcassets/imageForCell.imageset/Orly.jpg";

@interface IDCStringModel()
@property (nonatomic, copy)     NSString    *string;
@property (nonatomic, strong)   UIImage     *image;

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
        self.image  = [[UIImage alloc] initWithContentsOfFile:[kIDCCellImagePath copy]];
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

@end
