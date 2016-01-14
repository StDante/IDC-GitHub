//
//  IDCLection5ObjectHuman.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 12.01.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "IDCLection5ObjectHuman.h"

#pragma mark -
#pragma mark Private Declarations

typedef enum {
    kIDCUnknownGender,
    kIDCMale,
    kIDCFemale
} IDCGender;

struct IDCHuman{
    char *_name;
    IDCHuman *_father;
    IDCHuman *_mother;
    IDCHuman *_partner;
    IDCGender _gender;
    uint8_t _age;
    uint8_t _childrenCount;
    uint8_t _releaseCount;
    bool _isMarried;
    IDCHuman *_children[20];
};

static
void IDCHumanDeallocate(IDCHuman *human);

static
IDCHuman *IDCHumanCreate(void);

static
void IDCHumanSetName(IDCHuman *human, char *name);

#pragma mark -
#pragma mark Initialization and Deallocation

void IDCHumanDeallocate(IDCHuman *human) {
    free(human);
}

IDCHuman *IDCHumanCreate(void) {
    IDCHuman *human = calloc(1, sizeof(IDCHuman));
    IDCCheckOnNull(human);
    human->_releaseCount++;

    return human;
}

void IDCHumanSetName(IDCHuman *human, char *name) {
    human->_name = name;
}

IDCHuman *IDCHumanCreateWithName(char *name) {
    IDCHuman *human = IDCHumanCreate();
    human->_name = name;
    
    return human;
}

void IDCReleaseHuman(IDCHuman *human) {
    if (0 == human->_releaseCount) {
        human->_father = NULL;
        human->_mother = NULL;
        human->_partner = NULL;
        while (0 != human->_childrenCount) {
            int index = human->_childrenCount;
            human->_children[index - 1] = NULL;
            human->_childrenCount--;
        }
        IDCHumanDeallocate(human);
        
    }
}
