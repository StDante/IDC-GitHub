//
//  IDCSquareView.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 22.04.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCSquareView.h"

static const CGFloat kIDCAnimationDuration = 1.5;

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
        _squarePosition = position;
    }
    
    UILabel *label = self.label;
    CGRect positionSquare = [self squarePosition:position];
    CGPoint origin = positionSquare.origin;
    CGAffineTransform transformPosition = CGAffineTransformMakeTranslation(origin.x, origin.y);
  
    CGFloat duration = animated ? kIDCAnimationDuration : 0;
    [UIView animateWithDuration:duration animations:^ {
        label.transform = transformPosition;
    } completion:^(BOOL finished) {
        if (handler) {
            handler();
        }
    }];
}

#pragma mark -
#pragma mark Public

- (void)squareCycleMove {
    [self setSquarePosition:[self nextSquarePosition] animated:YES completionHandler:^ {
        [self squareCycleMove];
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
    CGRect screen = [[UIScreen mainScreen] bounds];
    CGFloat height = screen.size.height;
    CGFloat widht = screen.size.width;
    switch (position) {
        case kIDCUpperLeft:
            return CGRectMake(0, 0, 100, 100);
            
        case kIDCLowerLeft:
            return CGRectMake(0, height - 100, 100, 100);
            
        case kIDCUpperRight:
            return CGRectMake(widht - 100, 0, 100, 100);
            
        case kIDCLowerRight:
            return CGRectMake(widht - 100, height - 100, 100, 100);
            
    }
    
    return CGRectMake(widht * 0.5, height * 0.5, 100, 100);
}

@end
