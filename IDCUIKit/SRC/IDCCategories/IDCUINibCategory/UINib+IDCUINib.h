//
//  UINib+IDCUINib.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 25.05.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UINib (IDCUINib)

+ (id)objectFromNibOfClass:(Class)theClass;

@end
