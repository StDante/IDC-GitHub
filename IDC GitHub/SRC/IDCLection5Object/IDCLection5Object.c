//
//  IDCLection5Object.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 21.01.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#include <stdlib.h>
#include <assert.h>
#include "IDCLection5Macros.h"
#include "IDCLection5Object.h"

#pragma mark -
#pragma mark Initialization and Deallocation

void __IDCObjectDeallocate(void *object) {
    free(object);
}

void *__IDCObjectCreate(size_t size, IDCObjectDeallocator *deallocator) {
    IDCObject *object = calloc(1, sizeof(size));
    assert(object);
    
    object->_referenceCount = 1;
    
    return object;
}

#pragma mark -
#pragma mark Private Implementation

void __IDCObjectRelease(void *object) {
    IDCReturnMacros(object);
    
    IDCObject *newObject = object;
    newObject->_referenceCount--;
    
    if (0 == newObject->_referenceCount) {
        newObject->_deallocator(newObject);
        __IDCObjectDeallocate(object);
    }
    
}

void *__IDCObjectRetain(void *object) {
    assert(object);
    
    IDCObject *newObject = object;
    newObject->_referenceCount++;
    
    return object;
}