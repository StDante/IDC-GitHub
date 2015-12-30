//
//  IDCLection3Structure.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 29.12.15.
//  Copyright © 2015 Alexandr Altukhov. All rights reserved.
//

#include <stdio.h>
#include "IDCLection3Structure.h"

void IDCPrintStructureIDCPatientSize() {
    printf("Size of structure 'IDCPatient' is %lu\n", sizeof(IDCPatient));
    
}

void IDCPrintStructureIDCOptimisationPatientStructureSize() {
    printf("Size of structure 'IDCOptimisationPatientStructure' is %lu\n",
                                    sizeof(IDCOptimisationPatientStructure));
    
}
