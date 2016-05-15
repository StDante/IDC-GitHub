//
//  IDCSquareView.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 22.04.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCSquareView.h"

static const CGFloat kIDCAnimationDuration = 1.5;
static const CGFloat kIDCLabelWidht = 100;
static const CGFloat kIDCLabelHeight = 100;

@interface IDCSquareView()

- (CGRect)squarePositionSwitch:(IDCSquarePosition)squarePosition;
- (CGAffineTransform)transformPosition:(IDCSquarePosition)squarePosition;

@end

@implementation IDCSquareView

#pragma mark -
#pragma mark Accessors

- (void)setSquarePosition:(IDCSquarePosition)squarePosition {
    [self setSquarePosition:squarePosition animated:NO];
}

- (void)setSquarePosition:(IDCSquarePosition)squarePosition animated:(BOOL)animated {
    [self setSquarePosition:squarePosition animated:animated completionHandler:nil];
}

- (void)setSquarePosition:(IDCSquarePosition)squarePosition
                 animated:(BOOL)animated
        completionHandler:(IDCSquareViewHandler)handler

{
    if (_squarePosition != squarePosition) {
        UILabel *label = self.label;
        CGAffineTransform transformPosition = [self transformPosition:squarePosition];
  
        CGFloat duration = animated ? kIDCAnimationDuration : 0;
        [UIView animateWithDuration:duration
                              delay:0.5
                            options:UIViewAnimationOptionCurveEaseInOut
                         animations:^ {
            label.transform = transformPosition;
        } completion:^(BOOL finished) {
            _squarePosition = squarePosition;
            if (handler) {
                handler();
            }
        }];
    }
}

#pragma mark -
#pragma mark Public

- (void)moveLabel {
    IDCWeakifyMacro
    self.button.userInteractionEnabled = NO;
    [self setSquarePosition:[self nextSquarePosition] animated:self.animationSwitch.isOn completionHandler:^ {
        IDCStrongifyReturnIfNillMacro(IDCSquareView)
        if (strongSelf.cycleMoveSwitch.isOn) {
            [strongSelf moveLabel];
        } else {
            strongSelf.button.userInteractionEnabled = YES;
        }
    }];
}

#pragma mark -
#pragma mark Private

- (CGAffineTransform)transformPosition:(IDCSquarePosition)squarePosition {
    CGRect positionSquare = [self squarePositionSwitch:squarePosition];
    CGPoint origin = positionSquare.origin;
    
    return CGAffineTransformMakeTranslation(origin.x, origin.y);
}

- (IDCSquarePosition)nextSquarePosition {
    switch (self.squarePosition) {
        case kIDCUpperLeft:
            return kIDCUpperRight;
            
        case kIDCUpperRight:
            return kIDCLowerRight;
            
        case kIDCLowerRight:
            return kIDCLowerLeft;
            
        default:
            return kIDCUpperLeft;
    }
}

- (CGRect)squarePositionSwitch:(IDCSquarePosition)squarePosition {
    CGSize viewSize = [self.labelView viewSize];
    CGFloat height = viewSize.height;
    CGFloat widht = viewSize.width;
    switch (squarePosition) {
        case kIDCUpperLeft:
            return CGRectMake(0, 0, kIDCLabelWidht, kIDCLabelHeight);
            
        case kIDCLowerLeft:
            return CGRectMake(0, height - kIDCLabelHeight, kIDCLabelWidht, kIDCLabelHeight);
            
        case kIDCUpperRight:
            return CGRectMake(widht - kIDCLabelWidht, 0, kIDCLabelWidht, kIDCLabelHeight);
            
        case kIDCLowerRight:
            return CGRectMake(widht - kIDCLabelWidht,
                              height - kIDCLabelHeight,
                              kIDCLabelWidht,
                              kIDCLabelHeight);
            
    }
    
    return CGRectMake(0, 0, kIDCLabelWidht, kIDCLabelHeight);
}

@end
