//
//  IDCLection5Object.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 21.01.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#include <stdlib.h>
#include <assert.h>
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
    object->_deallocator = deallocator;
    
    return object;
}

#pragma mark -
#pragma mark Private Implementation

void IDCObjectRelease(void *object) {
    IDCReturnMacros(object);
    
    IDCObject *newObject = object;
    newObject->_referenceCount--;
    
    if (0 == newObject->_referenceCount) {
        newObject->_deallocator(object);
    }
}

void *IDCObjectRetain(void *object) {
    IDCReturnNULLMacros(object);
    
    IDCObject *newObject = object;
    newObject->_referenceCount++;
    
    return object;
}