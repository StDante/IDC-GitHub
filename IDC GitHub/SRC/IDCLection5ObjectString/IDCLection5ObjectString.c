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
void IDCStringSetStringEmpty(IDCString *string);

#pragma mark -
#pragma mark Initialization and Deallocation

void __IDCStringDeallocate(IDCString *string) {
    IDCReturnMacros(string);
    IDCStringSetString(string, NULL);
    __IDCObjectDeallocate(string);
    
}

IDCString *IDCStringCreate(char *string) {
    IDCString *newString = IDCObjectCreate(IDCString);
    assert(newString);
    
    return newString;
}

#pragma mark -
#pragma mark Accessors

void IDCStringSetString (IDCString *string, char *setString) {
    IDCReturnMacros(string)
    free(string->_string);
    
    if (setString) {
        string->_string = strdup(setString);
    } else {
        string->_string = NULL;
    }
    
}

char *IDCStringGetString (IDCString *string) {
    assert(string);
    
    return string->_string;
}

uint64_t IDCStringGetCount(IDCString *string) {
    uint64_t count = strlen(IDCStringGetString(string));
    
    return count;
}

#pragma mark-
#pragma marl Private Implementation

void IDCStringSetStringEmpty(IDCString *string) {
    IDCReturnMacros(string);
    
    IDCStringSetString(string, NULL);
    
}

#pragma mark - 
#pragma mark Public Implementation

void IDCStringPrintString(IDCString *string) {
    IDCReturnMacros(string)
    
    puts(IDCStringGetString(string));
    
}

void IDCStringIsEmpty(IDCString *string) {
    (0 != IDCStringGetCount(string))
                                    ? puts("String has some data")
                                    : puts("String is empty");
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
    
    IDCString *newString = IDCStringCreate(temporaryString);
    assert(newString);
    
    return newString;
}

bool IDCStringComarisonWithString(IDCString *firstString, IDCString *secondString) {
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

uint64_t IDCStringGetCharacterIndex(IDCString *string, char character) {
    uint64_t count = IDCStringGetCount(string);
    for (uint64_t index = 0; IDCStringGetString(string)[index] != character; index++) {
        if (index > count) {
            char *noChar = "There is no such character in string";
            
            return (uint64_t)noChar;
        }
    }
    
    return (uint64_t)index - 1;
}

IDCString *IDCStringChangeCharacter(IDCString *string, uint64_t index, char character) {
    IDCStringGetString(string)[index] = character;
    
    return string;
}
