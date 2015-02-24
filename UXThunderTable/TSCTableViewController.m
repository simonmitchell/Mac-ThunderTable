//
//  TSCTableViewController.m
//  American Red Cross Disaster
//
//  Created by Phillip Caudell on 16/08/2013.
//  Copyright (c) 2013 madebyphill.co.uk. All rights reserved.
//

#import "TSCTableViewController.h"
#import "TSCTableSection.h"
#import "TSCTableRowDataSource.h"
#import "TSCTableViewCell.h"
//#import "TSCTableInputViewCell.h"
//#import "TSCTableInputTextFieldViewCell.h"
//#import "TSCTableInputTextViewViewCell.h"
//#import "TSCTableInputCheckViewCell.h"
//#import "TSCTableInputDatePickerViewCell.h"
//#import "TSCTableInputPickerViewCell.h"
#import "TSCTableRow.h"
#import "TSCThemeManager.h"

@interface TSCTableViewController ()
{
    UXBarButtonItem *TSC_editItem;
    BOOL _isPendingSetDataSource;
    BOOL _didSetupFrame;
    BOOL _viewHasAppearedBefore;
}

@property (nonatomic, strong) NSMutableDictionary *overides;
@property (nonatomic, strong) NSMutableArray *registeredCellClasses;
@property (nonatomic, strong) NSMutableDictionary *dynamicHeightCells;
@property (nonatomic, assign) BOOL viewHasAppeared;

@end

@implementation TSCTableViewController

- (id)initWithStyle:(UXTableViewStyle)style
{
    self = [super initWithStyle:style];
    
    if (self) {
        
        self.style = style;
        self.registeredCellClasses = [NSMutableArray new];
        self.dynamicHeightCells = [NSMutableDictionary dictionary];
        self.shouldMakeFirstTextFieldFirstResponder = YES;
    }
    
    return self;
}

#pragma mark View life cycle

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
//    [self TSC_resignAnyResponders];
    self.viewHasAppeared = false;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    [self.tableView deselectRowAtIndexPath:[self.tableView indexPathForSelectedRow] animated:YES];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    if (!_viewHasAppearedBefore && self.shouldMakeFirstTextFieldFirstResponder) {
        [self TSC_makeFirstTextFieldFirstResponder];
        _viewHasAppearedBefore = YES;
    }
    
    if (self.title) {
        [[NSNotificationCenter defaultCenter] postNotificationName:@"TSCStatEventNotification" object:self userInfo:@{@"type":@"screen", @"name":self.title}];
    }
    
    self.viewHasAppeared = true;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.automaticallyAdjustsScrollViewInsets = YES;
    self.tableView.separatorStyle = 0;
}

-(void)viewDidLayoutSubviews
{
    [super viewDidLayoutSubviews];
    
    if (!_didSetupFrame) {
        
        self.tableView.frame = self.view.bounds;
        _didSetupFrame = YES;
    }
}

#pragma mark Actions

- (void)overideCellAtIndexPath:(NSIndexPath *)indexPath withClass:(Class)overideClass
{
    if (!self.overides) {
        self.overides = [NSMutableDictionary dictionary];
    }
    
    self.overides[indexPath] = overideClass;
}

#pragma mark Refresh

- (void)setRefreshEnabled:(BOOL)refreshEnabled
{
    _refreshEnabled = refreshEnabled;
    
//    if (refreshEnabled) {
//        self.refreshControl = [[UIRefreshControl alloc] init];
//        [self.refreshControl addTarget:self action:@selector(handleRefresh) forControlEvents:UIControlEventValueChanged];
//        [self.tableView addSubview:self.refreshControl];
//    } else {
//        [self.refreshControl removeFromSuperview];
//        self.refreshControl = nil;
//    }
}

- (void)handleRefresh
{
    self.dataSource = self.dataSource;
}

- (void)setRefreshing:(BOOL)refreshing
{
    _refreshing = refreshing;
    
//    if (!refreshing) {
//        [self.refreshControl endRefreshing];
//    } else {
//        [self.refreshControl beginRefreshing];
//    }
}

#pragma mark Datasource

- (void)setDataSource:(NSArray *)dataSource
{
    [self setDataSource:dataSource animated:NO];
}

