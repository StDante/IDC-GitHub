//
//  IDCLection5ObjectHuman.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 12.01.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#ifndef IDCLection5ObjectHuman_h
#define IDCLection5ObjectHuman_h
#include "IDCLection5ObjectString.h"
#include "IDCLection5ObjectArray.h"

typedef struct IDCHuman IDCHuman;

typedef enum {
    kIDCUnknownGender,
    kIDCMale,
    kIDCFemale
} IDCGender;

extern
IDCHuman *IDCHumanCreateWithNameAndGender(IDCString *name, IDCGender gender);

extern
IDCHuman *IDCHumanCreateWithParentsAndName(IDCString *name, IDCHuman *father, IDCHuman *mother);

extern
void IDCHumanSetName(IDCHuman *human, IDCString *name);

extern
IDCString *IDCHumanGetName(IDCHuman *human);

extern
IDCHuman *IDCHumanGetFather(IDCHuman *human);

extern
IDCHuman *IDCHumanGetMother(IDCHuman *human);

extern
IDCHuman *IDCHumanGetParents(IDCHuman *human);

extern
IDCHuman *IDCHumanGetPartner(IDCHuman *human);

extern
void IDCHumanSetGender(IDCHuman *human, IDCGender genderType);

extern
IDCGender IDCHumanGetGender(IDCHuman *human);

extern
void IDCHumanSetAge(IDCHuman *human, uint8_t age);

extern
uint8_t IDCHumanGetAge(IDCHuman *human);

extern
bool IDCHumanGetterIsMarried(IDCHuman *human);

extern
void IDCHumanAddChild(IDCHuman *human, IDCHuman *child);

extern
void IDCHumanRemoveChild(IDCHuman *human, uint8_t index);

extern
IDCHuman *IDCHumanGetChild(IDCHuman *human, uint8_t childIndex);

extern
uint8_t IDCHumanGetChildrenCount(IDCHuman *human);

extern
void IDCHumanMarriage(IDCHuman *human, IDCHuman *partner);

extern
void IDCHumanDivorce(IDCHuman *human);

extern
IDCHuman IDCHumanReproduction(IDCString *name, IDCHuman *human);

#endif /* IDCLection5ObjectHuman_h */
