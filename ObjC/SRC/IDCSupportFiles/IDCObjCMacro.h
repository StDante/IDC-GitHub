//
//  IDCObjCMacro.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 18.04.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#ifndef IDCObjCMacro_h
#define IDCObjCMacro_h

#define IDCWeakifyMacro \
__weak id weakSelf = self; \


#define IDCStrongifyReturnIfNillMacro \
__strong id strongSelf = weakSelf; \
            if (!strongSelf) { \
                return; \
            }

#define IDCRootViewIfReturnNilMacro(theClass) \
            - (theClass *)rootView {\
                if ([self isViewLoaded] && [self.view isKindOfClass:[theClass class]]) { \
                    return (theClass *)self.view; \
                } \
                return nil;\
            }

#endif /* IDCObjCMacro_h */