- (void)setDataSource:(NSArray *)dataSource animated:(BOOL)animated
{
    _dataSource = dataSource;
    
    self.tableView.dataSource = self;
    self.tableView.delegate = self;
    
    if (animated) {
        [self.tableView reloadData];
    } else {
        [self.tableView reloadData];
    }
}

- (NSArray *)flattenedDataSource
{
    NSMutableArray *flattenedDataSource = [NSMutableArray array];
    
    for (id <TSCTableSectionDataSource> section in self.dataSource) {
        
        NSArray *items = [section sectionItems];
        [flattenedDataSource addObjectsFromArray:items];
    }
    
    return flattenedDataSource;
}

#pragma mark UITableViewDataSource methods

- (NSString *)tableView:(UXTableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    TSCTableSection *tableSection = self.dataSource[section];
    
    return tableSection.sectionHeader;
}

- (NSString *)tableView:(UXTableView *)tableView titleForFooterInSection:(NSInteger)section
{
    TSCTableSection *tableSection = self.dataSource[section];
    
    return tableSection.sectionFooter;
}

- (NSInteger)numberOfSectionsInTableView:(UXTableView *)tableView
{
    return self.dataSource.count;
}

- (NSInteger)tableView:(UXTableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    NSObject <TSCTableSectionDataSource> *tableSection = self.dataSource[section];
    
    return tableSection.sectionItems.count;
}

- (Class)TSC_tableViewCellClassForIndexPath:(NSIndexPath *)indexPath
{
    NSObject <TSCTableSectionDataSource> *section = self.dataSource[indexPath.section];
    NSObject <TSCTableRowDataSource> *row = [section sectionItems][indexPath.row];
    
    Class tableViewCellClass = nil;
    
    if (self.overides[indexPath]) {
        return tableViewCellClass = self.overides[indexPath];
    }
    
    if ([row respondsToSelector:@selector(tableViewCellClass)]) {
        tableViewCellClass = [row tableViewCellClass];
    } else {
        tableViewCellClass = [TSCTableViewCell class];
    }
    
    return tableViewCellClass;
}

- (UXTableViewCell *)tableView:(UXTableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    Class tableViewCellClass = [self TSC_tableViewCellClassForIndexPath:indexPath];
    NSString *reuseIdentifier = NSStringFromClass(tableViewCellClass);
    
    // Check if class is registered with table view
    if (![self.registeredCellClasses containsObject:reuseIdentifier]) {
        
        [self.registeredCellClasses addObject:reuseIdentifier];
        [self.tableView registerClass:tableViewCellClass forCellWithReuseIdentifier:reuseIdentifier];
    }
    
    TSCTableViewCell *cell = (TSCTableViewCell *)[self.tableView dequeueReusableCellWithIdentifier:reuseIdentifier forIndexPath:indexPath];
    
    [self TSC_configureCell:cell withIndexPath:indexPath];
    
    return cell;
}

