//
//  IDCLection5LinkedList.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 08.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#ifndef IDCLection5LinkedList_h
#define IDCLection5LinkedList_h


#include <stdbool.h>
#include "IDCLection5Node.h"

typedef struct IDCLinkedList IDCLinkedList;

struct IDCLinkedList {
    IDCObject _super;
    IDCNode *_head;
    uint64_t _count;
    uint64_t _mutationsCount;
};

extern
void __IDCLinkedListDeallocate(IDCLinkedList *list);

extern
IDCLinkedList *IDCLinkedListCreate(void);

extern
IDCLinkedList *IDCLinkedListCreateWithObject(void *object);

extern
void *IDCLinkedListGetObject(IDCLinkedList *list, void *object);

extern
void *IDCLinkedListGetFirstObject(IDCLinkedList *list);

extern
void IDCLinkedListAddObject(IDCLinkedList *list, void *object);

extern
void IDCLinkedListRemoveObject(IDCLinkedList *list, void *object);

extern
void IDCLinkedListRemoveAllObjects(IDCLinkedList *list);

extern
uint64_t IDCLinkedListGetCount(IDCLinkedList *list);

extern
bool IDCLinkedListContainsObject(IDCLinkedList *list, void *object);

#endif /* IDCLection5LinkedList_h */
