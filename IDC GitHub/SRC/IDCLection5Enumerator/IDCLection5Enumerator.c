//
//  IDCLection5Enumerator.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 10.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//
//bool add nextnode = 0;
//add next node method;
//Context - struct that have inside - object, nodebefore and current node.


#include "IDCLection5Enumerator.h"

#pragma mark -
#pragma mark Private Declaration

static
IDCEnumerator *IDCEnumeratorCreate(void);

static
void IDCEnumeratorSetList(IDCEnumerator *enumerator, IDCLinkedList *list);

static
void IDCEnumeratorSetCurrentNode(IDCEnumerator *enumerator, IDCNode *node);

static
void IDCEnumeratorSetMutationsCount(IDCEnumerator *enumerator, uint64_t mutationsCount);

static
uint64_t IDCEnumeratorGetMutationsCount(IDCEnumerator *enumerator);

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
    IDCEnumeratorSetMutationsCount(enumerator, 0);
    
    return enumerator;
}

IDCEnumerator *IDCEnumeratorCreateWithList(IDCLinkedList *list) {
    IDCEnumerator *enumerator = IDCEnumeratorCreate();
    IDCEnumeratorSetList(enumerator, list);
    IDCEnumeratorSetMutationsCount(enumerator, IDCLinkedListGetMutationsCount(list));
    
    return enumerator;
}

#pragma mark - 
#pragma mark Accessors

void IDCEnumeratorSetList(IDCEnumerator *enumerator, IDCLinkedList *list) {
    IDCReturnMacros(enumerator);
    
    IDCRetainSetter(enumerator->_list, list);
}

IDCLinkedList *IDCEnumeratorGetList(IDCEnumerator *enumerator) {
    IDCReturnNULLMacros(enumerator);
    
    return enumerator->_list;
}

void IDCEnumeratorSetCurrentNode(IDCEnumerator *enumerator, IDCNode *node) {
    IDCReturnMacros(enumerator);
    
    IDCRetainSetter(enumerator->_currentNode, node);
}

IDCNode *IDCEnumeratorGetCurrentNode(IDCEnumerator *enumerator) {
    IDCReturnNULLMacros(enumerator);
    
    return enumerator->_currentNode;
}

IDCNode *IDCEnumeratorGetNextNode(IDCEnumerator *enumerator) {
    IDCReturnNULLMacros(enumerator);
    IDCLinkedList *list = IDCEnumeratorGetList(enumerator);
    IDCNode *node = IDCEnumeratorGetCurrentNode(enumerator);
    
    if (node == NULL) {
        node = IDCLinkedListGetHead(list);
    } else {
        node = IDCNodeGetNextNode(node);
        IDCEnumeratorSetCurrentNode(enumerator, node);
    }
    
    return node;
}

void IDCEnumeratorSetMutationsCount(IDCEnumerator *enumerator, uint64_t mutationsCount) {
    IDCReturnMacros(enumerator);
    
    IDCAssignSetter(enumerator->_mutationsCount, mutationsCount);
}

uint64_t IDCEnumeratorGetMutationsCount(IDCEnumerator *enumerator) {
    assert(enumerator);
    
    return enumerator->_mutationsCount;
}

#pragma mark -
#pragma mark Public Implementation

bool IDCEnumeratorIsValid(IDCEnumerator *enumerator, IDCLinkedList *list) {
    IDCReturnValueMacros(enumerator, false);
    IDCReturnValueMacros(list, false);
    
    uint64_t enumeratorMutationsCount = IDCEnumeratorGetMutationsCount(enumerator);
    uint64_t listMutationsCount = IDCLinkedListGetMutationsCount(list);
    IDCNode *node = IDCEnumeratorGetNextNode(enumerator);
    bool isValid = (enumeratorMutationsCount == listMutationsCount) && node;
    
    return isValid;
}