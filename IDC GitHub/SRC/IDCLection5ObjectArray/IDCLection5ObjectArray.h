//
//  IDCLection5ObjectArray.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 27.01.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#ifndef IDCLection5ObjectArray_h
#define IDCLection5ObjectArray_h

#include "IDCLection5Object.h"

static const uint8_t kIDCArrayReturnIndexMax = UINT8_MAX;
static const uint8_t kIDCArrayLimit = 20;

typedef struct IDCArray IDCArray;

struct IDCArray {
    IDCObject _super;
    void *_arrayData[kIDCArrayLimit];
};

extern
void *IDCArrayCreate(void);

extern
void IDCArrayAddElement(IDCArray *array, void *object);

extern
void IDCArrayRemoveElement(IDCArray *array, void *object);

extern
void __IDCArrayResortElementsFromIndex(IDCArray *array, uint8_t index);

extern
void IDCArraySetElementAtIndex(IDCArray *array, void *object, uint8_t index);

extern
void *IDCArrayGetElementAtIndex(IDCArray *array, uint8_t index);

extern
void IDCArrayRemoveElementAtIndex(IDCArray *array, uint8_t index);

extern
uint8_t IDCArrayGetCount(IDCArray *array);

extern
void *IDCArrayGetAllElements(IDCArray *array);

extern
uint8_t IDCArrayGetIndexOfElement(IDCArray *array, void *object);

extern
uint8_t IDCArrayGetIndexOfOldestElement(IDCArray *array);

extern
void IDCArrayDeleteAllElements(IDCArray *array);

#endif /* IDCLection5ObjectArray_h */
