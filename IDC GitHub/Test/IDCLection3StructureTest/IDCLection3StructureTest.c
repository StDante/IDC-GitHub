//
//  IDCLection3StructureTest.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 29.12.15.
//  Copyright © 2015 Alexandr Altukhov. All rights reserved.
//

#include <stdio.h>
#include <stddef.h>
#include "IDCLection3StructureTest.h"

void IDCPrintStructureIDCPatientSizeTest() {
    printf("Size of structure 'IDCPatient' is %lu\n", sizeof(IDCPatient));
    
}

void IDCPrintStructureIDCOptimisationPatientStructureSizeTest() {
    printf("Size of structure 'IDCOptimisationPatientStructure' is %lu\n",
           sizeof(IDCOptimisationPatientStructure));
    
}

void IDCPrintOffsetofStructureElementsTest() {
    char *elementOfStructure = "IDCPatient.lifeStatus";
    printf("Size of 'IDCPatient' structure before element %s is %lu\n",
                                            elementOfStructure,
                                            offsetof(IDCPatient, lifeStatus));
    
    elementOfStructure = "IDCPatient.hight";
    printf("Size of 'IDCPatient' structure before element %s is %lu\n",
                                            elementOfStructure,
                                            offsetof(IDCPatient, hight));
    
}