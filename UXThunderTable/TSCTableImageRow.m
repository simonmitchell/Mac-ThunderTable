//
//  TSCTableImageRow.m
//  American Red Cross Disaster
//
//  Created by Phillip Caudell on 29/08/2013.
//  Copyright (c) 2013 madebyphill.co.uk. All rights reserved.
//

#import "TSCTableImageRow.h"
#import "TSCTableImageViewCell.h"

@implementation TSCTableImageRow

+ (id)rowWithImage:(NSImage *)image
{
    TSCTableImageRow *row = [[TSCTableImageRow alloc] init];
    row.image = image;
    
    return row;
}

+ (id)rowWithImageURL:(NSURL *)url placeholderImage:(NSImage *)placeholderImage
{
    TSCTableImageRow *row = [[TSCTableImageRow alloc] init];
    row.image = placeholderImage;
    row.imageURL = url;
    
    return row;
}

+ (id)rowWithImage:(NSImage *)image contentMode:(long long)contentMode
{
    TSCTableImageRow *row = [[TSCTableImageRow alloc] init];
    row.image = image;
    row.contentMode = contentMode;
    
    return row;
}

+ (id)rowWithImage:(NSImage *)image backgroundColor:(NSColor *)backgroundColor
{
    TSCTableImageRow *row = [[TSCTableImageRow alloc] init];
    row.image = image;
    row.backgroundColor = backgroundColor;
    
    return row;
}

- (NSImage *)rowImage
{
    return self.image;
}

- (CGFloat)tableViewCellHeightConstrainedToContentViewSize:(CGSize)contentViewSize tableViewSize:(CGSize)tableViewSize
{
    CGFloat scaleFactor = self.image.size.width / tableViewSize.width;
    
    return self.image.size.height / scaleFactor;
}

- (Class)tableViewCellClass
{
    return [TSCTableImageViewCell class];
}

- (TSCTableViewCell *)tableViewCell:(TSCTableViewCell *)cell
{
    cell.cellImageView.backgroundColor = self.backgroundColor;
    cell.cellImageView.contentMode = self.contentMode;
    
    return cell;
}

@end
