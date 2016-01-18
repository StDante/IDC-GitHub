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
#include <assert.h>
#include <string.h>
#include "IDCLection5ObjectHuman.h"

#pragma mark -
#pragma mark Private Declarations

struct IDCHuman{
    char *_name; //+
    IDCHuman *_father; //+
    IDCHuman *_mother; //+
    IDCHuman *_partner; //+
    IDCGender _gender; //+
    uint8_t _age; //+
    uint8_t _childrenCount; //+
    uint8_t _referenceCount; //+
    IDCHuman *_children[20]; //+
};

static
void __IDCHumanDeallocate(IDCHuman *human);

static
IDCHuman *__IDCHumanCreate(void);

static
void __IDCHumanRetain(IDCHuman *human);

static
void __IDCHumanRelease(IDCHuman *human);

static
void IDCHumanSetPartner(IDCHuman *human, IDCHuman *partner);

static
void IDCHumanSetFather(IDCHuman *human, IDCHuman *father);

static
void IDCHumanSetMother(IDCHuman *human, IDCHuman *mother);

static
int IDCReplaceOldestChild(IDCHuman *human);

#pragma mark -
#pragma mark Private Implementation

void __IDCHumanRetain(IDCHuman *human) {
    human->_referenceCount++;
}

void __IDCHumanRelease(IDCHuman *human) {
    human->_referenceCount--;
}

#pragma mark -
#pragma mark Initialization and Deallocation

void __IDCHumanDeallocate(IDCHuman *human) {
    if (0 == human->_referenceCount) {
        IDCHumanSetPartner(human->_partner, NULL);
//        while (0 != human->_childrenCount) {
//            int index = human->_childrenCount;
//            if (human->_gender == kIDCMale) {
//                IDCHumanSetFather(human->_children[index - 1], NULL);
//            } else {
//                IDCHumanSetMother(human->_children[index - 1], NULL);
//            }
//            index--;
//            human->_childrenCount--;
//        }
//  How I can return index of element in array if I know value of element?
        IDCHumanRemoveChild(IDCHumanGetFather(human), (uint8_t)human);
        IDCHumanRemoveChild(IDCHumanGetMother(human), (uint8_t)human);
    }
        
        free(human);
}

IDCHuman *__IDCHumanCreate(void) {
    IDCHuman *human = calloc(1, sizeof(IDCHuman));
    assert(human);
    human->_referenceCount = 1;

    return human;
}

IDCHuman *IDCHumanCreateWithName(char *name) {
    IDCHuman *human = __IDCHumanCreate();
    human->_name = name;
    
    return human;
}

#pragma mark -
#pragma mark Accessors

void IDCHumanSetName(IDCHuman *human, char *name) {
    IDCCheckOnNull(human)
    human->_name = name;
}

char *IDCHumanGetName(IDCHuman *human) {
    assert(human);
    
    return human->_name;
}

void IDCHumanSetFather(IDCHuman *human, IDCHuman *father) {
    IDCCheckOnNull(human);
    IDCCheckOnNull(father);
    human->_father = father;
}

IDCHuman *IDCHumanGetFather(IDCHuman *human) {
    assert(human);
    
    return human->_father;
}

void IDCHumanSetMother(IDCHuman *human, IDCHuman *mother) {
    IDCCheckOnNull(human);
    IDCCheckOnNull(mother);
    human->_mother = mother;
}

IDCHuman *IDCHumanGetMother(IDCHuman *human) {
    assert(human);
    
    return human->_mother;
}

void IDCHumanSetPartner(IDCHuman *human, IDCHuman *partner) {
    if (human->_partner != partner) {
        human->_partner = partner;
    }
    
}

IDCHuman *IDCHumanGetPartner(IDCHuman *human) {
    assert(human);
    
    return human->_partner;
}

void IDCHumanSetGender(IDCHuman *human, IDCGender genderType) {
    IDCCheckOnNull(human)
    human->_gender = genderType;
    if ((genderType != kIDCMale) || (genderType != kIDCFemale)) {
        genderType = kIDCUnknownGender;
    }
    
}