- (void)TSC_configureCell:(TSCTableViewCell *)cell withIndexPath:(NSIndexPath *)indexPath
{
    NSObject <TSCTableSectionDataSource> *section = self.dataSource[indexPath.section];
    NSObject <TSCTableRowDataSource> *row = [section sectionItems][indexPath.row];
    
    cell.currentIndexPath = indexPath;
    cell.detailTextLabel.text = nil;
    cell.textLabel.text = nil;
    cell.imageView.image = nil;
    
    // Setup basic defaults
    if ([row respondsToSelector:@selector(textColor)]) {
        cell.textLabel.textColor = ((TSCTableRow *)row).textColor;
    }
    if ([row respondsToSelector:@selector(rowTitle)]) {
        cell.textLabel.text = [row rowTitle];
    }
    
    if ([row respondsToSelector:@selector(rowSubtitle)]) {
        cell.detailTextLabel.text = [row rowSubtitle];
    }
    
    if ([row respondsToSelector:@selector(indentationLevel)]) {
        cell.indentationLevel = [row indentationLevel];
    }
    
//    if ([row respondsToSelector:@selector(rowImageURL)]) {
//        
//        if ([row respondsToSelector:@selector(rowImagePlaceholder)]) {
//            [cell.imageView setImageURL:[row rowImageURL] placeholderImage:[row rowImagePlaceholder]];
//        } else {
//            [cell.imageView setImageURL:[row rowImageURL] placeholderImage:nil];
//        }
//    }
    
    if ([row respondsToSelector:@selector(rowImage)]) {
        cell.imageView.image = [row rowImage];
    }
    
    if ([self isIndexPathSelectable:indexPath]) {
        
        if (![row respondsToSelector:@selector(shouldDisplaySelectionIndicator)] || [row shouldDisplaySelectionIndicator]) {
            cell.accessoryType = 1;
        } else {
            cell.accessoryType = 0;
        }
        
        if (![row respondsToSelector:@selector(shouldDisplaySelectionCell)] || [row shouldDisplaySelectionCell]) {
            cell.selectionStyle = 3;
        } else {
            cell.selectionStyle = 0;
        }
        
    } else {
        
        cell.accessoryType = 0;
        cell.selectionStyle = 0;
    }
    
//    if ([row conformsToProtocol:@protocol(TSCTableInputRowDataSource)]) {
//        
//        TSCTableInputRow *inputRow = (TSCTableInputRow *)row;
//        TSCTableInputViewCell *inputCell = (TSCTableInputViewCell *)cell;
//        
//        inputCell.inputRow = inputRow;
//        inputCell.delegate = self;
//    }
    
    if ([row respondsToSelector:@selector(rowAccessoryType)]) {
        cell.accessoryType = [row rowAccessoryType];
    }
    
    cell.parentViewController = self;
    
    // So model can perform additional changes if it wants
    if ([row respondsToSelector:@selector(tableViewCell:)]) {
        [row tableViewCell:cell];
    }
    
    if ([cell respondsToSelector:@selector(setShouldDisplaySeparators:)]) {
        if (self.shouldDisplaySeparatorsOnCells) {
            cell.shouldDisplaySeparators = YES;
        } else {
            cell.shouldDisplaySeparators = NO;
        }
    }
    
    if ([row respondsToSelector:@selector(shouldDisplaySeperator)]) {
        cell.shouldDisplaySeparators = [row shouldDisplaySeperator];
    }
}

- (CGFloat)tableView:(UXTableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSObject <TSCTableSectionDataSource> *section = self.dataSource[indexPath.section];
    NSObject <TSCTableRowDataSource> *row = [section sectionItems][indexPath.row];
    
    CGSize contentViewSize = CGSizeMake(self.tableView.frame.size.width, MAXFLOAT);
    
    if ([row respondsToSelector:@selector(tableViewCellHeightConstrainedToSize:)]) {
        
        float height = [row tableViewCellHeightConstrainedToSize:contentViewSize];
        return height;
    } else if ([row respondsToSelector:@selector(tableViewCellHeightConstrainedToContentViewSize:tableViewSize:)]) {
        
        float height = [row tableViewCellHeightConstrainedToContentViewSize:contentViewSize tableViewSize:self.tableView.frame.size];
        return height;
    } else {
        
        float height = [self TSC_dynamicCellHeightWithIndexPath:indexPath];
        return height;
    }
}

- (CGFloat)tableView:(UXTableView *)tableView estimatedHeightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSObject <TSCTableSectionDataSource> *section = self.dataSource[indexPath.section];
    NSObject <TSCTableRowDataSource> *row = [section sectionItems][indexPath.row];
    
    if([row respondsToSelector:@selector(tableViewCellEstimatedHeight)]) {
        return [row tableViewCellEstimatedHeight];
    } else {
        return [self tableView:tableView heightForRowAtIndexPath:indexPath];
    }
}

#pragma mark UITableViewDelegate methods

- (void)tableView:(UXTableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [self.tableView deselectRowAtIndexPath:indexPath animated:YES];
    
    if ([self isIndexPathSelectable:indexPath]) {
        [self TSC_handleTableViewSelectionWithIndexPath:indexPath];
    }
}

- (NSIndexPath *)tableView:(UXTableView *)tableView willSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    return indexPath;
}

- (NSArray *)sectionIndexTitlesForTableView:(UXTableView *)tableView
{
    if (self.shouldDisplayAlphabeticalSectionIndexTitles) {
        return nil;
//        return [[UILocalizedIndexedCollation currentCollation] sectionTitles];
    } else {
        return nil;
    }
}

- (long long)tableView:(UXTableView *)tableView sectionForSectionIndexTitle:(NSString *)title atIndex:(long long)index
{
    return index;
}

