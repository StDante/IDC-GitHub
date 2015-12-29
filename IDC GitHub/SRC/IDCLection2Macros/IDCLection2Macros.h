//
//  IDCLection2Macros.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 28.12.15.
//  Copyright © 2015 Alexandr Altukhov. All rights reserved.
//

#ifndef IDCLection2Macros_h
#define IDCLection2Macros_h

#define IDCPrintSizeType(type) \
printf("Size type " #type "= %lu\n", sizeof(type));

#define IDCPrintValue(specifier, value) \
printf("This is " #specifier, value);

//macros that creates function to print any value of any type
#define IDCOutputFunction(type, specifier) \
void IDCOutput_##type(type value) {\
printf("Value of type " #type " is " #specifier "\n", value);\
}

//macros that runs function from IDCOutputFunction macros with some value
#define IDCOutputValueOfType(type, value) IDCOutput_##type(value)

#endif /* IDCLection2Macros_h */