IDCGender IDCHumanGetGender(IDCHuman *human) {
    assert(human);
    
    return human->_gender;
}

void IDCHumanSetAge(IDCHuman *human, uint8_t age) {
    IDCCheckOnNull(human)
    human->_age = age;
}

uint8_t IDCHumanGetAge(IDCHuman *human) {
    assert(human);
    
    return human->_age;
}

bool IDCHumanGetMarried(IDCHuman *human) {
    assert(human);
    
    return IDCHumanGetPartner(human) ? true : false;
}

int IDCReplaceOldestChild(IDCHuman *human) {
    uint8_t index = 0;
    uint8_t increment = 1;
    uint8_t indexLast = index + increment;
    while (19 >= indexLast) {
        if (human->_children[index]->_age <= human->_children[index + increment]->_age) {
            index = index + increment;
            increment = 1;
        } else {
            increment++;
        }
    }
    
    return index;
}

void IDCHumanAddChild(IDCHuman *human, IDCHuman *child) {
    IDCCheckOnNull(human);
    IDCCheckOnNull(child);
    
    if (20 > human->_childrenCount) {
        human->_children[human->_childrenCount] = child;
        human->_childrenCount++;
    } else if (20 == human->_childrenCount) {
        human->_children[IDCReplaceOldestChild(human)] = child;
    }
    
    if (human->_gender == kIDCUnknownGender) {
        return;
    } else {
    (human->_gender == kIDCMale) ? IDCHumanSetFather(child, human)
                                 : IDCHumanSetMother(child, human);
    }
    
    __IDCHumanRetain(human);
    
}

void IDCHumanRemoveChild(IDCHuman *human, uint8_t index) {
    IDCCheckOnNull(human);
    if (human->_gender == kIDCMale) {
        IDCHumanSetFather(human->_children[index], NULL);
    } else {
        IDCHumanSetMother(human->_children[index], NULL);
    }
    
    human->_children[index] = NULL;
    uint8_t indexReplace = index + 1;
    while (indexReplace < human->_childrenCount) {
        human->_children[indexReplace - 1] = human->_children[indexReplace];
        indexReplace++;
    }
    
    human->_childrenCount--;
    __IDCHumanRelease(human);
}

IDCHuman *IDCHumanGetChild(IDCHuman *human, uint8_t childIndex) {
    assert(human);
    
    if (childIndex < human->_childrenCount) {
        return human->_children[childIndex];
    } else {
        return NULL;
    }
}

void IDCHumanMarriage(IDCHuman *human, IDCHuman *partner) {
    IDCCheckOnNull(human)
    IDCCheckOnNull(partner)
    
    if (IDCHumanGetGender(human) == IDCHumanGetGender(partner)) {
        printf("Can't pair partners with same gender");
        return;
    } else if (kIDCUnknownGender == (IDCHumanGetGender(human) || IDCHumanGetGender(partner))) {
        printf("Can't pair partner with unknown gender");
        return;
    } else {
        IDCHumanSetPartner(human, partner);
        IDCHumanSetPartner(partner, human);
        
        IDCGender genderType = IDCHumanGetGender(human);
        if (genderType == kIDCMale) {
            __IDCHumanRetain(human);
        } else if (genderType == kIDCFemale) {
            __IDCHumanRetain(partner);
        }
    }
    
}

void IDCHumanDivorce(IDCHuman *human, IDCHuman *partner) {
    IDCCheckOnNull(human)
    IDCCheckOnNull(partner)
    
    IDCHumanSetPartner(partner, NULL);
    IDCHumanSetPartner(human, NULL);
    
    IDCGender genderType = IDCHumanGetGender(human);
    if (genderType == kIDCMale) {
        __IDCHumanRelease(human);
    } else if (genderType == kIDCFemale) {
        __IDCHumanRelease(partner);
    }
    
}
