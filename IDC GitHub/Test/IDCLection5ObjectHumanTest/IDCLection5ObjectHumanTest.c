//
//  IDCLection5ObjectHumanTest.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 12.01.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#include "IDCLection5ObjectHumanTest.h"

void IDCPrintObjectStringTest() {
    IDCString *name = IDCStringCreate("Adam");
    IDCStringPrintString(name);
    __IDCObjectRelease(name);
//    extern
//    void IDCStringSetString (IDCString *string, char *setString);
//    
//    extern
//    char *IDCStringGetString (IDCString *string);
//    

//
//    extern
//    IDCString *IDCStringWithString(IDCString *string, IDCString *addString);
//    
//    extern
//    uint64_t IDCStringGetCount(IDCString *string);
//    
//    extern
//    bool IDCStringComarisonWithString(IDCString *firstString, IDCString *secondString);
//    
//    extern
//    void IDCStringIsEmpty(IDCString *string);
//    
//    extern
//    uint64_t IDCStringGetCharacterIndex(IDCString *string, char character);
//    
//    extern
//    IDCString *IDCStringChangeCharacter(IDCString *string, uint64_t index, char character);
}

//void IDCPrintHumanTest() {
//    IDCString *manName = IDCStringCreate("Adam");
//    IDCHuman *man = IDCHumanCreateWithNameAndGender(manName, kIDCMale);
//    
//}
