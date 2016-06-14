//
//  NSFileManager+IDCNSFilemManagerCategory.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 09.06.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSFileManager (IDCNSFilemManagerCategory)

+ (NSString *)directoryFolderPath;
+ (NSString *)pathFileWithName:(NSString *)name;

@end