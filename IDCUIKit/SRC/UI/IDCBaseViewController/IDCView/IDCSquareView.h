//
//  IDCSquareView.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 22.04.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IDCObjCMacro.h"
#import "UIView+IDCViewCategory.h"

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
@property (nonatomic, strong)   IBOutlet   UIView                *labelView;
@property (nonatomic, strong)   IBOutlet   UISwitch              *animationSwitch;
@property (nonatomic, strong)   IBOutlet   UISwitch              *cycleMoveSwitch;
@property (nonatomic, assign)              IDCSquarePosition     squarePosition;

- (void)setSquarePosition:(IDCSquarePosition)position;
- (void)setSquarePosition:(IDCSquarePosition)position animated:(BOOL)animated;
- (void)setSquarePosition:(IDCSquarePosition)position
                 animated:(BOOL)animated
        completionHandler:(IDCSquareViewHandler)handler;

- (void)moveLabel;

- (IDCSquarePosition)nextSquarePosition;

@end
