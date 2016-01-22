//
//  IDCLection5Macro.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 21.01.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#ifndef IDCLection5Macros_h
#define IDCLection5Macros_h

#define IDCReturnMacros(value) \
            if (NULL == value) { \
                printf("There is no such object"); \
                return; \
            }

#define IDCObjectCreate(type) \
            __IDCObjectCreate(sizeof(type), (IDCObjectDeallocator *)__##type##Deallocate);


#endif /* IDCLection5Macro_h */
