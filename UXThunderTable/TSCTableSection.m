//
//  TSCTableSection.m
//  American Red Cross Disaster
//
//  Created by Phillip Caudell on 16/08/2013.
//  Copyright (c) 2013 madebyphill.co.uk. All rights reserved.
//

#import "TSCTableSection.h"

@implementation TSCTableSection

+ (id)sectionWithItems:(NSArray *)items
{
    TSCTableSection *section = [[TSCTableSection alloc] init];
    section.items = items;
    
    return section;
}

+ (id)sectionWithTitle:(NSString *)title footer:(NSString *)footer items:(NSArray *)items selectionHandler:(TSCTableViewSectionSelectionHandler)selectionHandler
{
    TSCTableSection *section = [[TSCTableSection alloc] init];
    section.title = title;
    section.items = items;
    section.selectionHandler = selectionHandler;
    section.footer = footer;
    
    return section;
}

#pragma mark Section data source

- (NSString *)sectionHeader
{
    return self.title;
}

- (NSString *)sectionFooter
{
    return self.footer;
}

- (TSCTableViewSectionSelectionHandler)sectionSelectionHandler
{
    return self.selectionHandler;
}

- (NSArray *)sectionItems
{
    return self.items;
}

@end
