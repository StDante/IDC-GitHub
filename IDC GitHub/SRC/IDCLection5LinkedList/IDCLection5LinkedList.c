//
//  IDCLection5LinkedList.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 08.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//
// ADD BOOL "ContainsObject"
// ADD Setter And Getter For First Object

#include "IDCLection5LinkedList.h"
#include "IDCLection5LinkedListPrivateHeader.h"

#pragma mark -
#pragma mark Private Declaration

#pragma mark -
#pragma mark Initialization and Deallocation

void __IDCLinkedListDeallocate(IDCLinkedList *list) {
    IDCLinkedListSetHead(list, NULL);
    
    __IDCObjectDeallocate(list);
}

IDCLinkedList *IDCLinkedListCreate(void) {
    IDCLinkedList *list = IDCObjectCreate(IDCLinkedList);
    list->_head = NULL;
    list->_count = 0;
    
    return list;
}

IDCLinkedList *IDCLinkedListCreateWithObject(void *object) {
    IDCLinkedList *list = IDCLinkedListCreate();
    IDCLinkedListAddObject(list, object);
    
    return list;
}

#pragma mark -
#pragma mark Accessors

void IDCLinkedListSetHead(IDCLinkedList *list, IDCNode *node) {
    IDCReturnMacros(list);
    
    IDCRetainSetter(list->_head, node);
}

IDCNode *IDCLinkedListGetHead(IDCLinkedList *list) {
    IDCReturnNULLMacros(list);
    
    return list->_head;
}

void *IDCLinkedListGetFirstObject(IDCLinkedList *list) {
    return IDCNodeGetObject(IDCLinkedListGetHead(list));
}

void *IDCLinkedListGetObject(IDCLinkedList *list, void *object) {
    IDCReturnNULLMacros(list);
    uint64_t stepsCount = 1;
    uint64_t count = IDCLinkedListGetCount(list);
    
    IDCNode *node = IDCLinkedListGetHead(list);
    
    while (IDCNodeGetObject(node) != object) {
        node = IDCNodeGetNextNode(node);
        stepsCount++;
        IDCReturnNULLIfFirstValueIsBigger(stepsCount, count);
    }
    
    return IDCNodeGetObject(node);
}

void IDCLinkedListSetCount(IDCLinkedList *list, uint64_t count) {
    IDCReturnMacros(list);
    
    list->_count = count;
}


uint64_t IDCLinkedListGetCount(IDCLinkedList *list) {
    assert(list);
    
    return list->_count;
}


#pragma mark -
#pragma mark Private Implementation

#pragma mark -
#pragma mark Public Implementation

bool IDCLinkedListContainsObject(IDCLinkedList *list, void *object) {
    IDCReturnValueMacros(list, false);
    IDCReturnValueMacros(object, false);
    
    IDCNode *node = IDCLinkedListGetHead(list);
    while (IDCNodeGetObject(node) != object || !node) {
        node = IDCNodeGetNextNode(node);
    }

    return node;
}

void IDCLinkedListAddObject(IDCLinkedList *list, void *object) {
    IDCReturnMacros(list);
    IDCNode *node = IDCLinkedListGetHead(list);
    uint64_t count = IDCLinkedListGetCount(list);
    
    if (node == NULL) {
        node = IDCNodeCreateWithObject(object);
        IDCLinkedListSetHead(list, node);
    } else {
        node = IDCNodeCreateWithObject(object);
        IDCNodeSetNextNode(node, IDCLinkedListGetHead(list));
        IDCLinkedListSetHead(list, node);
    }
    
    IDCObjectRelease(node);
    IDCLinkedListSetCount(list, count++);
}

void IDCLinkedListRemoveObject(IDCLinkedList *list, void *object) {
    IDCReturnMacros(list);
    IDCNode *node = IDCLinkedListGetHead(list);
    IDCNode *nodeBefore = NULL;
    uint64_t stepsCount = 1;
    uint64_t count = IDCLinkedListGetCount(list);
    
    if (IDCNodeGetObject(node) == object) {
        IDCLinkedListSetHead(list, IDCNodeGetNextNode(node));
        IDCObjectRelease(node);
    } else {
        while (IDCNodeGetObject(node) != object) {
            nodeBefore = node;
            node = IDCNodeGetNextNode(node);
            stepsCount++;
            IDCReturnIfFirstValueIsBigger(stepsCount, count);
        }
        
        IDCNodeSetNextNode(nodeBefore, IDCNodeGetNextNode(node));
        IDCObjectRelease(node);
    }
    
    IDCLinkedListSetCount(list, count--);
}

void IDCLinkedListRemoveAllObject(IDCLinkedList *list) {
    IDCLinkedListSetHead(list, NULL);
}