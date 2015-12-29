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

typedef struct {
    char *name;
    long long phoneNumber;
    double weight;
    float hight;
    int wealth;
    short age;
    short numberOfChildren;
    short iq;
    struct {
        bool sex : 1;
        bool lifeStatus : 1;
        bool familyStatus : 1;
        bool workStatus : 1;
        bool healthStatus : 1;
        bool treatmentStatus : 1;
    };
} IDCOptimisationPatientStructure;

void IDCPrintStructureIDCPatientSize() {
    printf("Size of structure 'IDCPatient' is %lu\n", sizeof(IDCPatient));
    
}

void IDCPrintStructureIDCOptimisationPatientStructureSize() {
    printf("Size of structure 'IDCOptimisationPatientStructure' is %lu\n",
                                    sizeof(IDCOptimisationPatientStructure));
    
}
