//
//  IDCLection5LinkedListPrivateHeader.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 08.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#ifndef IDCLection5LinkedListPrivateHeader_h
#define IDCLection5LinkedListPrivateHeader_h

#include "IDCLection5LinkedList.h"

typedef struct {
    void *previousNode;
    void *node;
    void *object;
}IDCContext;

typedef bool (*IDCLinkedListNodeComparison)(IDCNode *node, IDCContext *context);

extern
void IDCLinkedListSetCount(IDCLinkedList *list, uint64_t count);

extern
void IDCLinkedListSetHead(IDCLinkedList *list, IDCNode *node);

extern
IDCNode *IDCLinkedListGetHead(IDCLinkedList *list);

extern
uint64_t IDCLinkedListGetMutationsCount(IDCLinkedList *list);

extern
IDCNode *IDCLinkedListGetNodeWithContext(IDCLinkedList *list,
                                         IDCLinkedListNodeComparison comparator,
                                         IDCContext *context);

extern
bool IDCLinkedListNodeContainsObject(IDCNode *node, IDCContext *context);

extern
bool IDCLinkedListObjectIsEqualSubsequentObject(IDCContext *context);


#endif /* IDCLection5LinkedListPrivateHeader_h */
