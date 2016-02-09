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

extern
void IDCLinkedListSetCount(IDCLinkedList *list, uint64_t count);

extern
void IDCLinkedListSetHead(IDCLinkedList *list, IDCNode *node);

extern
IDCNode *IDCLinkedListGetHead(IDCLinkedList *list);

#endif /* IDCLection5LinkedListPrivateHeader_h */
