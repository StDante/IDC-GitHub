//
//  IDCImageModel.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 12.06.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCStateUniversalModel.h"
#import <UIKit/UIkit.h>

@interface IDCImageModel : IDCStateUniversalModel
@property (nonatomic, strong) UIImage     *image;
@property (nonatomic, strong) NSURL       *URL;

+ (instancetype)imageModelWithURL:(NSURL *)URL;
- (instancetype)initWithURL:(NSURL *)URL;

@end
