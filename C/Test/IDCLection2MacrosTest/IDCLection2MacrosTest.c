//
//  IDCLection2MacrosTest.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 29.12.15.
//  Copyright © 2015 Alexandr Altukhov. All rights reserved.
//

#include <stdio.h>
#include "IDCLection2MacrosTest.h"

IDCOutputFunction(char, %c)
IDCOutputFunction(short, %i)
IDCOutputFunction(int, %i)
IDCOutputFunction(long, %li)
IDCOutputFunction(float, %f)
IDCOutputFunction(double, %f)

void IDCPrintMacrosWithAnyTypeAndValue() {
    printf("testing\n");
    IDCOutputValueOfType(char, 'C');
    IDCOutputValueOfType(short, 10);
    IDCOutputValueOfType(int, 158);
    IDCOutputValueOfType(long, 999);
    IDCOutputValueOfType(float, 1.2);
    IDCOutputValueOfType(double, 99.9);
    
}

