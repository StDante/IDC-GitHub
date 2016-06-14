//
//  IDCStateUniversalModel.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 09.06.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCStateUniversalModel.h"

@implementation IDCStateUniversalModel

#pragma mark -
#pragma mark Public

- (void)load {
    if (self.state == kIDCModelLoadingState) {
        return;
    }
    
    if (self.state == kIDCModelLoadedState) {
        [self completionLoad];
        return;
    }
    
    self.state = kIDCModelLoadingState;
    
    [self setupLoad];
    
    IDCWeakifyMacro;
    IDCGCDAsyncInBackground(^{
        IDCStrongifyReturnIfNillMacro(IDCStateUniversalModel);
        [strongSelf prepareToLoad];
        IDCGCDAsyncOnMainThread(^{
            [strongSelf finishLoad];
        });
    });
}

- (void)dump {
    
}

- (void)setupLoad {
    
}

- (void)prepareToLoad {
    
}

- (void)completionLoad {
    [self finishLoad];
}

- (void)finishLoad {
    
}

@end
