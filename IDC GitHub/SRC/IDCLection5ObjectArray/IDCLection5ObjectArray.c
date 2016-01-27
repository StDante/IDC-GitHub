//
//  IDCLection5ObjectArray.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 27.01.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#include <assert.h>
#include "IDCLection5ObjectArray.h"

#pragma mark -
#pragma mark - Privat Declarations

static
void __IDCArrayDeallocate(IDCArray *array);

#pragma mark -
#pragma mark Initialization and Deallocation

void __IDCArrayDeallocate(IDCArray *array) {
    IDCArrayDeleteAllElements(array);
    __IDCObjectDeallocate(array);
    
}

void *IDCArrayCreate(void) {
    IDCArray *array = IDCObjectCreate(IDCArray);
    assert(array);
    
    return array;
}

#pragma mark -
#pragma mark Private Implementation

uint8_t IDCArrayGetIndexOfOldestElement(IDCArray *array);

#pragma mark - 
#pragma mark Public Implementation

void IDCArrayAddElement(IDCArray *array, void *object) {
    IDCReturnMacros(array);
    IDCReturnMacros(object);
    
    if (kIDCArrayLimit > IDCArrayGetCount(array)) {
        array->_arrayData[IDCArrayGetCount(array)] = object;
    } else if (kIDCArrayLimit == IDCArrayGetCount(array)) {
        array->_arrayData[IDCArrayGetIndexOfOldestElement(array)] = object;
    }
    
}

void IDCArrayRemoveElement(IDCArray *array, void *object) {
    IDCReturnMacros(array);
    uint8_t index = IDCArrayGetIndexOfElement(array, object);
    
    if (index > kIDCArrayLimit) {
        printf("There is no such object in array");
        return;
    }
    
    IDCArrayRemoveElementAtIndex(array, index);
    
}

void __IDCArrayResortElementsFromIndex(IDCArray *array, uint8_t index) {
    IDCReturnMacros(array);
    uint8_t indexReplace = index + 1;
    while (indexReplace < IDCArrayGetCount(array)) {
        array->_arrayData[indexReplace - 1] = array->_arrayData[indexReplace];
        indexReplace++;
    }
    
}

void IDCArraySetElementAtIndex(IDCArray *array, void *object, uint8_t index) {
    IDCReturnMacros(array);
    IDCReturnMacros(object);
    
    IDCRetainSetter(array->_arrayData[index], object);
    
}

extern
void *IDCArrayGetElementAtIndex(IDCArray *array, uint8_t index) {
    assert(array);
    
    if (index < kIDCArrayLimit) {
        return array->_arrayData[index];
    }
    
    return NULL;
}

void IDCArrayRemoveElementAtIndex(IDCArray *array, uint8_t index) {
    IDCReturnMacros(array);
    
    IDCRetainSetter(array->_arrayData[index], NULL);
    __IDCArrayResortElementsFromIndex(array, index);
    
}

uint8_t IDCArrayGetCount(IDCArray *array) {
    assert(array);
    
    uint8_t index = 0;
    while (array->_arrayData[index] != NULL) {
        index++;
    }
    
    return index;
}

void *IDCArrayGetAllElements(IDCArray *array) {
    assert(array);
    
    return array->_arrayData;
}

uint8_t IDCArrayGetIndexOfElement(IDCArray *array, void *object) {
    assert(array);
    assert(object);
    
    uint8_t index = 0;
    if (index < IDCArrayGetCount(array)) {
        while (object != IDCArrayGetElementAtIndex(array, index)) {
            index++;
        }
        
        return index;
    }
    
    return kIDCArrayReturnIndexMax;
}

void IDCArrayDeleteAllElements(IDCArray *array) {
    uint8_t index = IDCArrayGetCount(array);
    
    while (0 != index) {
        IDCArrayRemoveElementAtIndex(array, --index);
    }
    
}