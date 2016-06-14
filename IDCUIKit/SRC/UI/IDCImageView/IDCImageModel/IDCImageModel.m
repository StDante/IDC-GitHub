//
//  IDCImageModel.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 12.06.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCImageModel.h"
#import "IDCObjectCache.h"

@interface IDCImageModel ()
@property (nonatomic, readonly, getter=isCached) BOOL       cached;
@property (nonatomic, readonly)                  NSString   *path;
@property (nonatomic, readonly)                  NSString   *fileName;

@property (nonatomic, strong) NSURLSession              *session;
@property (nonatomic, strong) NSURLSessionDownloadTask  *task;

@property (nonatomic, readonly) IDCObjectCache *cache;

- (void)removeIfNeeded;
- (void)loadFromFile;
- (void)download;

@end

@implementation IDCImageModel

@dynamic cached;
@dynamic path;
@dynamic fileName;
@dynamic cache;

#pragma mark -
#pragma mark Class Methods

+ (instancetype)imageModelWithURL:(NSURL *)URL {
    return [[self alloc] initWithURL:URL];
}

#pragma mark -
#pragma mark Initializations & Deallocations

- (void)dealloc {
    self.task = nil;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        NSURLSessionConfiguration *config = [NSURLSessionConfiguration ephemeralSessionConfiguration];
        self.session = [NSURLSession sessionWithConfiguration:config];
    }
    
    return self;
}

- (instancetype)initWithURL:(NSURL *)URL {
    self = [self init];
    if (self) {
        self.URL = URL;
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

-(IDCObjectCache *)cache {
    return [IDCObjectCache sharedObject];
}

- (void)setURL:(NSURL *)URL {
    if (![_URL isEqual:URL]) {
        _URL = URL;
        
        [self dump];
    }
    
    [self load];
}

- (NSString *)fileName {
    return [self.URL lastPathComponent];
}

- (NSString *)path {
    return [NSFileManager pathFileWithName:self.fileName];
}

- (BOOL)isCached {
    return [self.cache isCachedWithKey:self.URL];
}

-(void)setTask:(NSURLSessionDownloadTask *)task {
    if (_task != task) {
        [_task cancel];
        _task = task;
        [_task resume];
    }
}

#pragma mark -
#pragma mark Public

- (void)prepareToLoad {
    if (self.URL.isFileURL || self.isCached) {
        [self loadFromFile];
    } else {
        [self download];
    }
}

- (void)dump {
    self.state = kIDCModelUndefinedState;
}

#pragma mark -
#pragma mark Private

- (void)download {
    NSURL *URL = self.URL;
    self.task = [self.session downloadTaskWithURL:URL
                                completionHandler:^(NSURL *location, NSURLResponse *response,
                                                    NSError *error)
                 {
                     if (!error) {
                         NSString *path = self.path;
                         NSError *saveError = nil;
                         NSFileManager *manager = [NSFileManager defaultManager];
                         if (!self.isCached && [manager fileExistsAtPath:path]) {
                             [manager removeItemAtPath:path error:nil];
                         }
                         
                         [manager copyItemAtURL:location toURL:[NSURL fileURLWithPath:self.path] error:&saveError];
                         if (!saveError) {
                             [self.cache setObject:self.fileName forKey:URL];
                         }
                         
                         [self loadFromFile];
                     }
                 }];
}

- (void)loadFromFile {
    UIImage *image = [UIImage imageWithContentsOfFile:self.path];
    if (!image) {
        [self removeIfNeeded];
    } else {
        self.image = image;
    }
    
    [self completionLoad];
}

- (void)completionLoad; {
    IDCWeakifyMacro;
    IDCGCDAsyncOnMainThread(^{
        IDCStrongifyReturnIfNillMacro(IDCImageModel);
        NSUInteger state = strongSelf.image ? kIDCModelLoadedState : kIDCModelFailedState;
        [strongSelf setState:state withObject:strongSelf.image];
    });
}

- (void)removeIfNeeded {
    if (self.isCached) {
        NSError *error = nil;
        [[NSFileManager defaultManager] removeItemAtPath:self.path error:&error];
        [self.cache removeObjectForKey:self.URL];
    }
}

@end