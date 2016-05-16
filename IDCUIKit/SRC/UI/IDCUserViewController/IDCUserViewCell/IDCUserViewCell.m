//
//  IDCUserViewCell.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 09.05.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCUserViewCell.h"

@implementation IDCUserViewCell

#pragma mark -
#pragma mark Public

- (void)fillWithModel:(IDCStringModel *)theModel {
    self.cellLabel.text = theModel.string;
    self.cellImage.image = theModel.image;
}

@end
