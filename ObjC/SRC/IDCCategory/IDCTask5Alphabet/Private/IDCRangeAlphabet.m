//
//  IDCRangeAlphabet.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 07.03.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCRangeAlphabet.h"

@interface IDCRangeAlphabet ()
@property (nonatomic, assign) NSRange range;

@end

@implementation IDCRangeAlphabet

#pragma mark -
#pragma mark Initializationd and Deallocation

- (instancetype)initWithRange:(NSRange)range {
    self = [super init];
    if (self) {
        self.range = range;
    }
    
    return self;
}

#pragma mark - 
#pragma mark Accessors

- (NSString *)alphabetString {
    NSMutableString *string = [NSMutableString string];
    NSRange range = self.range;
    NSUInteger location = range.location;
    
    for (NSUInteger index = location; index < location + range.length; index++) {
        [string appendString:[NSString stringWithFormat:@"%c", (unichar)index]];
    }
    
    return [[string copy] autorelease];
}

- (NSUInteger)count {
    return self.range.length;
}

@end
