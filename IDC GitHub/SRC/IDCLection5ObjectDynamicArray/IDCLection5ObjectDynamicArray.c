//
//  IDCLection5ObjectDynamicArray.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 03.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "IDCLection5ObjectDynamicArray.h"

#pragma mark -
#pragma mark Private Declarations

static const uint64_t kIDCCapacityStep = 1;

static
void IDCDynamicArraySetCount(IDCDynamicArray *array, uint64_t count);

static
void IDCDynamicArraySetCapacity(IDCDynamicArray *array, uint64_t capacity);

static
void IDCDynamicArrayShiftObjectsFromIndex(IDCDynamicArray *array, uint64_t index);

static
void IDCDynamicArraySetData(IDCDynamicArray *array, void **data);

static
void IDCDynamicArraySetObjectAtIndex(IDCDynamicArray *array,
                                     void *object,
                                     uint64_t index);

static
void IDCDynamicArrayRemoveObjectAtIndex(IDCDynamicArray *array, uint64_t index);

#pragma mark -
#pragma mark Initialization and Deallocation

void __IDCDynamicArrayDeallocate(IDCDynamicArray *array) {
    IDCDynamicArrayRemoveAllObjects(array);
    
    __IDCObjectDeallocate(array);
}

void *IDCDynamicArrayCreate(void) {
    IDCDynamicArray *array = IDCObjectCreate(IDCDynamicArray);
    assert(array);
    IDCDynamicArraySetCapacity(array, 1);
    IDCDynamicArraySetCount(array, 0);
    
    return array;
}

#pragma mark -
#pragma mark Accessors

void IDCDynamicArraySetData(IDCDynamicArray *array, void **data) {
    IDCReturnMacros(array);
    
    IDCAssignSetter(array->_arrayData, data);
}

void **IDCDynamicArrayGetData(IDCDynamicArray *array) {
    IDCReturnNULLMacros(array);
    return array->_arrayData;
}

void IDCDynamicArraySetObjectAtIndex(IDCDynamicArray *array,
                                     void *object,
                                     uint64_t index)
{
    IDCReturnMacros(array);
    
    IDCRetainSetter(array->_arrayData[index], object);
}

uint64_t IDCDynamicArrayGetIndexOfObject(IDCDynamicArray *array, void *object) {
    assert(array);
    uint64_t index = 0;
    if (IDCDynamicArrayIsContainsObject(array, object) == true) {
        while (IDCDynamicArrayGetObjectAtIndex(array, index) != object) {
            index++;
        }
        
        return index;
    }
    
    return puts("There is no such object in array");
}

void *IDCDynamicArrayGetObjectAtIndex(IDCDynamicArray *array, uint64_t index) {
    assert(array);
    
    if (index >= IDCDynamicArrayGetCount(array)) {
        printf("There is no such index in array");
        return NULL;
    }
    
    return array->_arrayData[index];
}

void *IDCDynamicArrayGetFirstObject(IDCDynamicArray *array) {
    assert(array);
    
    if (IDCDynamicArrayIsEmpty(array) == true) {
        printf("Array is empty");
        return NULL;
    }
    
    return array->_arrayData[0];
}

void *IDCDynamicArrayGetLastObject(IDCDynamicArray *array) {
    assert(array);
    
    if (IDCDynamicArrayIsEmpty(array) == true) {
        printf("Array is empty");
        return NULL;
    }
    
    return array->_arrayData[IDCDynamicArrayGetCount(array) - 1];
}

void IDCDynamicArraySetCapacity(IDCDynamicArray *array, uint64_t capacity) {
    IDCReturnMacros(array);
    
    uint64_t arrayCapacity = IDCDynamicArrayGetCapacity(array);
    uint64_t count = IDCDynamicArrayGetCount(array);
    size_t size = sizeof(void *);
    
    if (arrayCapacity == capacity) {
        return;
    }
        
    if (arrayCapacity < capacity) {
        IDCDynamicArraySetData(array, realloc(IDCDynamicArrayGetData(array), capacity * size));
        memset(&array->_arrayData[count], 0, (capacity - count) * sizeof(void *));
    }
        
    IDCAssignSetter(array->_capacity, capacity);
}

