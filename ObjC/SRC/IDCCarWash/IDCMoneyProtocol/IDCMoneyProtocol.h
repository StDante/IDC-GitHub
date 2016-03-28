//
//  IDCMoneyProtocol.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 28.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol IDCMoneyProtocol <NSObject>
@property (nonatomic, assign) NSUInteger money;

@required
- (NSUInteger)giveMoney;

@optional
- (void)takeMoney:(NSUInteger)money;

@end
