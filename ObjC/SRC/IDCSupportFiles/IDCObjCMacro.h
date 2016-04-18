//
//  IDCObjCMacro.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 18.04.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#ifndef IDCObjCMacro_h
#define IDCObjCMacro_h

#define IDCWeakifyMacro(object) \
__weak typeof(object) *weakSelf = object \


#define IDCStrongifyMacro(object) \
__strong typeof(object) *strongSelf = weakSelf; \
if (!strongSelf) { \
return; \
}


#endif /* IDCObjCMacro_h */
