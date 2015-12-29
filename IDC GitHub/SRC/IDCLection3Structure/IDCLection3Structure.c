//
//  IDCLection3Structure.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 29.12.15.
//  Copyright © 2015 Alexandr Altukhov. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include "IDCLection3Structure.h"

typedef struct {
    bool sex;
    bool lifeStatus;
    bool familyStatus;
    bool workStatus;
    bool healthStatus;
    bool treatmentStatus;
    float hight;
    int wealth;
    long long phoneNumber;
    short age;
    short numberOfChildren;
    short iq;
    double weight;
    char *name;
} IDCPatient;

void IDCPrintStructureIDCPatientSize() {
    printf("Size of structure 'IDCPatient' is %lu\n", sizeof(IDCPatient));
    
}