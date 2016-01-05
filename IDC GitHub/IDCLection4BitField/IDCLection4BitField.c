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

#pragma mark -
#pragma mark Private Declaration

union {
    bool checkingBoolValue : 1;
    int8_t checkingCharValue;
} IDCCheckValue;

static const char kIDCBiteSize = 8;

static
void IDCPrintBitValueBigEndian(int8_t *valueStartByte);

static
void IDCPrintBitValueLittleEndian(int8_t *valueStartByte);

static
bool IDCCheckEndianness(void);

#pragma mark -
#pragma mark Private Implementation

void IDCPrintBitValueBigEndian(int8_t *valueStartByte) {
    int8_t value = *valueStartByte;
    for (int index = 0; index < kIDCBiteSize; index++) {
        printf((value >> index) & 1 ? "1" : "0");
    }
    
    printf(" ");
}

void IDCPrintBitValueLittleEndian(int8_t *valueStartByte) {
    int8_t value = *valueStartByte;
    for (int index = kIDCBiteSize - 1; index >= 0; index--) {
        printf((value >> index) & 1 ? "1" : "0");
    }
    
    printf(" ");
}

bool IDCCheckEndianness() {
    int8_t firstBiteValue = 1;
    IDCCheckValue.checkingCharValue = firstBiteValue;
    
    return IDCCheckValue.checkingBoolValue;
}

#pragma mark -
#pragma mark Public Implementation

void IDCPrintBitesValue(void *valueStartByte, size_t size) {
    void *value = valueStartByte;
    
    size_t index = size;
    
    IDCCheckEndianness();
    if (IDCCheckValue.checkingBoolValue == true) {
        printf("Little-endian\n");
        while (index > 0) {
            index--;
            IDCPrintBitValueLittleEndian(&value[index]);
        }
    } else {
        printf("\nBig-endian\n");
        index = 0;
        while (index < size) {
            IDCPrintBitValueBigEndian(&value[index]);
            index++;
        }
    }
}