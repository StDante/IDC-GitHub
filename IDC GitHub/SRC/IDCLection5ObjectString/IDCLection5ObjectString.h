//
//  IDCLection5ObjectString.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 24.01.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#ifndef IDCLection5ObjectString_h
#define IDCLection5ObjectString_h

#include <stdbool.h>
#include "IDCLection5Object.h"

typedef struct IDCString IDCString;

struct IDCString {
    IDCObject _super;
    char *_stringData;
};

extern
void __IDCStringDeallocate(IDCString *string);

extern
IDCString *__IDCStringCreate(void);

extern
IDCString *IDCStringCreateWithData(char *stringData);

extern
void IDCStringSetStringData (IDCString *string, char *setString);

extern
char *IDCStringGetString (IDCString *string);

extern
void IDCStringPrintString(IDCString *string);

extern
IDCString *IDCStringWithString(IDCString *string, IDCString *addString);

extern
uint64_t IDCStringGetCount(IDCString *string);

extern
void IDCPrintStringCount(IDCString *string);

extern
bool IDCStringComparisonWithString(IDCString *firstString, IDCString *secondString);

extern
void IDCStringPrintComparisonResult(IDCString *firstString, IDCString *secondString);

extern
void IDCStringIsEmpty(IDCString *string);

extern
uint64_t IDCStringGetCharacterIndex(IDCString *string, char character);

extern
void IDCStringPrintCharacterIndex(IDCString *string, char character);

extern
IDCString *IDCStringChangeCharacter(IDCString *string, uint64_t index, char character);

extern
void IDCStringPrintCharacterAtIndex(IDCString *string, uint64_t index);

#endif /* IDCLection5ObjectString_h */
