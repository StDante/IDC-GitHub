//
//  IDCLection5LinkedList.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 08.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#include "IDCLection5LinkedList.h"
#include "IDCLection5Enumerator.h"

#pragma mark -
#pragma mark Private Declaration

static
void IDCLinkedListSetFirstObject(IDCLinkedList *list, void *object);

static
void IDCLinkedListAddNode(IDCLinkedList *list, IDCNode *node);

static
void IDCLinkedListRemoveNode(IDCLinkedList *list, IDCNode *node);

static
void IDCLinkedListSetMutationsCount(IDCLinkedList *list, uint64_t mutationsCount);

#pragma mark -
#pragma mark Initialization and Deallocation

void __IDCLinkedListDeallocate(IDCLinkedList *list) {
    IDCLinkedListSetHead(list, NULL);
    
    __IDCObjectDeallocate(list);
}

IDCLinkedList *IDCLinkedListCreate(void) {
    IDCLinkedList *list = IDCObjectCreate(IDCLinkedList);
    IDCLinkedListSetHead(list, NULL);
    IDCLinkedListSetMutationsCount(list, 0);
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

void IDCLinkedListSetMutationsCount(IDCLinkedList *list, uint64_t mutationsCount) {
    IDCReturnMacros(list);
    
    list->_mutationsCount = mutationsCount;
}


uint64_t IDCLinkedListGetMutationsCount(IDCLinkedList *list) {
    IDCReturnValueMacros(list, 0);
    
    return list->_mutationsCount;
}

void IDCLinkedListSetCount(IDCLinkedList *list, uint64_t count) {
    IDCReturnMacros(list);
    
    list->_count = count;
    IDCLinkedListSetMutationsCount(list, IDCLinkedListGetMutationsCount(list) + 1);
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
    
    IDCContext *context = calloc(1, sizeof(IDCContext));
    context->object = object;
    
    IDCNode *node = IDCLinkedListGetNodeWithContext(list, IDCLinkedListNodeContainsObject, context);
    
    free(context);
    return node;
}

void IDCLinkedListAddObject(IDCLinkedList *list, void *object) {
    IDCReturnMacros(list);
    
    IDCNode *node = IDCNodeCreateWithObject(object);
    IDCLinkedListAddNode(list, node);
    IDCObjectRelease(node);
}

void IDCLinkedListRemoveObject(IDCLinkedList *list, void *object) {
    if (IDCLinkedListContainsObject(list, object)) {
        IDCContext *context = calloc(1, sizeof(IDCContext));
        context->object = object;
        
        IDCNode *node = IDCLinkedListGetNodeWithContext(list,
                                                        IDCLinkedListNodeContainsObject,
                                                        context);
        if (node == IDCLinkedListGetHead(list)) {
            IDCLinkedListSetHead(list, IDCNodeGetNextNode(node));
        }
        
        IDCNodeSetNextNode(context->previousNode, IDCNodeGetNextNode(node));
        
        free(context);
        IDCLinkedListSetCount(list, IDCLinkedListGetCount(list) - 1);
    } else {
        printf("There no such object in list");
        
        return;
    }
}

void IDCLinkedListRemoveAllObjects(IDCLinkedList *list) {
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

IDCNode *IDCLinkedListGetNodeWithContext(IDCLinkedList *list,
                                         IDCLinkedListNodeComparison comparator,
                                         IDCContext *context)
{
    IDCReturnNULLMacros(list);
    
    IDCNode *node = NULL;
    
    IDCEnumerator *enumerator = IDCEnumeratorCreateWithList(list);
    while (IDCEnumeratorIsValid(enumerator, list)) {
        node = IDCEnumeratorGetNextNode(enumerator);
        context->node = node;
        
        if (IDCLinkedListNodeContainsObject(node, context)) {
            break;
        } else {
            context->previousNode = node;
        }
    }
    
    IDCObjectRelease(enumerator);
    
    return node;
}

bool IDCLinkedListNodeContainsObject(IDCNode *node, IDCContext *context) {
    return node && IDCNodeGetObject(node) == context->object;
}

bool IDCLinkedListObjectIsEqualSubsequentObject(IDCContext *context) {
    return IDCNodeGetObject(context->previousNode) == context->object;
}