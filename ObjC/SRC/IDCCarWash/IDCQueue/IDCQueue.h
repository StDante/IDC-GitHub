//
//  IDCQueue.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 06.04.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IDCQueue : NSObject
@property (nonatomic, retain) NSArray *queue;

- (void)pushObject:(id)object;
- (id)popObject;

@end
