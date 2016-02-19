//
//  IDCLection5ObjectString.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 24.01.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "IDCLection5ObjectString.h"
#include "IDCLection5Macros.h"

#pragma mark -
#pragma mark Private Declaration

static
void IDCStringSetEmpty(IDCString *string);

#pragma mark -
#pragma mark Initialization and Deallocation

void __IDCStringDeallocate(IDCString *string) {
    IDCReturnMacros(string);
    IDCStringSetEmpty(string);
    __IDCObjectDeallocate(string);
    
}

IDCString *__IDCStringCreate(void) {
    IDCString *string = IDCObjectCreate(IDCString);
    
    return string;
}

IDCString *IDCStringCreateWithData(char *stringData) {
    IDCString *string = __IDCStringCreate();
    IDCStringSetStringData(string, stringData);
    
    return string;
}


#pragma mark -
#pragma mark Accessors

void IDCStringSetStringData (IDCString *string, char *stringData) {
    IDCReturnMacros(string)
    free(string->_stringData);
    
    if (stringData) {
        string->_stringData = strdup(stringData);
    } else {
        string->_stringData = NULL;
    }
}

char *IDCStringGetString (IDCString *string) {
    assert(string);
    
    return string->_stringData;
}

uint64_t IDCStringGetCount(IDCString *string) {
    uint64_t count = strlen(IDCStringGetString(string));
    
    return count;
}

#pragma mark-
#pragma marl Private Implementation

void IDCStringSetEmpty(IDCString *string) {
    IDCReturnMacros(string);
    
    IDCStringSetStringData(string, NULL);
    
}

#pragma mark - 
#pragma mark Public Implementation

void IDCPrintStringCount(IDCString *string) {
    IDCReturnMacros(string)
    
    printf("%llu \n", IDCStringGetCount(string));
    
}

void IDCStringPrintString(IDCString *string) {
    IDCReturnMacros(string)
    
    puts(IDCStringGetString(string));
    
}

void IDCStringIsEmpty(IDCString *string) {
    (0 != IDCStringGetCount(string))
                                    ? puts("String has some data\n")
                                    : puts("String is empty\n");
}

IDCString *IDCStringWithString(IDCString *string, IDCString *addString) {
    assert(string);
    if (addString == NULL) {
        return string;
    }
    
    uint64_t count = IDCStringGetCount(string);
    count += IDCStringGetCount(addString);
    
    char *temporaryString = calloc(count, sizeof(char));
    assert(temporaryString);
    
    strcat(temporaryString, IDCStringGetString(string));
    strcat(temporaryString, IDCStringGetString(addString));
    
    IDCString *newString = IDCStringCreateWithData(temporaryString);
    assert(newString);
    
    return newString;
}

bool IDCStringComparisonWithString(IDCString *firstString, IDCString *secondString) {
    assert(firstString);
    assert(secondString);
    
    bool stringsEqual = false;
    
    if (0 == strcmp(IDCStringGetString(firstString),
                    IDCStringGetString(secondString)))
    {
        stringsEqual = true;
    }
    
    return stringsEqual;
}

void IDCStringPrintComparisonResult(IDCString *firstString, IDCString *secondString) {
    bool comparisonResult = IDCStringComparisonWithString(firstString, secondString);
    printf("%d\n", comparisonResult);
    
}

uint64_t IDCStringGetCharacterIndex(IDCString *string, char character) {
    assert(string);
    
    uint64_t count = IDCStringGetCount(string);
    uint64_t index = 0;
    
    while (string->_stringData[index] != character) {
        if (index < count) {
            index++;
        } else {
            return UINT64_MAX;
        }
    }

    return index;
}

void IDCStringPrintCharacterIndex(IDCString *string, char character) {
    printf("%llu\n", IDCStringGetCharacterIndex(string, character));
}

IDCString *IDCStringChangeCharacter(IDCString *string, uint64_t index, char character) {
    string->_stringData[index] = character;
    
    return string;
}

void IDCStringPrintCharacterAtIndex(IDCString *string, uint64_t index) {
    IDCReturnMacros(string);
    
    char character = IDCStringGetString(string)[index];
    printf("%c\n", character);
}