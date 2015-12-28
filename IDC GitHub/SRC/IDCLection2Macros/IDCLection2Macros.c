//
//  IDCLection2Macros.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 28.12.15.
//  Copyright © 2015 Alexandr Altukhov. All rights reserved.
//

#include "IDCLection2Macros.h"

//macros that creates function to print any value of any type
#define IDCOutputFunction(type, specifier) \
void IDCOutput_##type(type value) {\
printf("Value of type " #type " is " specifier "\n", value);\
}

//macros that runs function from IDCOutputFunction macros with some value
#define IDCOutputValueOfType(type, value) IDCOutput_##type(value)


IDCOutputFunction(char, "%c")
IDCOutputFunction(short, "%i")
IDCOutputFunction(int, "%i")
IDCOutputFunction(long, "%li")
IDCOutputFunction(float, "%f")
IDCOutputFunction(double, "%f")