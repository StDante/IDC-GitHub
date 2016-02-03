//
//  IDCLection4BitFieldTest.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 04.01.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#include <stdio.h>
#include "IDCLection4BitFieldTest.h"

static const int16_t kIDCFirstValueTest = 1;
static const int32_t kIDCSecondValueTest = 16;
static const int64_t kIDCThirdValueTest = 20;

//void IDCPrintBitesValueTest() {
//    printf("\ntesting");
//    puts("\ntest with int16_t value = 1");
//    void *value = &kIDCFirstValueTest;
//    size_t size = sizeof(kIDCFirstValueTest);
//    IDCPrintBitesValue(value, size);
//    
//    puts("\n\ntest with int32_t value = 16");
//    value = &kIDCSecondValueTest;
//    size = sizeof(kIDCSecondValueTest);
//    IDCPrintBitesValue(value, size);
//    
//    puts("\n\ntest with int64_t value = 20");
//    value = &kIDCThirdValueTest;
//    size = sizeof(kIDCThirdValueTest);
//    IDCPrintBitesValue(value, size);
//    
//}
