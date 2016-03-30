//
//  IDCCarWasher.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 28.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCWorker.h"

typedef void (^IDCCarWasherHandler)(void);
@interface IDCCarWasher : IDCWorker
@property (nonatomic, retain) NSMutableDictionary *handlersDictionary;

- (void)addHandler:(IDCCarWasherHandler)carWasherHandler forState:(NSUInteger)state;

@end
