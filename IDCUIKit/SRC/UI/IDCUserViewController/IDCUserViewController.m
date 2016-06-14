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

- (void)performChangesWithObject:(id)object;
- (void)addHandlers;
- (void)performLoad;

@end

@implementation IDCUserViewController

#pragma mark -
#pragma mark Accessors

IDCRootViewReturnIfNilMacro(IDCUserView);

- (void)setArrayModel:(IDCArrayModel *)arrayModel{
    if (_arrayModel != arrayModel) {
        _arrayModel = arrayModel;
        
        [self addHandlers];
        [self performLoad];
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

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    [self performLoad];
}

#pragma mark -
#pragma mark Private

- (void)addHandlers {
    IDCArrayModel *arrayModel = self.arrayModel;
    IDCWeakifyMacro;
    [arrayModel addHandler:^(IDCStateModel *model){
        IDCStrongifyReturnIfNillMacro(IDCUserViewController);
        [strongSelf performChangesWithObject:model];
        
    }           forState:kIDCModelChangeState
                    object:self];
    
    [arrayModel addHandler:^(IDCStateModel *model){
        IDCStrongifyReturnIfNillMacro(IDCUserViewController);
        IDCUserView *rootView = strongSelf.rootView;
        [rootView removeLoadingViewAnimated:YES];
        [rootView.tableView reloadData];
        
    }           forState:kIDCModelLoadedState
                    object:self];
}

- (void)performLoad {
    [self.rootView showLoadingViewWithDefaultTextAnimated:YES];
    [self.arrayModel load];
}

- (void)performChangesWithObject:(IDCStateModel *)object {
    UITableView *tableView = self.rootView.tableView;
    NSIndexPath *indexPath = [NSIndexPath indexPathForRow:object.index inSection:0];
    
    if (object.state == kIDCObjectAddState) {
        [tableView insertRowsAtIndexPaths:[NSArray arrayWithObject:indexPath]
                         withRowAnimation:UITableViewRowAnimationAutomatic];
    } else {
        [tableView deleteRowsAtIndexPaths:[NSArray arrayWithObject:indexPath]
                         withRowAnimation:UITableViewRowAnimationAutomatic];
    }
}

#pragma mark -
#pragma mark UITableViewDataSource protocol


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.arrayModel.objects.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    IDCUserViewCell *cell = [tableView dequeueReusableCellFromNibWithClass:[IDCUserViewCell class]];
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

@end
