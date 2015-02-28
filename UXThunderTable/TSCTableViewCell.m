//
//  TSCTableViewCell.m
//  American Red Cross Disaster
//
//  Created by Phillip Caudell on 16/08/2013.
//  Copyright (c) 2013 madebyphill.co.uk. All rights reserved.
//

#import "TSCTableViewCell.h"
#import "TSCThemeManager.h"

static CGFloat sideMargin = 12.0;

@interface TSCTableViewCell ()

@end

@implementation TSCTableViewCell

- (id)initWithStyle:(UXTableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    if (self = [super initWithFrame:CGRectZero]) {
        
        self.style = style;
        [self setupViews];
    }
    return self;
}

- (id)initWithFrame:(CGRect)frame
{
    if (self = [super initWithFrame:frame]) {
        
        [self setupViews];
    }
    return self;
}

- (void)setupViews
{
    
    self.textLabel = [UXLabel new];
    self.textLabel.font = [NSFont systemFontOfSize:18];
    self.textLabel.numberOfLines = 0;
    self.textLabel.lineBreakMode = NSLineBreakByWordWrapping;
    self.textLabel.backgroundColor = [NSColor clearColor];
    [self.contentView addSubview:self.textLabel];
    
    self.detailTextLabel = [UXLabel new];
    self.detailTextLabel.font = [NSFont systemFontOfSize:16];
    self.detailTextLabel.numberOfLines = 0;
    self.detailTextLabel.lineBreakMode = NSLineBreakByWordWrapping;
    self.detailTextLabel.numberOfLines = 0;
    self.detailTextLabel.textColor = [NSColor grayColor];
    [self.contentView addSubview:self.detailTextLabel];
    
    self.separatorTopView = [UXView new];
    self.separatorTopView.backgroundColor = [[TSCThemeManager sharedTheme] tableSeperatorColor];
    [self.contentView addSubview:self.separatorTopView];
    
    self.separatorBottomView = [UXView new];
    self.separatorBottomView.backgroundColor = [[TSCThemeManager sharedTheme] tableSeperatorColor];
    [self.contentView addSubview:self.separatorBottomView];
}

- (void)layout
{
    [super layout];
    
    if (self.detailTextLabel.text && ![self.detailTextLabel.text isEqualToString:@""]) {
        
        CGSize detailLabelSize = [self.detailTextLabel sizeThatFits:CGSizeMake(self.frame.size.width - sideMargin*2, MAXFLOAT)];
        self.detailTextLabel.frame = CGRectMake(sideMargin, 12, self.frame.size.width - sideMargin*2, detailLabelSize.height);
        
        CGSize textLabelSize = [self.textLabel sizeThatFits:CGSizeMake(self.frame.size.width - sideMargin*2, MAXFLOAT)];
        self.textLabel.frame = CGRectMake(sideMargin, CGRectGetMaxY(self.detailTextLabel.frame) + 2, self.frame.size.width - sideMargin*2, textLabelSize.height);
    } else {
        
        CGSize textLabelSize = [self.textLabel sizeThatFits:CGSizeMake(self.frame.size.width - sideMargin*2, MAXFLOAT)];
        self.textLabel.frame = CGRectMake(sideMargin, self.frame.size.height - textLabelSize.height - 12, self.frame.size.width - sideMargin*2, textLabelSize.height);
        
        self.detailTextLabel.frame = CGRectZero;
    }
    

    self.separatorTopView.frame = CGRectMake(0, self.contentView.bounds.size.height, self.contentView.bounds.size.width, 0.5);
    self.separatorBottomView.frame = CGRectMake(0, 0, self.bounds.size.width, 0.5);
}

- (void)setShouldDisplaySeparators:(BOOL)shouldDisplaySeparators
{
    _shouldDisplaySeparators = shouldDisplaySeparators;
    
    self.separatorTopView.alpha = shouldDisplaySeparators ? 1.0 : 0.0;
    self.separatorBottomView.alpha = shouldDisplaySeparators ? 1.0 : 0.0;
}

@end
