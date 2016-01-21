//
//  IDCLection5ObjectHuman.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 12.01.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "IDCLection5Macros.h"
#include "IDCLection5Object.h"
#include "IDCLection5ObjectHuman.h"

static const uint8_t kIDCHumanReturnChildreIndexMax = UINT8_MAX;
static const uint8_t kIDCHumanChildrenLimit = 20;

#pragma mark -
#pragma mark Private Declarations

struct IDCHuman {
    IDCObject _super;
    
    char *_name; //+
    IDCHuman *_father; //+
    IDCHuman *_mother; //+
    IDCHuman *_partner; //+
    IDCGender _gender; //+
    uint8_t _age; //+
    IDCHuman *_children[kIDCHumanChildrenLimit]; //+
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
uint8_t IDCHumanReplaceOldestChild(IDCHuman *human);

static
uint8_t IDCHumanReturnIndexOfChild(IDCHuman *human, IDCHuman *child);

static
void IDCHumanRemoveAllChildren(IDCHuman *human);

#pragma mark -
#pragma mark Initialization and Deallocation

void __IDCHumanDeallocate(IDCHuman *human) {
        IDCHumanSetName(human, NULL);
        IDCHumanSetPartner(human->_partner, NULL);
        IDCHumanRemoveAllChildren(human);
        IDCHumanRemoveChild(IDCHumanGetFather(human), IDCHumanReturnIndexOfChild(human->_father, human));
        IDCHumanRemoveChild(IDCHumanGetMother(human), IDCHumanReturnIndexOfChild(human->_mother, human));
    
        free(human);
    
}


IDCHuman *IDCHumanCreateWithName(char *name) {
    IDCHuman *human = IDCObjectCreate(human);
    human->_name = name;
    
    return human;
}

#pragma mark -
#pragma mark Private Implementation

void IDCHumanRemoveAllChildren(IDCHuman *human) {
    while (0 != IDCHumanGetChildrenCount(human)) {
        int index = IDCHumanGetChildrenCount(human);
        if (human->_gender == kIDCMale) {
            IDCHumanSetFather(human->_children[index], NULL);
        } else {
            IDCHumanSetMother(human->_children[index], NULL);
        }
    }
    
}


uint8_t IDCHumanReturnIndexOfChild(IDCHuman *human, IDCHuman *child) {
    assert(human);
    assert(child);
    
    uint8_t index = 0;
    if (index < IDCHumanGetChildrenCount(human)) {
        while (child != human->_children[index]) {
            index++;
        }
        
        return index;
    }

    return kIDCHumanReturnChildreIndexMax;
}

//void IDCHumanSetFather(IDCHuman *human, IDCHuman *father) {
//    IDCReturnMacros(human);
//
//    human->_father = father;
//    __IDCHumanRetain(human);
//    
//}
//
//void IDCHumanSetMother(IDCHuman *human, IDCHuman *mother) {
//    IDCReturnMacros(human);
//
//    human->_mother = mother;
//    __IDCHumanRetain(human);
//    
//}

uint8_t IDCHumanReplaceOldestChild(IDCHuman *human) {
    uint8_t childIndex = 0;
    for (uint8_t index = 1; index < IDCHumanGetChildrenCount(human); index++) {
        if (IDCHumanGetAge(IDCHumanGetChild(human, childIndex))
            < IDCHumanGetAge(IDCHumanGetChild(human, index)))
        {
            childIndex = index;
        }
    }
    
    return childIndex;
}


#pragma mark -
#pragma mark Accessors

void IDCHumanSetName(IDCHuman *human, char *name) {
    IDCReturnMacros(human)
    human->_name = name;
    
}

char *IDCHumanGetName(IDCHuman *human) {
    assert(human);
    
    return human->_name;
}

IDCHuman *IDCHumanGetFather(IDCHuman *human) {
    assert(human);
    
    return human->_father;
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
    IDCReturnMacros(human)
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
    IDCReturnMacros(human)
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

void IDCHumanAddChild(IDCHuman *human, IDCHuman *child) {
    IDCReturnMacros(human);
    IDCReturnMacros(child);
    
    if (20 > IDCHumanGetChildrenCount(human)) {
        human->_children[IDCHumanGetChildrenCount(human)] = child;
    } else if (20 == IDCHumanGetChildrenCount(human)) {
        human->_children[IDCHumanReplaceOldestChild(human)] = child;
    }
    
    if (human->_gender == kIDCUnknownGender) {
        return;
    } else {
    (human->_gender == kIDCMale) ? IDCHumanSetFather(child, human)
                                 : IDCHumanSetMother(child, human);
    }
    
    __IDCHumanRetain(human);
    
}

uint8_t IDCHumanGetChildrenCount(IDCHuman *human) {
    assert(human);
    
    uint8_t index = 0;
    while (human->_children[index] != NULL) {
        index++;
    }

    return index;
}

void IDCHumanRemoveChild(IDCHuman *human, uint8_t index) {
    IDCReturnMacros(human);
    if (human->_gender == kIDCMale) {
        IDCHumanSetFather(human->_children[index], NULL);
    } else {
        IDCHumanSetMother(human->_children[index], NULL);
    }
    
    human->_children[index] = NULL;
    uint8_t indexReplace = index + 1;
    while (indexReplace < IDCHumanGetChildrenCount(human)) {
        human->_children[indexReplace - 1] = human->_children[indexReplace];
        indexReplace++;
    }
    
    __IDCHumanRelease(human);
    
}

IDCHuman *IDCHumanGetChild(IDCHuman *human, uint8_t childIndex) {
    assert(human);
    
    if (childIndex < IDCHumanGetChildrenCount(human)) {
        return human->_children[childIndex];
    } else {
        return NULL;
    }
    
}
//optimisation
void IDCHumanMarriage(IDCHuman *human, IDCHuman *partner) {
    IDCReturnMacros(human)
    IDCReturnMacros(partner)
    
    if (IDCHumanGetGender(human) == IDCHumanGetGender(partner)) {
        printf("Can't pair partners with same gender");
        return;
    } else if (kIDCUnknownGender == (IDCHumanGetGender(human) || IDCHumanGetGender(partner))) {
        printf("Can't pair partner with unknown gender");
        return;
    } else {

        IDCHumanDivorce(human);
        IDCHumanDivorce(partner);
        
        IDCHumanSetPartner(human, partner);
        IDCHumanSetPartner(partner, human);
        
        IDCGender genderType = IDCHumanGetGender(human);
        if (genderType == kIDCMale) {
            __IDCHumanRetain(human);
        } else {
            __IDCHumanRetain(partner);
        }
    }
    
}

void IDCHumanDivorce(IDCHuman *human) {
    IDCReturnMacros(human)
    
    IDCGender genderType = IDCHumanGetGender(human);
    if (genderType == kIDCMale) {
        __IDCHumanRelease(human);
    } else if (genderType == kIDCFemale) {
        __IDCHumanRelease(IDCHumanGetPartner(human));
    }
    
    IDCHumanSetPartner(IDCHumanGetPartner(human), NULL);
    IDCHumanSetPartner(human, NULL);
    
}
