//
//  IDCSaveArrayModel.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 09.06.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCSaveArrayModel.h"

static NSString * const kIDCFileAdress       = @"temp.plist";

@interface IDCSaveArrayModel ()
@property (nonatomic, readonly)                  NSString        *path;
@property (nonatomic, readonly, getter=isCached) BOOL            cached;

@property (nonatomic, readonly) NSArray *keys;

+ (instancetype)model;

- (void)save;
- (void)addObserversWithKeys:(NSArray *)keys;
- (void)removeObserversWithKeys:(NSArray *)keys;

@end

@implementation IDCSaveArrayModel

@dynamic keys;

#pragma mark -
#pragma mark Class Methods

+ (instancetype)model {
    IDCSaveArrayModel *model = [IDCSaveArrayModel new];
    if (model.isCached) {
        return [NSKeyedUnarchiver unarchiveObjectWithFile:model.path];
    } else {
        return [IDCSaveArrayModel arrayModelWithArray:[IDCStringModel randomStringsModels]];
    }
}

#pragma mark -
#pragma mark Initializations and Deallocatins

- (void)dealloc {
    [self removeObserversWithKeys:self.keys];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        [self addObserversWithKeys:self.keys];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSArray *)keys {
    return @[UIApplicationDidEnterBackgroundNotification, UIApplicationWillTerminateNotification];
}

- (NSString *)path {
    return [NSFileManager pathFileWithName:kIDCFileAdress];
}

- (BOOL)isCached {
    return [[NSFileManager defaultManager] fileExistsAtPath:self.path];
}

#pragma mark -
#pragma mark Private

- (void)addObserversWithKeys:(NSArray *)keys {
    for (NSString *key in self.keys) {
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(save)
                                                     name:key
                                                   object:nil];
    }
}

- (void)removeObserversWithKeys:(NSArray *)keys {
    for (NSString *key in self.keys) {
        [[NSNotificationCenter defaultCenter] removeObserver:self
                                                        name:key
                                                      object:nil];
    }
}

- (void)save {
    [NSKeyedArchiver archiveRootObject:self toFile:self.path];
}

#pragma mark -
#pragma mark Public

- (void)finishLoad {
    self.state = kIDCModelLoadedState;
}

- (void)prepareToLoad {
    IDCSaveArrayModel *model = [IDCSaveArrayModel model];
    [self addObjects:model.objects];
}

@end