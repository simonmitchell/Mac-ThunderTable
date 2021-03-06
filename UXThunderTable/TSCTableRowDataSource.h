//
//  TSCTableRowDatasource.h
//  American Red Cross Disaster
//
//  Created by Phillip Caudell on 16/08/2013.
//  Copyright (c) 2013 madebyphill.co.uk. All rights reserved.
//

@import Foundation;
#import "UXKit.h"

@class TSCLink, TSCTableViewCell;
@protocol TSCTableRowDataSource;

typedef void (^TSCTableViewSelectionHandler)(id <TSCTableRowDataSource> row, UXTableViewCell *cell, UXCollectionView *tableView, NSIndexPath *indexPath);

/**
 All objects that can be displayed in a `TSCTableViewController` must conform to the `TSCTableRowDataSource` protocol. This protocol is useful for defininig how a object should represent itself in a tableview without the need to build a custom cell for display in a number of circumstances
 */
@protocol TSCTableRowDataSource <NSObject>

@required

///---------------------------------------------------------------------------------------
/// @name General setup
///---------------------------------------------------------------------------------------

/**
 @abstract The text to be displayed in the cells `textLabel`
 */
- (NSString *)rowTitle;

@optional

/**
 @abstract The text to be displayed in the cells `detailTextLabel`
 */
- (NSString *)rowSubtitle;

/**
 @abstract The `UIImage` to be displayed in the cell
 */
- (NSImage *)rowImage;

/**
 @abstract The URL of the image to be loaded into the image area of the cell
 */
- (NSURL *)rowImageURL;

/**
 @abstract The placeholder image that is displayed whilst the cell is asynchronously loading the image defined by the `imageURL`
 */
- (NSImage *)rowImagePlaceholder;

///---------------------------------------------------------------------------------------
/// @name Overriding cell layout behaviour
///---------------------------------------------------------------------------------------

/**
 @abstract The `Class` to override the UITableViewCell with when displaying the row.
 @discussion Provide a custom class to have `TSCTableViewController` use this class when rendering the row in the table view
 */
- (Class)tableViewCellClass;

/**
 @abstract This method delivers the `cell` which has been rendered based on the other methods in the protocol.
 @discussion This is the last chance to further customise the cell before it is rendered in the `TSCTableViewController`
 @param cell The cell that will be rendered, please return this when you are finished customising
 @note If you have overidden the class used by the row, this method will return a cell of that class type
 */
- (TSCTableViewCell *)tableViewCell:(TSCTableViewCell *)cell;

/**
 @abstract Define a custom height for the cell to be rendered to
 @param constrainedSize The size of the contentView in the cell
 @warning This method is deprecated, please use `tableViewCellHeightConstrainedToContentViewSize:tableViewSize:`
 */
- (CGFloat)tableViewCellHeightConstrainedToSize:(CGSize)contrainedSize DEPRECATED_ATTRIBUTE;

/**
 @abstract Define a custom height for the cell to be rendered to
 @param constrainedSize The size of the contentView in the cell
 @param tableViewSize The size of the tableView that the cell will be rendered in.
 */
- (CGFloat)tableViewCellHeightConstrainedToContentViewSize:(CGSize)contentViewSize tableViewSize:(CGSize)tableViewSize;

/**
 @abstract The level of indentation to enable in the cell
 @discussion The default value is `0`
 */
- (NSInteger)indentationLevel;

/**
 @abstract The type of accessory to be shown on the cell if the row is selectable
 */
- (long long)rowAccessoryType;

/**
 @abstract The amount of padding to add above and below the contents of the cell.
 @discussion You may find that adjusting this padding value on the cell improves the look and feel of your app
 */
- (float)rowPadding;

///---------------------------------------------------------------------------------------
/// @name Optimizing performance
///---------------------------------------------------------------------------------------

/**
 @abstract Provide an estimated cell height to improve tableView loading performance where possible
 */
- (CGFloat)tableViewCellEstimatedHeight;

///---------------------------------------------------------------------------------------
/// @name Selection and editing behaviour
///---------------------------------------------------------------------------------------

/**
 @abstract A boolean indicating whether or not the cell should allow editing
 */
- (BOOL)canEditRow;

/**
 @abstract The block to be called when the user selects the row
 */

- (TSCTableViewSelectionHandler)rowSelectionHandler;

/**
 @abstract The link that a row should attempt to push when selected
 */
- (TSCLink *)rowLink;

/**
 @abstract A boolean indicating if the cell should display the accessory view.
 @note This is only respected if the row selection target and row selector are both not nil. Otherwise neither are displayed
 */
- (BOOL)shouldDisplaySelectionIndicator;

/**
 @abstract A boolean indicating if the cell should display the highlight state for selection
 @note This is only respected if the row selection target and row selector are both not nil. Otherwise neither are displayed
 */
- (BOOL)shouldDisplaySelectionCell;

/**
 @abstract A boolean indicating if the cell should display remain selected after being tapped
 */
- (BOOL)shouldRemainSelected;

/**
 @abstract A boolean indicating if the cell should display the seperator between itself and it's surrounding cells
 */
- (BOOL)shouldDisplaySeperator;

@end