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
        
    self.cellImageView = [UXImageView new];
    [self.contentView addSubview:self.cellImageView];
    
    self.cellTextLabel = [UXLabel new];
    self.cellTextLabel.numberOfLines = 0;
    self.cellTextLabel.backgroundColor = [NSColor clearColor];
    self.cellTextLabel.font = [NSFont systemFontOfSize:17];
    self.cellTextLabel.lineBreakMode = NSLineBreakByWordWrapping;
    [self.contentView addSubview:self.cellTextLabel];
    
    self.cellDetailTextLabel = [UXLabel new];
    self.cellDetailTextLabel.numberOfLines = 0;
    self.cellDetailTextLabel.font = [NSFont systemFontOfSize:17];
    self.cellDetailTextLabel.lineBreakMode = NSLineBreakByWordWrapping;
    self.cellDetailTextLabel.textColor = [NSColor grayColor];

    [self.contentView addSubview:self.cellDetailTextLabel];
    
    self.shouldDisplaySeparators = YES;
    
    self.separatorTopView = [UXView new];
    self.separatorTopView.backgroundColor = [[TSCThemeManager sharedTheme] tableSeperatorColor];
    [self addSubview:self.separatorTopView];
    
    self.separatorBottomView = [UXView new];
    self.separatorBottomView.backgroundColor = [[TSCThemeManager sharedTheme] tableSeperatorColor];
    [self addSubview:self.separatorBottomView];
}

- (void)layout
{
    [super layout];
    
    if (self.cellImageView.image) {
        
        [self.cellImageView sizeToFit];
        CGRect imageFrame = self.cellImageView.bounds;
        imageFrame.origin.x = 12;
        self.cellImageView.frame = imageFrame;
        
    } else {
        self.cellImageView.frame = CGRectZero;
    }
    
    switch (self.style) {
        case UXTableViewCellStyleDefault:
            [self subtitleLayout];
            break;
        case UXTableViewCellStyleValue1:
            [self value1Layout];
            break;
        default:
            break;
    }
    
    // Only set the center if we have superview to avoid breaking automatic cell height calculations
    if (self.superview) {
        self.cellImageView.layer.position = CGPointMake(self.cellImageView.layer.position.x, self.cellTextLabel.center.y);
    }
    
    self.separatorTopView.frame = CGRectMake(0, self.contentView.bounds.size.height, self.contentView.bounds.size.width, 0.5);
    self.separatorBottomView.frame = CGRectMake(0, 0, self.contentView.bounds.size.width, 0.5);
}

- (void)value1Layout
{
    NSEdgeInsets edgeInsets = [self edgeInsets];
    
    CGSize textLabelSize = [self.cellTextLabel sizeThatFits:CGSizeMake(self.contentView.frame.size.width - edgeInsets.left - edgeInsets.right, MAXFLOAT)];
    CGRect textLabelFrame = CGRectMake(edgeInsets.left, edgeInsets.bottom, textLabelSize.width, textLabelSize.height);
    
    CGRect detailLabelFrame;
    CGRect slice;
    CGRectDivide(self.contentView.frame, &slice, &detailLabelFrame, textLabelSize.width + edgeInsets.right, CGRectMinXEdge);
    
    CGSize detailLabelSize = [self.cellDetailTextLabel sizeThatFits:CGSizeMake(detailLabelFrame.size.width, MAXFLOAT)];
    detailLabelFrame.size.height = detailLabelSize.height;
    
    NSInteger textNumberOfLines = MAX((int)(textLabelFrame.size.height/[[NSLayoutManager new] defaultLineHeightForFont:self.cellTextLabel.font]),0);
    NSInteger detailNumberOfLines = MAX((int)(detailLabelFrame.size.height/[[NSLayoutManager new] defaultLineHeightForFont:self.cellDetailTextLabel.font]),0);
    
    if (textNumberOfLines == detailNumberOfLines) {
        
        textLabelFrame.origin.y = self.contentView.frame.size.height / 2 - textLabelFrame.size.height / 2;
        detailLabelFrame.origin.y = self.contentView.frame.size.height / 2 - detailLabelFrame.size.height / 2;
    }
    
    self.cellTextLabel.frame = CGRectIntegral(textLabelFrame);
    self.cellDetailTextLabel.frame = CGRectIntegral(detailLabelFrame);
}

- (void)subtitleLayout
{
    NSEdgeInsets edgeInsets = [self edgeInsets];
    
    CGSize detailLabelSize = [self.cellDetailTextLabel sizeThatFits:CGSizeMake(self.contentView.frame.size.width - edgeInsets.left - edgeInsets.right, MAXFLOAT)];
    CGRect detailLabelFrame =  CGRectMake(edgeInsets.left, edgeInsets.bottom, self.contentView.frame.size.width - edgeInsets.left - edgeInsets.right, detailLabelSize.height);
    
    CGSize textLabelSize = [self.cellTextLabel sizeThatFits:CGSizeMake(self.contentView.frame.size.width - edgeInsets.left - edgeInsets.right, MAXFLOAT)];
    CGRect textLabelFrame = CGRectMake(edgeInsets.left, CGRectGetMaxY(detailLabelFrame), self.contentView.frame.size.width - edgeInsets.left - edgeInsets.right, textLabelSize.height);
    
    // If no detail text then center the text label
    if (!self.cellDetailTextLabel.text || [[self.cellDetailTextLabel.text stringByReplacingOccurrencesOfString:@" " withString:@""] isEqualToString:@""]) {
        
        textLabelFrame.origin.y = self.contentView.frame.size.height / 2 - textLabelFrame.size.height / 2;
        
    } else if (self.cellImageView.frame.size.height >= (CGRectGetMaxY(textLabelFrame) - CGRectGetMinY(detailLabelFrame))) { // If image view is larger than both labels put together then centre them
        
        // The required compound rect of both the text + detail text labels
        CGRect compoundRect = CGRectMake(textLabelFrame.origin.x, 0, textLabelFrame.size.width, CGRectGetMaxY(detailLabelFrame) - CGRectGetMinY(textLabelFrame));
        compoundRect.origin.y = self.contentView.frame.size.height / 2 + compoundRect.size.height / 2;
        
        textLabelFrame.origin.y = compoundRect.origin.y;
        detailLabelFrame.origin.y = CGRectGetMaxY(textLabelFrame);
    }

    self.cellTextLabel.frame = (!self.cellTextLabel.text || [[self.cellTextLabel.text stringByReplacingOccurrencesOfString:@" " withString:@""] isEqualToString:@""]) ? CGRectZero : CGRectIntegral(textLabelFrame);
    self.cellDetailTextLabel.frame = (!self.cellDetailTextLabel.text || [[self.cellDetailTextLabel.text stringByReplacingOccurrencesOfString:@" " withString:@""] isEqualToString:@""]) ? CGRectZero : CGRectIntegral(detailLabelFrame);
}

- (NSEdgeInsets)edgeInsets
{
    CGFloat leftIndentation = 12;
    if (self.cellImageView.image) {
        leftIndentation = CGRectGetMaxX(self.cellImageView.frame) + leftIndentation;
    }
    
    NSEdgeInsets edgeInsets = NSEdgeInsetsMake(8, leftIndentation, 8, 12);
    
    return edgeInsets;
}

- (void)setShouldDisplaySeparators:(BOOL)shouldDisplaySeparators
{
    _shouldDisplaySeparators = shouldDisplaySeparators;
    
    self.separatorTopView.alpha = shouldDisplaySeparators ? 1.0 : 0.0;
    self.separatorBottomView.alpha = shouldDisplaySeparators ? 1.0 : 0.0;
}

@end
