//
//  IDCSquareView.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 22.04.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IDCObjCMacro.h"

typedef void (^IDCSquareViewHandler)(void);

typedef enum IDCSquarePosition : NSUInteger {
    kIDCUpperLeft,
    kIDCLowerLeft,
    kIDCUpperRight,
    kIDCLowerRight
} IDCSquarePosition;

@interface IDCSquareView : UIView
@property (nonatomic, strong)   IBOutlet   UILabel               *label;
@property (nonatomic, strong)   IBOutlet   UIButton              *button;
@property (nonatomic, assign)              IDCSquarePosition     sqaurePosition;


CGRect IDCSquarePositionSwitch(IDCSquarePosition position);
- (void)setSquarePosition:(IDCSquarePosition)position;
- (void)setSquarePosition:(IDCSquarePosition)position animated:(BOOL)value;

@end
