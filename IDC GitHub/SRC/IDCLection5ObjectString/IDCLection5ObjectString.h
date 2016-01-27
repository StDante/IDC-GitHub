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
    char *_string;
};

extern
void __IDCStringDeallocate(IDCString *string);

extern
IDCString *IDCStringCreate(char *string);

extern
void IDCStringSetString (IDCString *string, char *setString);

extern
char *IDCStringGetString (IDCString *string);

extern
void IDCStringPrintString(IDCString *string);

extern
IDCString *IDCStringWithString(IDCString *string, IDCString *addString);

extern
uint64_t IDCStringGetCount(IDCString *string);

extern
bool IDCStringComarisonWithString(IDCString *firstString, IDCString *secondString);

extern
void IDCStringIsEmpty(IDCString *string);

extern
uint64_t IDCStringGetCharacterIndex(IDCString *string, char character);

extern
IDCString *IDCStringChangeCharacter(IDCString *string, uint64_t index, char character);

#endif /* IDCLection5ObjectString_h */
