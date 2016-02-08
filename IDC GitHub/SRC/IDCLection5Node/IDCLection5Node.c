//
//  IDCLection5Node.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 08.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#include "IDCLection5Node.h"

#pragma mark -
#pragma mark Private Declaration

static
IDCNode *IDCNodeCreate(void);

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