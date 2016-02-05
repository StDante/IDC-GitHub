//
//  IDCLection5ObjectHumanTest.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 12.01.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#include "IDCLection5ObjectHumanTest.h"
#include "IDCLection5ObjectString.h"

void IDCPrintObjectDynamicArrayTest() {
    
    IDCDynamicArray *testArray = IDCDynamicArrayCreate();
    IDCString *object = IDCStringCreateWithData("test");
    int16_t index = 0;

    
    while (index < 10) {
        IDCDynamicArrayAddObject(testArray, object);
        index++;
    }
    
    uint64_t count = IDCDynamicArrayGetCount(testArray);
    
    for (int16_t index = 0; index < count; index++) {
        IDCDynamicArrayRemoveAllObjects(testArray);
    }
    
}

//void IDCPrintObjectStringTest() {
//    IDCString *firstTestString = IDCStringCreateWithData("Adam");
//    IDCPrintStringCount(firstTestString);
//    IDCStringIsEmpty(firstTestString);
//    IDCStringPrintString(firstTestString);
//    
//    IDCString *copyFirstTestString = IDCStringCreateWithData("Adam");
//    IDCStringPrintString(copyFirstTestString);
//    
//    IDCString *secondTestString = IDCStringCreateWithData("Eva");
//    IDCPrintStringCount(secondTestString);
//    IDCStringIsEmpty(secondTestString);
//    IDCStringPrintString(secondTestString);
//
//    IDCString *stringWithString = IDCStringWithString(firstTestString, secondTestString);
//    IDCPrintStringCount(stringWithString);
//    IDCStringIsEmpty(stringWithString);
//    IDCStringPrintString(stringWithString);
//
//    IDCStringPrintComparisonResult(firstTestString, copyFirstTestString);
//    IDCStringPrintComparisonResult(firstTestString, firstTestString);
// 
//    IDCStringPrintCharacterIndex(firstTestString, (char)"m");
//
//    IDCStringChangeCharacter(firstTestString, 0, (char)"B");
//    IDCStringPrintCharacterAtIndex(firstTestString, 0);
//    
//    IDCObjectRelease(firstTestString);
//    IDCObjectRelease(secondTestString);
//    IDCObjectRelease(stringWithString);
//}