- (BOOL)isIndexPathSelectable:(NSIndexPath *)indexPath
{
    NSObject <TSCTableSectionDataSource> *section = self.dataSource[indexPath.section];
    NSObject <TSCTableRowDataSource> *row = [section sectionItems][indexPath.row];
    
    if ([row respondsToSelector:@selector(rowSelectionHandler)]) {
        
        if (row.rowSelectionHandler) {
            return YES;
        }
    }
    
    if ([section respondsToSelector:@selector(sectionSelectionHandler)]) {
        
        if (section.sectionSelectionHandler) {
            return YES;
        }
    }
    
    return NO;
}

- (void)TSC_handleTableViewSelectionWithIndexPath:(NSIndexPath *)indexPath
{
    TSCTableSection *section = self.dataSource[indexPath.section];
    NSObject <TSCTableRowDataSource> *row = section.items[indexPath.row];
    UXTableViewCell *selectedCell = [self.tableView cellForRowAtIndexPath:indexPath];
    
    self.selectedIndexPath = indexPath;
    
    if ([row respondsToSelector:@selector(rowSelectionHandler)]) {
        
        if ([row rowSelectionHandler]) {
            [row rowSelectionHandler](row, selectedCell, indexPath);
        }
        
    } else if ([section respondsToSelector:@selector(sectionSelectionHandler)]) {
        
        if ([section sectionSelectionHandler]) {
            [section sectionSelectionHandler](row, indexPath);
        }
    }
    
//    // If row is an input
//    if ([row conformsToProtocol:@protocol(TSCTableInputRowDataSource)]) {
//        
//        TSCTableInputViewCell *cell = (TSCTableInputViewCell *)[self.tableView cellForRowAtIndexPath:selection.indexPath];
//        
//        if ([cell isKindOfClass:[TSCTableInputCheckViewCell class]]) {
//            
//            TSCTableInputCheckViewCell *checkCell = (TSCTableInputCheckViewCell *)cell;
//            TSCCheckView *checkView = checkCell.checkView;
//            [checkView setOn:!checkView.isOn animated:YES];
//        } else {
//            [self TSC_resignAnyResponders];
//        }
//        
//        if ([cell isKindOfClass:[TSCTableInputTextFieldViewCell class]]) {
//            [cell setEditing:YES animated:YES];
//            [[(TSCTableInputTextFieldViewCell *)cell textField] becomeFirstResponder];
//            [self.tableView scrollToRowAtIndexPath:indexPath atScrollPosition:UITableViewScrollPositionMiddle animated:NO];
//        }
//        
//        if ([cell isKindOfClass:[TSCTableInputTextViewViewCell class]]) {
//            [cell setEditing:YES animated:YES];
//            [[(TSCTableInputTextViewViewCell *)cell textView] becomeFirstResponder];
//            [self.tableView scrollToRowAtIndexPath:indexPath atScrollPosition:UITableViewScrollPositionMiddle animated:NO];
//        }
//        
//        if ([cell isKindOfClass:[TSCTableInputDatePickerViewCell class]] || [cell isKindOfClass:[TSCTableInputPickerViewCell class]]) {
//            
//            [cell setEditing:YES animated:YES];
//            [[(TSCTableInputPickerViewCell *)cell inputView] becomeFirstResponder];
//            [self.tableView scrollToRowAtIndexPath:indexPath atScrollPosition:UITableViewScrollPositionMiddle animated:NO];
//        }
//    }
    
    if ([row respondsToSelector:@selector(shouldRemainSelected)]) {
        if (![row shouldRemainSelected]) {
            [self.tableView deselectRowAtIndexPath:self.selectedIndexPath animated:YES];
        }
    } else {
        [self.tableView deselectRowAtIndexPath:self.selectedIndexPath animated:YES];
    }
}

- (UXTableViewCell *)TSC_dequeueDynamicHeightCellProxyWithIndexPath:(NSIndexPath *)indexPath
{
    Class tableViewCellClass = [self TSC_tableViewCellClassForIndexPath:indexPath];
    
    NSString *classNameString = NSStringFromClass(tableViewCellClass);
    
    UXTableViewCell *cell = self.dynamicHeightCells[classNameString];
    
    if (!cell) {
        cell = [[tableViewCellClass alloc] initWithStyle:UXTableViewCellStyleDefault reuseIdentifier:classNameString];
        self.dynamicHeightCells[classNameString] = cell;
    }
    
    return cell;
}

