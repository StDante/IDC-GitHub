//
//  IDCStateUniversalModel.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 09.06.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCObserver.h"
#import "IDCObjCMacro.h"
#import "IDCGCDQueue.h"


typedef NS_ENUM(NSUInteger, IDCStatesModel) {
    kIDCModelUndefinedState,
    kIDCModelDefaultState,
    kIDCModelLoadingState,
    kIDCModelChangeState,
    kIDCModelLoadedState,
    kIDCModelFailedState
};

@interface IDCStateUniversalModel : IDCObserver

- (void)load;
- (void)dump;
- (void)setupLoad;
- (void)prepareToLoad;
- (void)completionLoad;
- (void)finishLoad;

@end
