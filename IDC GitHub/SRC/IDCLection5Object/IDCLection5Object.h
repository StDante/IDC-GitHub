//
//  IDCLection5Object.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 21.01.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#ifndef IDCLection5Object_h
#define IDCLection5Object_h

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "IDCLection5Macros.h"

typedef struct IDCObject IDCObject;

typedef void (IDCObjectDeallocator) (void *object);

struct IDCObject {
    uint16_t _referenceCount;
    IDCObjectDeallocator *_deallocator;
};

extern
void __IDCObjectDeallocate(void *object);

extern
void *__IDCObjectCreate(size_t size, IDCObjectDeallocator *deallocator);

extern
void *IDCObjectRetain(void *object);

extern
void IDCObjectRelease(void *object);


#endif /* IDCLection5Object_h */
