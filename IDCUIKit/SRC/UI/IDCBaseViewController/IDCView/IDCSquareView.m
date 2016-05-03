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

- (CGRect)squarePosition:(IDCSquarePosition)position;

@end

@implementation IDCSquareView

#pragma mark -
#pragma mark Accessors

- (void)setSquarePosition:(IDCSquarePosition)position {
    [self setSquarePosition:position animated:NO];
}

- (void)setSquarePosition:(IDCSquarePosition)position animated:(BOOL)animated {
    [self setSquarePosition:position animated:animated completionHandler:nil];
}

- (void)setSquarePosition:(IDCSquarePosition)position
                 animated:(BOOL)animated
        completionHandler:(IDCSquareViewHandler)handler
{
    if (_squarePosition != position) {
        if (self.animationSwitch.isOn) {
            animated = YES;
        } else {
            animated = NO;
        }
        UILabel *label = self.label;
        CGRect positionSquare = [self squarePosition:position];
        CGPoint origin = positionSquare.origin;
        CGAffineTransform transformPosition = CGAffineTransformMakeTranslation(origin.x, origin.y);
  
        CGFloat duration = animated ? kIDCAnimationDuration : 0;
        [UIView animateWithDuration:duration animations:^ {
            label.transform = transformPosition;
        } completion:^(BOOL finished) {
            _squarePosition = position;
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
    [self setSquarePosition:[self nextSquarePosition] animated:YES completionHandler:^ {
        IDCStrongifyReturnIfNillMacro(IDCSquareView)
        if (strongSelf.cycleMoveSwitch.isOn) {
            [strongSelf moveLabel];
            sleep(1);
        }
    }];
}

#pragma mark -
#pragma mark Private

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

- (CGRect)squarePosition:(IDCSquarePosition)position {
    CGSize viewSize = [self.labelView viewSize];
    CGFloat height = viewSize.height;
    CGFloat widht = viewSize.width;
    switch (position) {
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
