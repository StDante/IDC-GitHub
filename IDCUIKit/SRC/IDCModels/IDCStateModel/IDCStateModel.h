//
//  IDCStateModel.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 15.05.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, IDCObjectState) {
    kIDCObjectAddState,
    kIDCObjectRemoveState
};


@interface IDCStateModel : NSObject
@property (nonatomic, assign)   IDCObjectState  state;
@property (nonatomic, assign)   NSUInteger      index;

+ (IDCStateModel *)modelWithState:(IDCObjectState)state index:(NSUInteger)index;

@end
