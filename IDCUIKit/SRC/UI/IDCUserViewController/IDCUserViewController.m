//
//  IDCUserViewController.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 09.05.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCUserViewController.h"

static const NSUInteger kIDCRowCount = 100;

@interface IDCUserViewController ()
@property (nonatomic, readonly) IDCUserView     *rootView;
@property (nonatomic, strong)   IDCArrayModel   *arrayModel;

- (id)objectFromNibOfClass:(Class)theClass;
- (IDCUserViewCell *)reuseCellIfNotCreate:(UITableView *)tableView;

@end

@implementation IDCUserViewController

#pragma mark -
#pragma mark Accessors

IDCRootViewReturnIfNilMacro(IDCUserView);

#pragma mark -
#pragma mark Controller Lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self.rootView.tableView reloadData];
}

#pragma mark -
#pragma mark UITableViewDataSource protocol


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return kIDCRowCount;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    return [self reuseCellIfNotCreate:(UITableView *)tableView];
}

#pragma mark -
#pragma mark Private

//create extention with thous methods

- (id)objectFromNibOfClass:(Class)theClass {
    UINib *nib = [UINib nibWithNibName:NSStringFromClass([theClass class]) bundle:[NSBundle mainBundle]];
    NSArray *objects = [nib instantiateWithOwner:[theClass class] options:nil];
    for (id object in objects) {
        if ([object isKindOfClass:theClass]) {
            return object;
        }
    }
    
    return nil;
}

- (IDCUserViewCell *)reuseCellIfNotCreate:(UITableView *)tableView {
    IDCUserViewCell *cell = [tableView dequeueReusableCellWithIdentifier:NSStringFromClass([IDCUserViewCell class])];
    if (!cell) {
        cell = [self objectFromNibOfClass:[IDCUserViewCell class]];
    }
    
    return cell;
}

@end
