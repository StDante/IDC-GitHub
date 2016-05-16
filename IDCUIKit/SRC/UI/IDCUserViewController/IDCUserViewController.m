//
//  IDCUserViewController.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 09.05.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCUserViewController.h"

@interface IDCUserViewController ()
@property (nonatomic, readonly) IDCUserView     *rootView;

- (id)objectFromNibOfClass:(Class)theClass;
- (IDCUserViewCell *)reuseCellIfNotCreate:(UITableView *)tableView ofClass:(Class)theClass;
- (void)performChangesWithObject:(id)object;

@end

@implementation IDCUserViewController

#pragma mark -
#pragma mark Accessors

IDCRootViewReturnIfNilMacro(IDCUserView);

- (void)setArrayModel:(IDCArrayModel *)arrayModel{
    if (_arrayModel != arrayModel) {
        _arrayModel = arrayModel;
        
        IDCWeakifyMacro;
        [_arrayModel addHandler:^(IDCStateModel *model){
            IDCStrongifyReturnIfNillMacro(IDCUserViewController);
            [strongSelf performChangesWithObject:model];
            
        }           forState:kIDCChangeObjectState
                         object:self];
    }
}

#pragma mark -
#pragma mark Handling Interface

- (IBAction)onUpdateCellsButton:(id)sender {
    self.arrayModel = [IDCArrayModel arrayModelWithArray:[IDCStringModel randomStringsModels]];
    [self.rootView.tableView reloadData];
}

- (IBAction)onStartEditingSwitch:(id)sender {
    self.rootView.tableView.editing = !self.rootView.editSwitch.on;
}

#pragma mark -
#pragma mark Controller Lifecycle


#pragma mark -
#pragma mark Private

- (void)performChangesWithObject:(IDCStateModel *)object {
    UITableView *tableView = self.rootView.tableView;
    NSIndexPath *indexPath = [NSIndexPath indexPathForRow:object.index inSection:0];
    
    if (object.state == kIDCObjectAddState) {
        [tableView insertRowsAtIndexPaths:[NSArray arrayWithObject:indexPath]
                         withRowAnimation:UITableViewRowAnimationFade];
    } else {
        
        [tableView deleteRowsAtIndexPaths:[NSArray arrayWithObject:indexPath]
                         withRowAnimation:UITableViewRowAnimationFade];
    }
}

#pragma mark -
#pragma mark UITableViewDataSource protocol


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.arrayModel.objects.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    IDCUserViewCell *cell = [self reuseCellIfNotCreate:(UITableView *)tableView ofClass:[IDCUserViewCell class]];
    [cell fillWithModel:self.arrayModel[indexPath.row]];
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}

- (void)        tableView:(UITableView *)tableView
       commitEditingStyle:(UITableViewCellEditingStyle)editingStyle
        forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        [self.arrayModel removeObjectAtIndex:indexPath.row];
    } else {
        [self.arrayModel addObject:[IDCStringModel new]];
    }
}

- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath
{
    return YES;
}

- (void)            tableView:(UITableView *)tableView
           moveRowAtIndexPath:(NSIndexPath *)fromIndexPath
                  toIndexPath:(NSIndexPath *)toIndexPath
{
    [self.arrayModel moveCellFromIndex:fromIndexPath.row toIndex:toIndexPath.row];
}

#pragma mark -
#pragma mark TableView Delegate Protocol

- (UITableViewCellEditingStyle)tableView:(UITableView *)tableView
           editingStyleForRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (indexPath.row < 1) {
        return UITableViewCellEditingStyleInsert;
    } else {
        return UITableViewCellEditingStyleDelete;
    }
}


#pragma mark -
#pragma mark Extention

//create extention with thous methods

- (id)objectFromNibOfClass:(Class)theClass {
    UINib *nib = [UINib nibWithNibName:NSStringFromClass([theClass class]) bundle:[NSBundle mainBundle]];
    NSArray *objects = [nib instantiateWithOwner:[theClass class] options:nil];
    for (id object in objects) {
        if ([object isMemberOfClass:theClass]) {
            return object;
        }
    }
    
    return nil;
}

- (IDCUserViewCell *)reuseCellIfNotCreate:(UITableView *)tableView ofClass:(Class)theClass {
    IDCUserViewCell *cell = [tableView dequeueReusableCellWithIdentifier:NSStringFromClass([theClass class])];
    if (!cell) {
        cell = [self objectFromNibOfClass:[IDCUserViewCell class]];
    }
    
    return cell;
}

@end