//- (void)TSC_resignAnyResponders
//{
//    TSCTableInputViewCell *cell = (TSCTableInputViewCell *)[self.tableView cellForRowAtIndexPath:self.selectedIndexPath];
//    [cell setEditing:NO animated:YES];
//}

//- (BOOL)TSC_isPickerRow:(TSCTableInputRow *)row
//{
//    if ([row isKindOfClass:[TSCTableInputPickerRow class]] || [row isKindOfClass:[TSCTableInputDatePickerRow class]]) {
//        return YES;
//    } else {
//        return NO;
//    }
//}

//- (BOOL)TSC_isControlRow:(TSCTableInputRow *)row
//{
//    return NO;
//}

- (CGFloat)TSC_dynamicCellHeightWithIndexPath:(NSIndexPath *)indexPath
{
    TSCTableViewCell *cell = (TSCTableViewCell *)[self TSC_dequeueDynamicHeightCellProxyWithIndexPath:indexPath];
    
    [self TSC_configureCell:cell withIndexPath:indexPath];
    
    cell.frame = CGRectMake(0, 0, self.view.bounds.size.width, 44);
    [cell layoutSubviews];
    
    NSArray *subviews = cell.contentView.subviews;
    CGFloat lowestYValue = 0;
    
    NSView *highestView;
    
    for (NSView *view in subviews) {
        
        if (CGRectGetMaxY(view.frame) < CGRectGetMaxY(highestView.frame)) {
            highestView = view;
        }
        
        if (view.frame.origin.y > lowestYValue) {
            lowestYValue = view.frame.origin.y;
        }
    }
    
    CGFloat cellHeight = CGRectGetMaxY(highestView.frame) + abs(lowestYValue) + 10;
    
    NSObject <TSCTableSectionDataSource> *section = self.dataSource[indexPath.section];
    NSObject <TSCTableRowDataSource> *row = [section sectionItems][indexPath.row];
    
    if ([row respondsToSelector:@selector(rowPadding)]) {
        cellHeight = (cellHeight - 10) + (long)[row rowPadding];
    }
    
    return ceilf(cellHeight);
}

#pragma mark Editing

- (UXBarButtonItem *)editButtonItem
{
    if (!TSC_editItem) {
//        TSC_editItem = [[UXBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemEdit target:self action:@selector(TSC_handleEdit:)];
    }
    
    return TSC_editItem;
}

- (UXBarButtonItem *)editDoneButtonItem
{
//    return [[UXBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemDone target:self action:@selector(TSC_handleEdit:)];
    return nil;
}

- (BOOL)tableView:(UXTableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
    TSCTableSection *section = self.dataSource[indexPath.section];
    NSArray *sectionItems = [section sectionItems];
    NSObject <TSCTableRowDataSource> *row = sectionItems[indexPath.row];
    
    BOOL canEditRow = NO;
    
    if ([row respondsToSelector:@selector(canEditRow)]) {
        canEditRow = [row canEditRow];
    }
    
    return canEditRow;
}

#pragma mark Inputs

- (void)TSC_makeFirstTextFieldFirstResponder
{
    if (self.dataSource.count > 0) {
        
        TSCTableSection *section = self.dataSource[0];
        
        if (section.sectionItems.count > 0) {
            
//            for (TSCTableInputRow *row in section.items) {
            
//                if ([row isKindOfClass:[TSCTableInputTextFieldRow class]]) {
            
//                    NSInteger index = [section.items indexOfObject:row];
//                    [self TSC_handleTableViewSelectionWithIndexPath:[NSIndexPath indexPathForRow:index inSection:0]];
//            
//                    break;
//                }
//            }
        }
    }
}

- (NSArray *)TSC_inputs
{
    NSMutableArray *inputs = [NSMutableArray array];
    
    for (TSCTableSection *section in self.dataSource) {
        
//        for (TSCTableInputRow *row in [section sectionItems]) {
//            if ([row conformsToProtocol:@protocol(TSCTableInputRowDataSource)]) {
//                [inputs addObject:row];
//            }
//        }
    }
    
    return inputs;
}

- (NSDictionary *)inputDictionary
{
    NSMutableDictionary *inputDictionary = [NSMutableDictionary dictionary];
    
//    for (TSCTableInputRow *row in [self TSC_inputs]) {
//        
//        if (!row.inputId) {
//            
//        } else {
//            
//            if (row.value) {
//                [inputDictionary setObject:row.value forKey:row.inputId];
//            } else {
//                [inputDictionary setObject:[NSNull null] forKey:row.inputId];
//            }
//        }
//    }
    
    return inputDictionary;
}

