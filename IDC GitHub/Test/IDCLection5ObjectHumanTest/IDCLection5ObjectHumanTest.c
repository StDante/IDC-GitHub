//
//  IDCLection5ObjectHumanTest.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 12.01.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#include "IDCLection5ObjectHumanTest.h"

void IDCPrintObjectStringTest() {
    IDCString *firstTestString = IDCStringCreate("Adam");
    IDCPrintStringCount(firstTestString);
    IDCStringIsEmpty(firstTestString);
    IDCStringPrintString(firstTestString);
    
    IDCString *secondTestString = IDCStringCreate("Eva");
    IDCPrintStringCount(secondTestString);
    IDCStringIsEmpty(secondTestString);
    IDCStringPrintString(secondTestString);

    IDCString *stringWithString = IDCStringWithString(firstTestString, secondTestString);
    IDCPrintStringCount(stringWithString);
    IDCStringIsEmpty(stringWithString);
    IDCStringPrintString(stringWithString);

    IDCStringPrintComparisonResult(firstTestString, secondTestString);
    IDCStringPrintComparisonResult(firstTestString, firstTestString);
 
    IDCStringPrintCharacterIndex(firstTestString, (char)"m");

    IDCStringChangeCharacter(firstTestString, 0, (char)"B");
    IDCStringPrintCharacterAtIndex(firstTestString, 0);
    
    __IDCObjectRelease(firstTestString);
    __IDCObjectRelease(secondTestString);
    __IDCObjectRelease(stringWithString);
}