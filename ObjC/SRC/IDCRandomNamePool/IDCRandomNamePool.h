//
//  IDCRandomNamePool.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 28.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IDCRandomNamePool : NSObject
@property (nonatomic, copy) NSArray *namePool;


+ (instancetype)namePool;
- (NSString *)nameFromPool;

@end
