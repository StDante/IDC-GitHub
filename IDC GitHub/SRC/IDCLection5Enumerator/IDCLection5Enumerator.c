//
//  IDCLection5Enumerator.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 10.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#include "IDCLection5Enumerator.h"

#pragma mark -
#pragma mark Private Declaration

static
IDCEnumerator *IDCEnumeratorCreate(void);

static
void IDCEnumeratorSetList(IDCEnumerator *enumerator, IDCLinkedList *list);

static
void IDCEnumeratorSetMutableCount(IDCEnumerator *enumerator, uint64_t mutableCount);

static
uint64_t IDCEnumeratorGetMutableCount(IDCEnumerator *enumerator);

#pragma mark -
#pragma mark Initialization and Deallocation

void __IDCEnumeratorDeallocate(IDCEnumerator *enumerator) {
    IDCReturnMacros(enumerator);
    
    IDCEnumeratorSetList(enumerator, NULL);
    IDCEnumeratorSetCurrentNode(enumerator, NULL);
    
    __IDCObjectDeallocate(enumerator);
}

IDCEnumerator *IDCEnumeratorCreate(void) {
    IDCEnumerator *enumerator = IDCObjectCreate(IDCEnumerator);
    assert(enumerator);
    
    IDCEnumeratorSetList(enumerator, NULL);
    IDCEnumeratorSetCurrentNode(enumerator, NULL);
    IDCEnumeratorSetMutableCount(enumerator, 0);
    
    return enumerator;
}

IDCEnumerator *IDCEnumeratorCreateWithList(IDCLinkedList *list) {
    IDCEnumerator *enumerator = IDCEnumeratorCreate();
    IDCEnumeratorSetList(enumerator, list);
    IDCEnumeratorSetCurrentNode(enumerator, IDCLinkedListGetHead(list));
    IDCEnumeratorSetMutableCount(enumerator, IDCLinkedListGetMutableCount(list));
    
    return enumerator;
}

#pragma mark - 
#pragma mark Accessors

void IDCEnumeratorSetList(IDCEnumerator *enumerator, IDCLinkedList *list) {
    IDCReturnMacros(enumerator);
    
    enumerator->_list = list;
}

IDCLinkedList *IDCEnumeratorGetList(IDCEnumerator *enumerator) {
    IDCReturnNULLMacros(enumerator);
    
    return enumerator->_list;
}

void IDCEnumeratorSetCurrentNode(IDCEnumerator *enumerator, IDCNode *node) {
    IDCReturnMacros(enumerator);
    
    enumerator->_currentNode = node;
}

IDCNode *IDCEnumeratorGetCurrentNode(IDCEnumerator *enumerator) {
    IDCReturnNULLMacros(enumerator);
    
    return enumerator->_currentNode;
}

void IDCEnumeratorSetMutableCount(IDCEnumerator *enumerator, uint64_t mutableCount) {
    IDCReturnMacros(enumerator);
    
    enumerator->_mutableCount = mutableCount;
}

uint64_t IDCEnumeratorGetMutableCount(IDCEnumerator *enumerator) {
    assert(enumerator);
    
    return enumerator->_mutableCount;
}

#pragma mark -
#pragma mark Public Implementation

bool IDCEnumeratorIsValid(IDCEnumerator *enumerator, IDCLinkedList *list) {
    IDCReturnValueMacros(enumerator, false);
    IDCReturnValueMacros(list, false);
    
    uint64_t enumeratorMutableCount = IDCEnumeratorGetMutableCount(enumerator);
    uint64_t listMutableCount = IDCLinkedListGetMutableCount(list);
    bool isValid = (enumeratorMutableCount == listMutableCount) ? true : false;
    
    return isValid;
}