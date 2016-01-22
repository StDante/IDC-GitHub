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

static const uint8_t kIDCHumanReturnChildrenIndexMax = UINT8_MAX;
static const uint8_t kIDCHumanChildrenLimit = 20;

#pragma mark -
#pragma mark Private Declarations

struct IDCHuman {
    IDCObject _super;
    
    char *_name;
    IDCHuman *_father;
    IDCHuman *_mother;
    IDCHuman *_partner;
    IDCGender _gender;
    uint8_t _age;
    IDCHuman *_children[kIDCHumanChildrenLimit];
};

static
void __IDCHumanDeallocate(IDCHuman *human);

static
IDCHuman *__IDCHumanCreateWithNameAndGender(char *name, IDCGender gender);

static
void IDCHumanSetPartner(IDCHuman *human, IDCHuman *partner);

static
void __IDCHumanSetFather(IDCHuman *human, IDCHuman *father);

static
void __IDCHumanSetMother(IDCHuman *human, IDCHuman *mother);

static
void __IDCHumanSetParents(IDCHuman *human, IDCHuman *father, IDCHuman *mother);

static
uint8_t IDCHumanOldestChildIndex(IDCHuman *human);

static
uint8_t IDCHumanIndexOfChild(IDCHuman *human, IDCHuman *child);

static
void __IDCHumanReplaceChildrenHigherInArray(IDCHuman *human, uint8_t index);

static
void IDCHumanRemoveAllChildren(IDCHuman *human);

#pragma mark -
#pragma mark Initialization and Deallocation

void __IDCHumanDeallocate(IDCHuman *human) {
        IDCHumanSetName(human, NULL);
        IDCHumanDivorce(human);
        IDCHumanRemoveAllChildren(human);
    
        __IDCObjectDeallocate(human);
    
}


IDCHuman *__IDCHumanCreateWithNameAndGender(char *name, IDCGender gender) {
    IDCHuman *human = IDCObjectCreate(IDCHuman);
    human->_name = name;
    
    return human;
}

IDCHuman *IDCHumanCreateWithParentsAndNameAndGender(char *name,
                                           IDCHuman *father,
                                           IDCHuman *mother)
{
    IDCHuman *human = __IDCHumanCreateWithNameAndGender(name, arc4random_uniform(2) + 1);
    __IDCHumanSetParents(human, father, mother);
    
    return human;
}

#pragma mark -
#pragma mark Private Implementation

uint8_t IDCHumanIndexOfChild(IDCHuman *human, IDCHuman *child) {
    assert(human);
    assert(child);
    
    uint8_t index = 0;
    if (index < IDCHumanGetChildrenCount(human)) {
        while (child != IDCHumanGetChild(human, index)) {
            index++;
        }
        
        return index;
    }
    
    return kIDCHumanReturnChildrenIndexMax;
}

uint8_t IDCHumanOldestChildIndex(IDCHuman *human) {
    assert(human);
    
    uint8_t childIndex = 0;
    uint8_t index = 1;
    uint8_t oldestChildAge = IDCHumanGetAge(IDCHumanGetChild(human, childIndex));
    uint8_t childAge = IDCHumanGetAge(IDCHumanGetChild(human, index));
    for (uint8_t index; index < IDCHumanGetChildrenCount(human); index++) {
        if (oldestChildAge < childAge) {
            childIndex = index;
        }
    }
    
    return childIndex;
}

void __IDCHumanReplaceChildrenHigherInArray(IDCHuman *human, uint8_t index) {
    uint8_t indexReplace = index + 1;
    while (indexReplace < IDCHumanGetChildrenCount(human)) {
        human->_children[indexReplace - 1] = human->_children[indexReplace];
        indexReplace++;
    }
    
}

void IDCHumanRemoveAllChildren(IDCHuman *human) {
    uint8_t index = IDCHumanGetChildrenCount(human);
    
    while (0 != index) {
        IDCHumanRemoveChild(human, --index);
    }
    
}

#pragma mark -
#pragma mark Accessors

void IDCHumanSetName(IDCHuman *human, char *name) {
    IDCReturnMacros(human)
    
    if (name) {
        human->_name = strdup(name);
    } else {
        human->_name = NULL;
    }
    
}

char *IDCHumanGetName(IDCHuman *human) {
    assert(human);
    
    return human->_name;
}

void __IDCHumanSetFather(IDCHuman *human, IDCHuman *father) {
    IDCReturnMacros(human);
    
    human->_father = father;
    __IDCObjectRetain(human);
    
}

IDCHuman *IDCHumanGetFather(IDCHuman *human) {
    assert(human);
    
    return human->_father;
}

void __IDCHumanSetMother(IDCHuman *human, IDCHuman *mother) {
    IDCReturnMacros(human);
    
    human->_mother = mother;
    
    __IDCObjectRetain(human);

}

IDCHuman *IDCHumanGetMother(IDCHuman *human) {
    assert(human);
    
    return human->_mother;
}

void __IDCHumanSetParents(IDCHuman *human, IDCHuman *father, IDCHuman *mother) {
    __IDCHumanSetFather(human, father);
    __IDCHumanSetMother(human, mother);
    
}

IDCHuman *IDCHumanGetParents(IDCHuman *human) {
    assert(human);
    
    return IDCHumanGetFather(human), IDCHumanGetMother(human);
}

//add macros!!!
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

bool IDCHumanGetterIsMarried(IDCHuman *human) {
    assert(human);
    
    return IDCHumanGetPartner(human) ? true : false;
}

void IDCHumanAddChild(IDCHuman *human, IDCHuman *child) {
    IDCReturnMacros(human);
    IDCReturnMacros(child);
    if (IDCHumanGetGender(human) == kIDCUnknownGender) {
        return;
    }
    
    if (20 > IDCHumanGetChildrenCount(human)) {
        human->_children[IDCHumanGetChildrenCount(human)] = child;
    } else if (20 == IDCHumanGetChildrenCount(human)) {
        human->_children[IDCHumanOldestChildIndex(human)] = child;
    }
    
    (IDCHumanGetGender(human) == kIDCMale) ? __IDCHumanSetFather(child, human)
                                           : __IDCHumanSetMother(child, human);

}

void IDCHumanRemoveChild(IDCHuman *human, uint8_t index) {
    IDCReturnMacros(human);
    
    if (human->_gender == kIDCMale) {
        __IDCHumanSetFather(IDCHumanGetChild(human, index), NULL);
    } else {
        __IDCHumanSetMother(IDCHumanGetChild(human, index), NULL);
    }
    
    __IDCObjectRelease(IDCHumanGetChild(human, index));
    __IDCObjectRelease(IDCHumanGetChild(human, index));
    
    human->_children[index] = NULL;
    __IDCHumanReplaceChildrenHigherInArray(human, index);
    
}

//add reproduction
uint8_t IDCHumanGetChildrenCount(IDCHuman *human) {
    assert(human);
    
    uint8_t index = 0;
    while (human->_children[index] != NULL) {
        index++;
    }

    return index;
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
            __IDCObjectRetain(human);
        } else {
            __IDCObjectRetain(partner);
        }
    }
    
}

void IDCHumanDivorce(IDCHuman *human) {
    IDCReturnMacros(human)
    
    IDCGender genderType = IDCHumanGetGender(human);
    if (genderType == kIDCMale) {
        __IDCObjectRelease(human);
    } else if (genderType == kIDCFemale) {
        __IDCObjectRelease(IDCHumanGetPartner(human));
    }
    
    IDCHumanSetPartner(IDCHumanGetPartner(human), NULL);
    IDCHumanSetPartner(human, NULL);
    
}
