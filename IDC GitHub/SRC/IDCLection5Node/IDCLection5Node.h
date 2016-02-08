//
//  IDCLection5Node.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 08.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#ifndef IDCLection5Node_h
#define IDCLection5Node_h

#include "IDCLection5Object.h"

typedef struct IDCNode IDCNode;

struct IDCNode {
    IDCObject _super;
    IDCNode *_nextNode;
    void *_object;
};

//methods with IDCNode

extern
void __IDCNodeDeallocate(IDCNode *node);

extern
IDCNode *IDCNodeCreateWithObject(void *object);

extern
void IDCNodeSetObject(IDCNode *node, void *object);

extern
void *IDCNodeGetObject(IDCNode *node);

extern
void IDCNodeSetNextNode(IDCNode *node, IDCNode *nextNode);

extern
IDCNode *IDCNodeGetNextNode(IDCNode *node);

#endif /* IDCLection5Node_h */
