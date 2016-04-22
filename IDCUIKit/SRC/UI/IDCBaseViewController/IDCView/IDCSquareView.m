//
//  IDCSquareView.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 22.04.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCSquareView.h"

@implementation IDCSquareView

#pragma mark -
#pragma mark Initialization and Deallocation

- (instancetype)init {
    self = [super init];
    self.label = [[UILabel alloc] init];
    self.sqaurePosition = kIDCUpperLeft;
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (void)setSquarePosition:(IDCSquarePosition)position {
    [self setSquarePosition:position animated:FALSE];
}

- (void)setSquarePosition:(IDCSquarePosition)position animated:(BOOL)value {
    [self setSquarePosition:position animated:value completionHandler:0];
}

- (void)setSquarePosition:(IDCSquarePosition)position
                 animated:(BOOL)value
        completionHandler:(IDCSquareViewHandler)handler
{
    
    self.sqaurePosition = position;
    UILabel *label = self.label;
    CGRect positionRectangle = IDCSquarePositionSwitch(position);
    
    CGAffineTransform transformPosition = CGAffineTransformTranslate(label.transform,
                                                             positionRectangle.origin.x,
                                                             positionRectangle.origin.y);
    
    
    if (value && self) {
        [UIView animateWithDuration:1.5 animations:^{
            label.transform = transformPosition;
        } completion:^(BOOL finished) {
            if (handler) {
                handler();
            }
        }];
    }
    
    [label setFrame:positionRectangle];
}

#pragma mark -
#pragma mark Public

- (void)awakeFromNib {
    [super awakeFromNib];
}

#pragma mark -
#pragma mark Private

CGRect IDCSquarePositionSwitch(IDCSquarePosition position){
    CGRect screen = [[UIScreen mainScreen] bounds];
    CGFloat height = screen.size.height;
    CGFloat widht = screen.size.width;
    switch (position) {
        case kIDCUpperLeft:

            return CGRectMake(widht * 0, height * 0, 100, 100);
            
        case kIDCLowerLeft:
            return CGRectMake(widht * 0, height * 1 - 100, 100, 100);
            
        case kIDCUpperRight:
            return CGRectMake((widht * 1 - 100), height * 0, 100, 100);
            
        case kIDCLowerRight:
            return CGRectMake((widht * 1 - 100), (height * 1 - 100), 100, 100);
            
    }
    
    return CGRectMake(widht * 0.5, height * 0.5, 100, 100);
}

@end
