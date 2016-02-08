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

#pragma mark -
#pragma mark Private Declaration

static
IDCNode *IDCNodeCreate(void);

static
void IDCLinkedListSetHead(IDCLinkedList *list, IDCNode *node);

#pragma mark -
#pragma mark Initialization and Deallocation


void __IDCNodeDeallocate(IDCNode *node) {
    IDCReturnMacros(node);
    IDCNodeSetObject(node, NULL);
    IDCNodeSetNextNode(node, NULL);
    
    __IDCObjectDeallocate(node);
}

IDCNode *IDCNodeCreate() {
    IDCNode *node = IDCObjectCreate(IDCNode);
    assert(node);
    
    return node;
}

IDCNode *IDCNodeCreateWithObject(void *object) {
    IDCNode *node = IDCNodeCreate();
    IDCNodeSetObject(node, object);
    IDCNodeSetNextNode(node, NULL);
    
    return node;
}

void __IDCLinkedListDeallocate(IDCLinkedList *list) {
    IDCLinkedListRemoveAllObjects(list);
    
    __IDCObjectDeallocate(list);
}

IDCLinkedList *IDCLinkedListCreate(void) {
    IDCLinkedList *list = IDCObjectCreate(IDCLinkedList);
    list->_head = NULL;
    list->_count = 0;
    
    return list;
}

#pragma mark -
#pragma mark Accessors

void IDCNodeSetObject(IDCNode *node, void *object) {
    IDCReturnMacros(node);
    
    IDCRetainSetter(node->_object, object);
}

void *IDCNodeGetObject(IDCNode *node) {
    IDCReturnNULLMacros(node);
    
    return node->_object;
}

void IDCNodeSetNextNode(IDCNode *node, IDCNode *nextNode) {
    IDCReturnMacros(node);
    
    IDCRetainSetter(node->_nextNode, nextNode);
}

IDCNode *IDCNodeGetNextNode(IDCNode *node) {
    IDCReturnNULLMacros(node);
    
    return node->_nextNode;
}

void IDCLinkedListSetHead(IDCLinkedList *list, IDCNode *node) {
    IDCReturnMacros(list);
    
    IDCRetainSetter(list->_head, node);
}

IDCNode *IDCLinkedListGetHead(IDCLinkedList *list) {
    IDCReturnNULLMacros(list);
    
    return list->_head;
}

IDCNode *IDCLinkedListGetObject(IDCLinkedList *list, void *object) {
    IDCReturnNULLMacros(list);
    uint64_t stepsCount = 1;
    uint64_t count = IDCLinkedListGetCount(list);
    
    IDCNode *node = IDCLinkedListGetHead(list);
    
    while (IDCNodeGetObject(node) != object) {
        node = IDCNodeGetNextNode(node);
        stepsCount++;
        IDCReturnNULLIfFirstValueIsBigger(stepsCount, count);
    }
    
    return node;
}

IDCNode *IDCLinkedListGetNodeAtNumber(IDCLinkedList *list, uint64_t number) {
    IDCReturnNULLMacros(list);
    if (number > IDCLinkedListGetCount(list)) {
        return NULL;
    }
    
    IDCNode *node = IDCLinkedListGetHead(list);
    uint64_t stepsCount = 1;
    
    if (number == 1) {
        return node;
    } else {
        while (stepsCount != number) {
            node = IDCNodeGetNextNode(node);
            stepsCount++;
        }
        
        return node;
    }
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
        IDCRetainSetter(node, NULL);
    } else {
        while (IDCNodeGetObject(node) != object) {
            nodeBefore = node;
            node = IDCNodeGetNextNode(node);
            stepsCount++;
            IDCReturnIfFirstValueIsBigger(stepsCount, count);
        }
        
        IDCNodeSetNextNode(nodeBefore, IDCNodeGetNextNode(node));
        IDCRetainSetter(node, NULL);
    }
    
    IDCLinkedListSetCount(list, count--);
}

void IDCLinkedListRemoveAllObjects(IDCLinkedList *list) {
    IDCReturnMacros(list);
    IDCLinkedListSetHead(list, NULL);
}