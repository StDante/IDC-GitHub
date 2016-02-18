//
//  IDCLection3Structure.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 29.12.15.
//  Copyright © 2015 Alexandr Altukhov. All rights reserved.
//

#ifndef IDCLection3Structure_h
#define IDCLection3Structure_h

#include <stdbool.h>

#pragma mark -
#pragma mark Structures

typedef struct {
    bool sex;
    bool deadOrAlive;
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
        bool deadOrAlive : 1;
        bool familyStatus : 1;
        bool workStatus : 1;
        bool healthStatus : 1;
        bool treatmentStatus : 1;
    };
} IDCOptimisationPatientStructure;

typedef struct {
    char *name;
    long long phoneNumber;
    double weight;
    float hight;
    int wealth;
    short age;
    short numberOfChildren;
    short iq;
    union {
        struct {
        bool sex : 1;
        bool deadOrAlive : 1;
        bool familyStatus : 1;
        bool workStatus : 1;
        bool healthStatus : 1;
        bool treatmentStatus : 1;
        };
        
        char boolOrder;
    };
} IDCPatientWithUnion;

#pragma mark -
#pragma mark Functions

#endif /* IDCLection3Structure_h */
