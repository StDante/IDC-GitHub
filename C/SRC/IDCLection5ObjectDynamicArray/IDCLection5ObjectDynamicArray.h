//
//  IDCLection5ObjectDynamicArray.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 03.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#ifndef IDCLection5ObjectDynamicArray_h
#define IDCLection5ObjectDynamicArray_h

#include "IDCLection5Object.h"
#include <stdbool.h>

typedef struct IDCDynamicArray IDCDynamicArray;

struct IDCDynamicArray {
    IDCObject _super;
    void **_arrayData;
    uint64_t _count;
    uint64_t _capacity;
};

extern
void __IDCDynamicArrayDeallocate(IDCDynamicArray *array);

extern
void *IDCDynamicArrayCreate(void);

extern
void **IDCDynamicArrayGetData(IDCDynamicArray *array);

extern
void IDCDynamicArrayAddObject(IDCDynamicArray *array, void *object);

extern
void IDCDynamicArrayRemoveObject(IDCDynamicArray *array, void *object);

extern
void IDCDynamicArrayRemoveAllObjects(IDCDynamicArray *array);

extern
uint64_t IDCDynamicArrayGetIndexOfObject(IDCDynamicArray *array, void *object);

extern
void *IDCDynamicArrayGetObjectAtIndex(IDCDynamicArray *array, uint64_t index);

extern
void *IDCDynamicArrayGetFirstObject(IDCDynamicArray *array);

extern
void *IDCDynamicArrayGetLastObject(IDCDynamicArray *array);

extern
bool IDCDynamicArrayIsEmpty(IDCDynamicArray *array);

extern
bool IDCDynamicArrayIsContainsObject(IDCDynamicArray *array, void *object);

extern
uint64_t IDCDynamicArrayGetCapacity(IDCDynamicArray *array);

extern
uint64_t IDCDynamicArrayGetCount(IDCDynamicArray *array);

#endif /* IDCLection5ObjectDynamicArray_h */
