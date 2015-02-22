//
//  TSCTableRow.h
//  American Red Cross Disaster
//
//  Created by Phillip Caudell on 16/08/2013.
//  Copyright (c) 2013 madebyphill.co.uk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TSCTableRowDataSource.h"

/**
 `TSCTableRow` is the primary class for creating rows within a `TSCTableViewController`. Each row must be contained within a `TSCTableSection`.
 */
@interface TSCTableRow : NSObject <TSCTableRowDataSource>

///---------------------------------------------------------------------------------------
/// @name Initializing a TSCTableRow Object
///---------------------------------------------------------------------------------------

/**
 Initializes the row with a single title.
 @param title The title to display in the row
 @discussion The title will populate the `textLabel` text property of a `UITableViewCell`
 */
+ (id)rowWithTitle:(NSString *)title;

/**
 Initializes the row with a single title in a custom color
 @param title The title to display in the row
 @param A 'UIColor' to color the text with
 @discussion The title will populate the `textLabel` text property of a `UITableViewCell`. The textColor will be applied to the text.
 */
+ (id)rowWithTitle:(NSString *)title textColor:(NSColor *)textColor;

/**
 Initializes the row with a single title.
 @param title The title to display in the row
 @param subtitle The subtitle to display beneath the title in the row
 @param image The image to be displayed to the left hand side of the cell
 @discussion The title will populate the `textLabel` text property and the subtitle will populate the `detailTextLabel` text property of the `UITableViewCell`
 */
+ (id)rowWithTitle:(NSString *)title subtitle:(NSString *)subtitle image:(NSImage *)image;

/**
 Initializes the row with a single title.
 @param title The title to display in the row
 @param subtitle The subtitle to display beneath the title in the row
 @param selectionHandler The block of code to be called when the cell is selected
 @discussion The title will populate the `textLabel` text property and the subtitle will populate the `detailTextLabel` text property of the `UITableViewCell`
 */
+ (id)rowWithTitle:(NSString *)title subtitle:(NSString *)subtitle selectionHandler:(TSCTableViewSelectionHandler)selectionHandler;

/**
 Initializes the row with a single title.
 @param title The title to display in the row
 @param subtitle The URL of the image to be displayed to the left hand side of the cell. Loaded asynchronously
 @discussion The title will populate the `textLabel` text property and the subtitle will populate the `detailTextLabel` text property of the `UITableViewCell`
 @note Please set the `imagePlaceholder` property when using this method. This is required because the image width and height is used at layout to provide appropriate space for your loaded image.
 */+ (id)rowWithTitle:(NSString *)title subtitle:(NSString *)subtitle imageURL:(NSURL *)imageURL;

/**
 @abstract The text to be displayed in the cells `textLabel`
 */
@property (nonatomic, strong) NSString *title;

/**
 @abstract The text to be displayed in the cells `detailTextLabel`
 */
@property (nonatomic, strong) NSString *subtitle;

/**
 @abstract The `UIImage` to be displayed in the cell
 */
@property (nonatomic, strong) NSImage *image;

/**
 @abstract The URL of the image to be loaded into the image area of the cell
 */
@property (nonatomic, strong) NSURL *imageURL;

/**
 @abstract The placeholder image that is displayed whilst the cell is asynchronously loading the image defined by the `imageURL`
 */
@property (nonatomic, strong) NSImage *imagePlaceholder;

/**
 @abstract The `UIColor` to apply to the text in the cell
 */
@property (nonatomic, strong) NSColor *textColor;

/**
 @abstract The link that a row should attempt to push when selected
 */
@property (nonatomic, strong) TSCLink *link;

///---------------------------------------------------------------------------------------
/// @name Handling selection
///---------------------------------------------------------------------------------------

/**
 @abstract The selection handler for selecting the row
 */
@property (nonatomic, assign) TSCTableViewSelectionHandler selectionHandler;

///---------------------------------------------------------------------------------------
/// @name Row configuration
///---------------------------------------------------------------------------------------

/**
 @abstract A boolean to configure whether the cell shows the selection indicator when it is selectable
 @discussion The default value of this property is `YES`
 */
@property (nonatomic, assign) BOOL shouldDisplaySelectionIndicator;

@end
