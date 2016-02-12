//
//  IDCLection5Enumerator.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 10.02.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#ifndef IDCLection5Enumerator_h
#define IDCLection5Enumerator_h

#include "IDCLection5LinkedListPrivateHeader.h"

typedef struct IDCEnumerator IDCEnumerator;

struct IDCEnumerator {
    IDCObject _super;
    IDCLinkedList *_list;
    IDCNode *_currentNode;
    uint64_t _mutableCount;
};

extern
void __IDCEnumeratorDeallocate(IDCEnumerator *enumerator);

extern
IDCEnumerator *IDCEnumeratorCreateWithList(IDCLinkedList *list);

extern
IDCLinkedList *IDCEnumeratorGetList(IDCEnumerator *enumerator);

extern
void IDCEnumeratorSetCurrentNode(IDCEnumerator *enumerator, IDCNode *node);

extern
IDCNode *IDCEnumeratorGetCurrentNode(IDCEnumerator *enumerator);

extern
bool IDCEnumeratorIsValid(IDCEnumerator *enumerator, IDCLinkedList *list);

#endif /* IDCLection5Enumerator_h */
