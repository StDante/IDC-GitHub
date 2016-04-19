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


#endif /* IDCObjCMacro_h */
