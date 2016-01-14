//
//  IDCLection4BitField.c
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 04.01.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#include <stdbool.h>
#include <stdio.h>
#include "IDCLection4BitField.h"

typedef enum {
    kIDCUnknowEndianType,
    kIDCLittleEndian,
    kIDCBigEndian
} IDCEndianType;

#pragma mark -
#pragma mark Private Declaration

static const char kIDCBiteSize = 8;

static
void IDCPrintBitValue(int8_t *valueStartByte, IDCEndianType type);

static
IDCEndianType IDCCheckEndianness(void);

#pragma mark -
#pragma mark Private Implementation

IDCEndianType IDCCheckEndianness(void) {
    union {
        bool checkingBoolValue : 1;
        int8_t checkingCharValue;
    } IDCCheckValue;
    
    int8_t firstBiteValue = 1;
    IDCCheckValue.checkingCharValue = firstBiteValue;
    
    return IDCCheckValue.checkingBoolValue ? kIDCLittleEndian : kIDCBigEndian;
}

void IDCPrintBitValue(int8_t *valueStartByte, IDCEndianType type) {
    int8_t value = *valueStartByte;
    for (int increment = 0; increment < kIDCBiteSize; increment++) {
        int index = (type == kIDCBigEndian) ? increment
                                            : (kIDCBiteSize - increment - 1);
        
        printf((value >> index) & 1 ? "1" : "0");
    }
    
    printf(" ");
}

#pragma mark -
#pragma mark Public Implementation

void IDCPrintBitesValue(void *valueStartByte, size_t size) {
    void *value = valueStartByte;
    IDCEndianType type = IDCCheckEndianness();
    if (type == kIDCUnknowEndianType) {
        
        return;
    }
    
    size_t increment = size;
    while (increment > 0) {
        size_t index = (type == kIDCBigEndian) ? (size - (--increment))
                                               : (--increment);
        IDCPrintBitValue(&value[index], type);
                                                  
    }
}