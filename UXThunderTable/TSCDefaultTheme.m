//
//  TSCDefaultTheme.m
//  ThunderStorm
//
//  Created by Phillip Caudell on 26/09/2013.
//  Copyright (c) 2013 3 SIDED CUBE. All rights reserved.
//

#import "TSCDefaultTheme.h"

@implementation TSCDefaultTheme

- (NSColor *)mainColor
{
    return [NSColor colorWithRed:0.894 green:0.000 blue:0.010 alpha:1.000];
}

- (NSColor *)secondaryColor
{
    return [NSColor colorWithWhite:0.25 alpha:1.0];
}

- (NSColor *)primaryLabelColor
{
    return [NSColor blackColor];
}

- (NSColor *)detailLabelColor
{
    return [NSColor darkGrayColor];
}

- (NSColor *)secondaryLabelColor
{
    return [NSColor lightGrayColor];
}

- (NSColor *)backgroundColor
{
    return [NSColor whiteColor];
}

- (NSColor *)freeTextColor
{
    return [NSColor blackColor];
}

- (NSColor *)headerTextColor
{
    return [NSColor blackColor];
}

- (NSColor *)tableCellBackgroundColor
{
    return [NSColor whiteColor];
}

- (NSColor *)tableSeperatorColor
{
    return [NSColor colorWithRed:0.78 green:0.78 blue:0.8 alpha:1];
}

- (NSFont *)primaryLabelFont
{
    return [NSFont systemFontOfSize:[NSFont systemFontSize]];
}

- (NSFont *)secondaryLabelFont
{
    return [NSFont systemFontOfSize:[NSFont systemFontSize]];
}

- (NSFont *)detailLabelFont
{
    return [NSFont systemFontOfSize:[NSFont systemFontSize]];
}

- (NSColor *)defaultTableViewCellBackgroundColor
{
    return [NSColor whiteColor];
}

- (NSColor *)redColor
{
    return [NSColor redColor];
}

- (NSColor *)yellowColor
{
    return [NSColor yellowColor];
}

- (NSColor *)greenColor
{
    return [NSColor greenColor];
}

- (NSColor *)blueColor
{
    return [NSColor blueColor];
}

- (NSColor *)darkBlueColor
{
    return [NSColor colorWithRed:5.0f / 255.0f green:56.0f / 255.0f blue:115.0f / 255.0f alpha:1.0];
}

- (NSColor *)titleTextColor
{
    return [NSColor blackColor];
}

- (NSColor *)disabledCellTextColor
{
    return [NSColor colorWithWhite:0.6 alpha:0.6];
}

@end
