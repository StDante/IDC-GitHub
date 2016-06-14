//
//  IDCStateModel.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 15.05.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCStateModel.h"

@implementation IDCStateModel

#pragma mark -
#pragma mark Class Methods

+ (IDCStateModel *)modelWithState:(IDCObjectState)state index:(NSUInteger)index {
    IDCStateModel *model = [IDCStateModel new];
    model.state = state;
    model.index = index;
    
    return model;
}

@end