- (void)setInputDictionary:(NSDictionary *)inputDictionary
{
//    for (TSCTableInputRow *row in [self TSC_inputs]) {
//        
//        row.value = inputDictionary[row.inputId];
//    }
}

- (NSArray *)missingRequiredInputRows
{
    NSMutableArray *rows = [NSMutableArray array];
    
//    [self enumerateInputRowsUsingBlock:^(TSCTableInputRow *inputRow, NSInteger index, NSIndexPath *indexPath, BOOL *stop) {
//        
//        if (inputRow.required) {
//            if (inputRow.value == nil || [inputRow.value isEqual:[NSNull null]]) {
//                [rows addObject:inputRow];
//            }
//        }
//    }];
    
    return rows;
}

- (BOOL)isMissingRequiredInputRows
{
    if (self.missingRequiredInputRows.count == 0) {
        return NO;
    } else {
        return YES;
    }
}

- (void)presentMissingRequiredInputRowsWarning
{
    NSMutableString *requiredFieldNames = [NSMutableString string];
    NSArray *missingRequiredInputRows = self.missingRequiredInputRows;
    
//    [missingRequiredInputRows enumerateObjectsUsingBlock:^(TSCTableInputRow *row, NSUInteger index, BOOL *stop) {
//        
//        if (missingRequiredInputRows.count == 1) {
//            [requiredFieldNames appendFormat:@"%@.", row.title];
//        } else if (index >= missingRequiredInputRows.count - 1) {
//            [requiredFieldNames appendFormat:@"and %@.", row.title];
//        } else {
//            [requiredFieldNames appendFormat:@"%@, ", row.title];
//        }
//    }];
//    
//    UIAlertView *missingRows = [[UIAlertView alloc] initWithTitle:@"Missing information" message:@"Please complete all the required fields." delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
//    [missingRows show];
}

- (void)enumerateRowsUsingBlock:(void (^)(TSCTableRow *row, NSInteger index, NSIndexPath *indexPath, BOOL *stop))block
{
    __block NSInteger index = 0;
    [self.dataSource enumerateObjectsUsingBlock:^(TSCTableSection *section, NSUInteger sectionIndex, BOOL *stopSection) {
        
        [section.items enumerateObjectsUsingBlock:^(TSCTableRow *row, NSUInteger rowIndex, BOOL *stopRow) {
            
            NSIndexPath *indexPath = [NSIndexPath indexPathForRow:rowIndex inSection:sectionIndex];
            block(row, index, indexPath, stopRow);
            *stopSection = * stopRow;
            index++;
            
        }];
    }];
}

//- (void)enumerateInputRowsUsingBlock:(void (^)(TSCTableInputRow *inputRow, NSInteger index, NSIndexPath *indexPath, BOOL *stop))block
//{
//    [self enumerateRowsUsingBlock:^(TSCTableRow *row, NSInteger index, NSIndexPath *indexPath, BOOL *stop) {
//        if ([row isKindOfClass:[TSCTableInputRow class]]) {
//            block((TSCTableInputRow *)row, index, indexPath, stop);
//        }
//    }];
//}

#pragma mark Table view cell input delegate

- (void)tableInputViewCellDidFinish:(TSCTableViewCell *)cell
{
    __block NSInteger selectedRowIndex = -1;
    
//    if ([cell isKindOfClass:[TSCTableInputTextFieldViewCell class]]) {
//        [self textFieldDidReturn:[(TSCTableInputTextFieldViewCell *)cell textField]];
//    }
    
//    [self enumerateInputRowsUsingBlock:^(TSCTableInputRow *inputRow, NSInteger index, NSIndexPath *indexPath, BOOL *stop) {
//        
//        if ([indexPath isEqual:self.selectedIndexPath]) {
//            selectedRowIndex = index;
//        }
//        
//        if (selectedRowIndex == -1) {
//            return;
//        }
//        
//        if (index > selectedRowIndex) {
//            [self TSC_handleTableViewSelectionWithIndexPath:indexPath];
//            *stop = YES;
//        }
//    }];
}

#pragma mark - UITextField delegate

- (void)textFieldDidReturn:(NSTextField *)textField
{
    [textField resignFirstResponder];
}

@end
