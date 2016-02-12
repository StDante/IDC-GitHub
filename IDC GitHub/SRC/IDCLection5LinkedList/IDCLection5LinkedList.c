//
//  IDCLection5LinkedList.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 08.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#include "IDCLection5LinkedList.h"
#include "IDCLection5Enumerator.h"
#include "IDCLection5LinkedListPrivateHeader.h"

#pragma mark -
#pragma mark Private Declaration

static
void IDCLinkedListSetFirstObject(IDCLinkedList *list, void *object);

static
void IDCLinkedListAddNode(IDCLinkedList *list, IDCNode *node);

static
void IDCLinkedListRemoveNode(IDCLinkedList *list, IDCNode *node);

static
void IDCLinkedListSetMutableCount(IDCLinkedList *list, uint64_t mutableCount);

#pragma mark -
#pragma mark Initialization and Deallocation

void __IDCLinkedListDeallocate(IDCLinkedList *list) {
    IDCLinkedListSetHead(list, NULL);
    
    __IDCObjectDeallocate(list);
}

IDCLinkedList *IDCLinkedListCreate(void) {
    IDCLinkedList *list = IDCObjectCreate(IDCLinkedList);
    IDCLinkedListSetHead(list, NULL);
    IDCLinkedListSetMutableCount(list, 0);
    IDCLinkedListSetCount(list, 0);
    
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

void IDCLinkedListSetFirstObject(IDCLinkedList *list, void *object) {
    IDCReturnMacros(list);
    
    if (IDCLinkedListContainsObject(list, object)) {
        IDCNode *node = IDCLinkedListGetHead(list);
        while (IDCNodeGetObject(node) != object) {
            node = IDCNodeGetNextNode(node);
        }
        
        IDCLinkedListSetHead(list, node);
    }
}

void *IDCLinkedListGetFirstObject(IDCLinkedList *list) {
    return IDCNodeGetObject(IDCLinkedListGetHead(list));
}

void *IDCLinkedListGetObject(IDCLinkedList *list, void *object) {
    IDCReturnNULLMacros(list);
    
    if (IDCLinkedListContainsObject(list, object)) {
        IDCNode *node = IDCLinkedListGetHead(list);
    
        while (IDCNodeGetObject(node) != object) {
            node = IDCNodeGetNextNode(node);
        }
    
        return IDCNodeGetObject(node);
    }
    
    return NULL;
}

void IDCLinkedListSetMutableCount(IDCLinkedList *list, uint64_t mutableCount) {
    IDCReturnMacros(list);
    
    list->_mutableCount = mutableCount;
}


uint64_t IDCLinkedListGetMutableCount(IDCLinkedList *list) {
    IDCReturnValueMacros(list, 0);
    
    return list->_mutableCount;
}

void IDCLinkedListSetCount(IDCLinkedList *list, uint64_t count) {
    IDCReturnMacros(list);
    
    list->_count = count;
    IDCLinkedListSetMutableCount(list, IDCLinkedListGetMutableCount(list) + 1);
}

uint64_t IDCLinkedListGetCount(IDCLinkedList *list) {
    assert(list);
    
    return list->_count;
}

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
    
    IDCNode *node = IDCNodeCreateWithObject(object);
    IDCLinkedListAddNode(list, node);
    IDCObjectRelease(node);
}

void IDCLinkedListRemoveObject(IDCLinkedList *list, void *object) {
    IDCReturnMacros(list);
    
    IDCNode *node = IDCLinkedListGetHead(list);
    IDCNode *nextNode = IDCNodeGetNextNode(node);
    
    while (NULL != node) {
        if (object == IDCNodeGetObject(node)) {
            IDCLinkedListRemoveNode(list, node);
        }
        
        node = nextNode;
        nextNode = IDCNodeGetNextNode(node);
    }
}

void IDCLinkedListRemoveAllObject(IDCLinkedList *list) {
    IDCLinkedListSetHead(list, NULL);
    IDCLinkedListSetCount(list, 0);
}

#pragma mark -
#pragma mark Private Implementation

void IDCLinkedListAddNode(IDCLinkedList *list, IDCNode *node) {
    IDCReturnMacros(list);
    
    IDCNodeSetNextNode(node, IDCLinkedListGetHead(list));
    IDCLinkedListSetHead(list, node);
    IDCLinkedListSetCount(list, IDCLinkedListGetCount(list) + 1);
}

void IDCLinkedListRemoveNode(IDCLinkedList *list, IDCNode *node) {
    IDCReturnMacros(list);
    IDCReturnMacros(node);
    IDCNode *firstNode = IDCLinkedListGetHead(list);
    IDCNode *secondNode = IDCNodeGetNextNode(firstNode);
    if (firstNode == node) {
        IDCLinkedListSetHead(list, secondNode);
    } else {
        IDCEnumerator *enumerator = IDCEnumeratorCreateWithList(list);
        while (IDCEnumeratorIsValid(enumerator, list) == true) {
            firstNode = IDCEnumeratorGetCurrentNode(enumerator);

        }

    }
    
    IDCObjectRelease(enumerator);
//    if (node == firstNode) {
//        IDCLinkedListSetHead(list, secondNode);
//    } else {
//        while (secondNode != node) {
//            firstNode = secondNode;
//            secondNode = IDCNodeGetNextNode(secondNode);
//        }
//        
//        IDCNodeSetNextNode(firstNode, IDCNodeGetNextNode(secondNode));
//    }
//    
//    IDCLinkedListSetCount(list, IDCLinkedListGetCount(list) - 1);
}

