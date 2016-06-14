//
//  IDCUserViewCell.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 09.05.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCUserViewCell.h"
#import "IDCImageView.h"
#import "IDCImageModel.h"

@implementation IDCUserViewCell

#pragma mark -
#pragma mark Public

- (void)fillWithModel:(IDCStringModel *)theModel {
    self.cellLabel.text = theModel.string;
    self.cellImage.URL = [NSURL URLWithString:theModel.urlString];
}

@end
