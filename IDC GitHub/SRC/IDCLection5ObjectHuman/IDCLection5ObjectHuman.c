//
//  IDCLection5ObjectHuman.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 12.01.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "IDCLection5ObjectHuman.h"

static const uint8_t kIDCHumanReturnChildrenIndexMax = UINT8_MAX;
static const uint8_t kIDCHumanChildrenLimit = 20;

#pragma mark -
#pragma mark Private Declarations

struct IDCHuman {
    IDCObject _super;
    
    IDCArray *_children;
    IDCString *_name;
    IDCHuman *_father;
    IDCHuman *_mother;
    IDCHuman *_partner;
    IDCGender _gender;
    uint8_t _age;
};

static
void __IDCHumanDeallocate(IDCHuman *human);

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
void __IDCHumanResortChildrenArray(IDCHuman *human, uint8_t index);

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

IDCHuman *IDCHumanCreateWithNameAndGender(IDCString *name, IDCGender gender) {
    IDCHuman *human = IDCObjectCreate(IDCHuman);
    IDCHumanSetName(human, name);
    
    return human;
}

IDCHuman *IDCHumanCreateWithParentsAndNameAndGender(IDCString *name,
                                           IDCHuman *father,
                                           IDCHuman *mother)
{
    IDCHuman *human = IDCHumanCreateWithNameAndGender(name, arc4random_uniform(2) + 1);
    __IDCHumanSetParents(human, father, mother);
    
    IDCHumanAddChild(father, human);
    IDCHumanAddChild(mother, human);
    
    return human;
}

#pragma mark -
#pragma mark Private Implementation

uint8_t IDCHumanIndexOfChild(IDCHuman *human, IDCHuman *child) {
    assert(human);

    return IDCArrayGetIndexOfElement(human->_children, child);
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

void __IDCHumanResortChildrenArray(IDCHuman *human, uint8_t index) {
    __IDCArrayResortElementsFromIndex(human->_children, index);
}

void IDCHumanRemoveAllChildren(IDCHuman *human) {
    uint8_t index = IDCHumanGetChildrenCount(human);
    
    while (0 != index) {
        IDCHumanRemoveChild(human, --index);
    }
    
}

#pragma mark - 
#pragma mark Public Implementation

void IDCHumanAddChild(IDCHuman *human, IDCHuman *child) {
    IDCReturnMacros(human);
    IDCReturnMacros(child);
    if (IDCHumanGetGender(human) == kIDCUnknownGender) {
        return;
    }
    
    uint8_t index = IDCHumanGetChildrenCount(human);
    
    if (kIDCHumanChildrenLimit > index) {
        IDCArrayAddElement(human->_children, child);
    } else if (kIDCHumanChildrenLimit == index) {
        IDCHumanRemoveChild(human, IDCHumanOldestChildIndex(human));
        IDCArrayAddElement(human->_children, child);
    }
    
    if (IDCHumanGetGender(human) == kIDCMale) {
        IDCHuman *father = IDCHumanGetFather(child);
        IDCHumanRemoveChild(father, IDCHumanIndexOfChild(father, child));
        __IDCHumanSetFather(child, human);
    } else {
        IDCHuman *mother = IDCHumanGetMother(child);
        IDCHumanRemoveChild(mother, IDCHumanIndexOfChild(mother, child));
        __IDCHumanSetMother(child, human);
    }
    
    __IDCObjectRetain(child);
    
}

void IDCHumanRemoveChild(IDCHuman *human, uint8_t index) {
    IDCReturnMacros(human);
    IDCHuman *child = IDCHumanGetChild(human, index);
    
    __IDCObjectRelease(child);
    
    (human->_gender == kIDCMale)
    ? __IDCHumanSetFather(child, NULL)
    : __IDCHumanSetMother(child, NULL);
    
    IDCArrayRemoveElementAtIndex(human->_children, index);
    __IDCHumanResortChildrenArray(human, index);
    
}

void IDCHumanMarriage(IDCHuman *human, IDCHuman *partner) {
    IDCReturnMacros(human)
    IDCReturnMacros(partner)
    IDCGender gender = IDCHumanGetGender(human);
    IDCGender partnerGender = IDCHumanGetGender(partner);
    
    if (gender == partnerGender || (kIDCUnknownGender == (gender || partnerGender)))
    {
        printf("Can't pair partners with same gender or unknown gender");
        
        return;
    }
    
    IDCHumanDivorce(human);
    IDCHumanDivorce(partner);
    
    IDCHumanSetPartner(human, partner);
    IDCHumanSetPartner(partner, human);
    
    IDCHumanRetainStrongConection(human,partner)
    
}

void IDCHumanDivorce(IDCHuman *human) {
    IDCReturnMacros(human)
    
    IDCHumanReleaseStrongConection(human)
    
    IDCHumanSetPartner(IDCHumanGetPartner(human), NULL);
    IDCHumanSetPartner(human, NULL);
    
}

IDCHuman IDCHumanReproduction(IDCString *name, IDCHuman *human) {
    assert(human);
    assert(IDCHumanGetterIsMarried(human));
    
    if (IDCHumanGetGender(human) == kIDCMale) {
        IDCHumanReproductionIfHumanMaleMacros(name, human)
    } else {
        IDCHumanReproductionIfHumanFemaleMacros(name, human)
    }
    
}

#pragma mark -
#pragma mark Accessors

void IDCHumanSetName(IDCHuman *human, IDCString *name) {
    IDCReturnMacros(human)
    
    IDCRetainSetter(human->_name, name)
    
}

IDCString *IDCHumanGetName(IDCHuman *human) {
    assert(human);
    
    return human->_name;
}

void __IDCHumanSetFather(IDCHuman *human, IDCHuman *father) {
    IDCReturnMacros(human);
    
    human->_father = father;
    
}

IDCHuman *IDCHumanGetFather(IDCHuman *human) {
    assert(human);
    
    return human->_father;
}

void __IDCHumanSetMother(IDCHuman *human, IDCHuman *mother) {
    IDCReturnMacros(human);
    
    human->_mother = mother;

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

void IDCHumanSetPartner(IDCHuman *human, IDCHuman *partner) {
    IDCAssignSetter(human->_partner, partner)
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

uint8_t IDCHumanGetChildrenCount(IDCHuman *human) {
    assert(human);
    
    return IDCArrayGetCount(human->_children);
}

IDCHuman *IDCHumanGetChild(IDCHuman *human, uint8_t childIndex) {
    assert(human);
    
    return IDCArrayGetElementAtIndex(human->_children, childIndex);
}