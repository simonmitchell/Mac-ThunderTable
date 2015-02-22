//
//  TSCTableRow.m
//  American Red Cross Disaster
//
//  Created by Phillip Caudell on 16/08/2013.
//  Copyright (c) 2013 madebyphill.co.uk. All rights reserved.
//

#import "TSCTableRow.h"
#import "TSCTableViewCell.h"

@implementation TSCTableRow

-(id)init
{
    if (self = [super init]) {
        self.shouldDisplaySelectionIndicator = YES;
    }
    
    return self;
}

+ (id)rowWithTitle:(NSString *)title
{
    TSCTableRow *row = [[TSCTableRow alloc] init];
    row.title = title;
    
    return row;
}

+ (id)rowWithTitle:(NSString *)title textColor:(NSColor *)textColor
{
    TSCTableRow *row = [[TSCTableRow alloc] init];
    row.title = title;
    row.textColor = textColor;
    
    return row;
}

+ (id)rowWithTitle:(NSString *)title subtitle:(NSString *)subtitle image:(NSImage *)image
{
    TSCTableRow *row = [[TSCTableRow alloc] init];
    row.title = title;
    row.subtitle = subtitle;
    row.image = image;
    
    return row;
}

+ (id)rowWithTitle:(NSString *)title subtitle:(NSString *)subtitle imageURL:(NSURL *)imageURL
{
    TSCTableRow *row = [[TSCTableRow alloc] init];
    row.title = title;
    row.subtitle = subtitle;
    row.imageURL = imageURL;
    
    return row;
}

+ (id)rowWithTitle:(NSString *)title subtitle:(NSString *)subtitle selectionHandler:(TSCTableViewSelectionHandler)selectionHandler
{
    TSCTableRow *row = [TSCTableRow rowWithTitle:title subtitle:subtitle image:nil];
    row.selectionHandler = selectionHandler;
    return row;
}

#pragma Table Row Data Source

- (NSString *)rowTitle
{
    return _title;
}

- (NSString *)rowSubtitle
{
    return _subtitle;
}

- (NSImage *)rowImage
{
    return _image;
}

- (NSURL *)rowImageURL
{
    return _imageURL;
}

- (NSImage *)rowImagePlaceholder
{
    return _imagePlaceholder;
}

- (Class)tableViewCellClass
{
    return [TSCTableViewCell class];
}

- (TSCTableViewSelectionHandler)rowSelectionHandler
{
    return self.selectionHandler;
}

- (TSCLink *)rowLink
{
    return self.link;
}

- (BOOL)shouldDisplaySelectionCell
{
    return YES;
}

- (BOOL)shouldDisplaySelectionIndicator
{
    return _shouldDisplaySelectionIndicator;
}

- (UXTableViewCell *)tableViewCell:(UXTableViewCell *)cell;
{
    TSCTableViewCell *standardCell = (TSCTableViewCell *)cell;
    
    if (self.textColor) {
        standardCell.textLabel.textColor = self.textColor;
    }
    
    return standardCell;
}

@end
