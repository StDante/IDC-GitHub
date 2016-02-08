//
//  IDCLection5LinkedList.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 08.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#ifndef IDCLection5LinkedList_h
#define IDCLection5LinkedList_h

#include "IDCLection5Node.h"

typedef struct IDCLinkedList IDCLinkedList;

struct IDCLinkedList {
    IDCObject _super;
    IDCNode *_head;
    uint64_t _count;
};

extern
void __IDCLinkedListDeallocate(IDCLinkedList *list);

extern
IDCLinkedList *IDCLinkedListCreate(void);

extern
IDCNode *IDCLinkedListGetHead(IDCLinkedList *list);

extern
IDCNode *IDCLinkedListGetObject(IDCLinkedList *list, void *object);

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
