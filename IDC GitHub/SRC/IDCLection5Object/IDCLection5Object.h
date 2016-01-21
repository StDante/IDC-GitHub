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

typedef struct IDCObject IDCObject;

struct IDCObject {
    uint8_t _referenceCount;
};

extern
void __IDCObjectDeallocate(void *object);

#define IDCObjectCreate(type) __IDCObjectCreate(sizeof(type))

extern
void *__IDCObjectCreate(size_t size);

extern
void *__IDCObjectRetain(void *object);

extern
void __IDCObjectRelease(void *object);


#endif /* IDCLection5Object_h */
