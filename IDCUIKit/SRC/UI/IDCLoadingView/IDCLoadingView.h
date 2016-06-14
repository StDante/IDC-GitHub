//
//  IDCLoadingView.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 13.06.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface IDCLoadingView : UIView

- (void)showLoadingView;

- (void)showLoadingViewWithDefaultText;
- (void)showLoadingViewWithDefaultTextAnimated:(BOOL)animated;

- (void)showLoadingViewWithText:(NSString *)text;
- (void)showLoadingViewWithText:(NSString *)text animated:(BOOL)animated;

- (void)removeLoadingView;
- (void)removeLoadingViewAnimated:(BOOL)animated;

@end
