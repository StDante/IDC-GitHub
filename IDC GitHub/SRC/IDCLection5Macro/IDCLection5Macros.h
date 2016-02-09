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
                printf("There is no such object\n"); \
                return; \
            }

#define IDCReturnValueMacros(value, returnValue) \
            if (NULL == value) { \
                printf("There is no such object\n"); \
                return returnValue; \
            }


#define IDCReturnNULLMacros(value) \
            if (NULL == value) { \
            printf("There is no such object\n"); \
            return NULL; \
            }

#define IDCObjectCreate(type) \
            __IDCObjectCreate(sizeof(type), (IDCObjectDeallocator *)__##type##Deallocate);

#define IDCDoubleRetain(value) \
            IDCObjectRetain(human); \
            IDCObjectRetain(human);

#define IDCAssignSetter(oldValue, newValue) \
            if (oldValue != newValue) { \
                oldValue = newValue; \
            } \

#define IDCRetainSetter(oldValue, newValue) \
            if (oldValue != newValue) {\
                IDCObjectRelease(oldValue); \
                oldValue = IDCObjectRetain(newValue); \
            }

#define IDCHumanRetainStrongConection(human, partner) \
            IDCGender genderType = IDCHumanGetGender(human); \
            if (genderType == kIDCMale) { \
                IDCObjectRetain(human); \
            } else { \
                IDCObjectRetain(partner); \
            }

#define IDCHumanReleaseStrongConection(human) \
            IDCGender genderType = IDCHumanGetGender(human); \
            if (genderType == kIDCMale) { \
                IDCObjectRelease(human); \
            } else if (genderType == kIDCFemale) { \
                IDCObjectRelease(IDCHumanGetPartner(human)); \
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

#define IDCReturnNULLIfFirstValueIsBigger(firstValue, secondValue) \
            if (firstValue > secondValue) { \
                return NULL; \
            }

#define IDCReturnIfFirstValueIsBigger(firstValue, secondValue) \
            if (firstValue > secondValue) { \
            return; \
            }
#endif /* IDCLection5Macro_h */
