//
//  TSCTheme.h
//  American Red Cross Disaster
//
//  Created by Phillip Caudell on 16/08/2013.
//  Copyright (c) 2013 madebyphill.co.uk. All rights reserved.
//

#import <AppKit/AppKit.h>

@protocol TSCTheme <NSObject>

- (NSColor *)mainColor;
- (NSColor *)secondaryColor;
- (NSColor *)backgroundColor;
- (NSColor *)freeTextColor;
- (NSColor *)headerTextColor;
- (NSColor *)tableCellBackgroundColor;
- (NSColor *)tableSeperatorColor;
- (NSColor *)primaryLabelColor;
- (NSFont *)primaryLabelFont;
- (NSColor *)secondaryLabelColor;
- (NSFont *)secondaryLabelFont;
- (NSColor *)detailLabelColor;
- (NSFont *)detailLabelFont;
- (NSColor *)defaultTableViewCellBackgroundColor;
- (NSColor *)titleTextColor;
- (NSColor *)disabledCellTextColor;
- (NSColor *)redColor;
- (NSColor *)yellowColor;
- (NSColor *)greenColor;
- (NSColor *)blueColor;
- (NSColor *)darkBlueColor;

@end