//
//  IDCLection5LinkedList.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 08.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#ifndef IDCLection5LinkedList_h
#define IDCLection5LinkedList_h

#include <stdio.h>
#include "IDCLection5Object.h"

typedef struct IDCLinkedList IDCLinkedList;

typedef struct IDCNode IDCNode;

struct IDCLinkedList {
    IDCObject _super;
    IDCNode *_head;
    uint64_t _count;
};

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

//methods with IDCLinkedList

extern
void __IDCLinkedListDeallocate(IDCLinkedList *list);

extern
IDCLinkedList *IDCLinkedListCreate(void);

extern
IDCNode *IDCLinkedListGetHead(IDCLinkedList *list);

extern
IDCNode *IDCLinkedListGetObject(IDCLinkedList *list, void *object);

extern
IDCNode *IDCLinkedListGetNodeAtNumber(IDCLinkedList *list, uint64_t number);

extern
void IDCLinkedListAddObject(IDCLinkedList *list, void *object);

extern
void IDCLinkedListRemoveObject(IDCLinkedList *list, void *object);

extern
void IDCLinkedListRemoveAllObjects(IDCLinkedList *list);

extern
void IDCLinkedListSetCount(IDCLinkedList *list, uint64_t count);

extern
uint64_t IDCLinkedListGetCount(IDCLinkedList *list);

#endif /* IDCLection5LinkedList_h */