uint64_t IDCDynamicArrayGetCapacity(IDCDynamicArray *array) {
    assert(array);
    
    return array->_capacity;
}

void IDCDynamicArraySetCount(IDCDynamicArray *array, uint64_t count) {
    IDCReturnMacros(array);
    
    IDCAssignSetter(array->_count, count);
}

uint64_t IDCDynamicArrayGetCount(IDCDynamicArray *array) {
    assert(array);
    
    return array->_count;
}

#pragma mark -
#pragma mark Private Implementation

void IDCDynamicArrayShiftObjectsFromIndex(IDCDynamicArray *array, uint64_t index) {
    
    void *lastObject = IDCDynamicArrayGetLastObject(array);
    uint64_t indexReplace = index + 1;
    uint64_t indexLast = IDCDynamicArrayGetIndexOfObject(array, lastObject);
    
    while (indexReplace <= indexLast) {
        IDCAssignSetter(array->_arrayData[index], array->_arrayData[indexReplace]);
        index++;
    }
}

void IDCDynamicArrayRemoveObjectAtIndex(IDCDynamicArray *array, uint64_t index) {
    IDCReturnMacros(array);
    
    uint64_t capacity = IDCDynamicArrayGetCapacity(array);
    uint64_t count = IDCDynamicArrayGetCount(array);
    
    if (index >= count) {
        printf("There is no object with such index in array");
        return;
    }
    
    IDCRetainSetter(array->_arrayData[index], NULL);
    IDCDynamicArrayShiftObjectsFromIndex(array, index);
    IDCDynamicArraySetCount(array, count--);
    if (capacity - count == kIDCCapacityStep) {
        IDCDynamicArraySetCapacity(array, capacity - kIDCCapacityStep);
    }
}

#pragma mark -
#pragma mark Public Implementation

void IDCDynamicArrayAddObject(IDCDynamicArray *array, void *object) {
    IDCReturnMacros(array);
    
    uint64_t capacity = IDCDynamicArrayGetCapacity(array);
    uint64_t count = IDCDynamicArrayGetCount(array);
    
    if (capacity == count) {
        IDCDynamicArraySetCapacity(array, count + kIDCCapacityStep);
    }
    
    IDCDynamicArraySetObjectAtIndex(array, object, count);
    IDCDynamicArraySetCount(array, count++);
}

void IDCDynamicArrayRemoveObject(IDCDynamicArray *array, void *object) {
    assert(array);
    uint64_t index = IDCDynamicArrayGetIndexOfObject(array, object);
    
    IDCDynamicArrayRemoveObjectAtIndex(array, index);
}

void IDCDynamicArrayRemoveAllObjects(IDCDynamicArray *array) {
    
    void *lastObject = IDCDynamicArrayGetLastObject(array);
    uint64_t indexLast = IDCDynamicArrayGetIndexOfObject(array, lastObject);
    
    while (IDCDynamicArrayGetCount(array) != 0) {
        IDCDynamicArrayRemoveObjectAtIndex(array, indexLast);
    }
}

bool IDCDynamicArrayIsEmpty(IDCDynamicArray *array) {
    assert(array);
    
    if (IDCDynamicArrayGetObjectAtIndex(array, 0) == NULL) {
        printf("Array is empty");
        
        return true;
    }
    printf("Array is not empty");
    
    return false;
}

bool IDCDynamicArrayIsContainsObject(IDCDynamicArray *array, void *object) {
    assert(array);
    
    if (IDCDynamicArrayIsEmpty(array) == true) {
        return false;
    }
    
    uint64_t index = 0;
    
    if (IDCDynamicArrayGetObjectAtIndex(array, index) != object) {
        while (index < IDCDynamicArrayGetCount(array)) {
            index++;
        }
        printf("This Array doesn't contain such object");
        
        return false;
    }
    printf("This Array contains such object");
    
    return true;
}
