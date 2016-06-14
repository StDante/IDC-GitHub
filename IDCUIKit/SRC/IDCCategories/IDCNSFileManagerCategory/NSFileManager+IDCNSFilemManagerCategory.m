//
//  NSFileManager+IDCNSFilemManagerCategory.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 09.06.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "NSFileManager+IDCNSFilemManagerCategory.h"

@implementation NSFileManager (IDCNSFilemManagerCategory)

+ (NSString *)directoryFolderPath {
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    
    return [paths firstObject];
}

+ (NSString *)pathFileWithName:(NSString *)name {
    return [[NSFileManager directoryFolderPath] stringByAppendingPathComponent:name];
}

@end
