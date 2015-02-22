//
//  TSCTableViewCell.m
//  American Red Cross Disaster
//
//  Created by Phillip Caudell on 16/08/2013.
//  Copyright (c) 2013 madebyphill.co.uk. All rights reserved.
//

#import "TSCTableViewCell.h"
#import "TSCThemeManager.h"

@implementation TSCTableViewCell

- (id)initWithStyle:(long long)style reuseIdentifier:(NSString *)reuseIdentifier
{
    if (self = [super initWithStyle:3 reuseIdentifier:reuseIdentifier]) {
        
        self.textLabel.numberOfLines = 0;
        self.textLabel.backgroundColor = [NSColor clearColor];
        
        self.detailTextLabel.numberOfLines = 0;
        self.detailTextLabel.font = [NSFont systemFontOfSize:14];
        self.detailTextLabel.textColor = [NSColor grayColor];
        
        self.separatorTopView = [NSView new];
        self.separatorTopView.backgroundColor = [[TSCThemeManager sharedTheme] tableSeperatorColor];
        [self.contentView addSubview:self.separatorTopView];
        
        self.separatorBottomView = [NSView new];
        self.separatorBottomView.backgroundColor = [[TSCThemeManager sharedTheme] tableSeperatorColor];
        [self.contentView addSubview:self.separatorBottomView];
        
//        [self.contentView.superview setClipsToBounds:NO];
    }
    
    return self;
}

- (void)layoutSubviews
{
    [super layoutSubviews];
    
    if ([[NSScreen mainScreen] respondsToSelector:@selector(scale)] == YES && [[NSScreen mainScreen] scale] == 1.00) {
        self.separatorTopView.frame = CGRectMake(0, self.bounds.size.height, self.bounds.size.width, 1);
        self.separatorBottomView.frame = CGRectMake(0, 0, self.bounds.size.width, 1);
    } else {
        self.separatorTopView.frame = CGRectMake(0, self.bounds.size.height, self.bounds.size.width, 0.5);
        self.separatorBottomView.frame = CGRectMake(0, 0, self.bounds.size.width, 0.5);
    }
    
    self.shouldDisplaySeparators = true;
}

- (void)setShouldDisplaySeparators:(BOOL)shouldDisplaySeparators
{
    _shouldDisplaySeparators = shouldDisplaySeparators;
    
    self.separatorTopView.alpha = shouldDisplaySeparators ? 1.0 : 0.0;
    self.separatorBottomView.alpha = shouldDisplaySeparators ? 1.0 : 0.0;
}

@end