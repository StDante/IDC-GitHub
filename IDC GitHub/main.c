//
//  main.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 28.12.15.
//  Copyright © 2015 Alexandr Altukhov. All rights reserved.
//

#include <stdio.h>
#include "IDCLection2MacrosTest.h"
#include "IDCLection3StructureTest.h"

int main(int argc, const char * argv[]) {
    printf("Lection 2 Macros\n");
    IDCPrintMacrosWithAnyTypeAndValue();
    
    printf("\nLection 3 Stucture\n");
    IDCPrintStructureIDCPatientSizeTest();
    IDCPrintStructureIDCOptimisationPatientStructureSizeTest();
    IDCPrintOffsetofStructureElementsTest();
    
    return 0;
}
