//
//  IDCLection5Macro.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 21.01.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#ifndef IDCLection5Macros_h
#define IDCLection5Macros_h

#define IDCReturnMacros(value) \
            if (NULL == value) { \
                printf("There is no such object"); \
                return; \
            }

#define IDCObjectCreate(type) \
            __IDCObjectCreate(sizeof(type), (IDCObjectDeallocator *)__##type##Deallocate);

#define IDCDoubleRetain(value) \
            __IDCObjectRetain(human); \
            __IDCObjectRetain(human);

#define IDCAssignSetter(oldValue, newValue) \
            if (oldValue != newValue) { \
                oldValue = newValue; \
            } \

#define IDCRetainSetter(oldValue, newValue) \
            if (oldValue != newValue) {\
                __IDCObjectRelease(oldValue); \
                oldValue = __IDCObjectRetain(newValue); \
            }

#define IDCHumanRetainStrongConection(human, partner) \
            IDCGender genderType = IDCHumanGetGender(human); \
            if (genderType == kIDCMale) { \
                __IDCObjectRetain(human); \
            } else { \
                __IDCObjectRetain(partner); \
            }

#define IDCHumanReleaseStrongConection(human) \
            IDCGender genderType = IDCHumanGetGender(human); \
            if (genderType == kIDCMale) { \
                __IDCObjectRelease(human); \
            } else if (genderType == kIDCFemale) { \
                __IDCObjectRelease(IDCHumanGetPartner(human)); \
            }

#define IDCHumanReproductionIfHumanMaleMacros(name, human) \
            IDCHuman *child = IDCHumanCreateWithParentsAndNameAndGender(name, \
                                                                        human, \
                                                                        IDCHumanGetPartner(human)); \
            return *child;

#define IDCHumanReproductionIfHumanFemaleMacros(name, human) \
            IDCHuman *child = IDCHumanCreateWithParentsAndNameAndGender(name, \
                                                                        IDCHumanGetPartner(human), \
                                                                        human); \
            return *child;


#endif /* IDCLection5Macro_h */
