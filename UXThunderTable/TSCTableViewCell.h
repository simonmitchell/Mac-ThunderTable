//
//  TSCTableViewCell.h
//  American Red Cross Disaster
//
//  Created by Phillip Caudell on 16/08/2013.
//  Copyright (c) 2013 madebyphill.co.uk. All rights reserved.
//

#import "UXKit.h"

@interface TSCTableViewCell : UXCollectionViewCell

@property (nonatomic, strong) UXLabel *cellTextLabel;
@property (nonatomic, strong) UXLabel *cellDetailTextLabel;
@property (nonatomic, strong) UXImageView *cellImageView;

@property (nonatomic, weak) UXCollectionViewController *parentViewController;

@property (nonatomic, strong) NSIndexPath *currentIndexPath;
@property (nonatomic, strong) NSView *separatorTopView;
@property (nonatomic, strong) NSView *separatorBottomView;

@property (nonatomic, assign) BOOL shouldDisplaySeparators;

@property (nonatomic, assign) UXTableViewCellStyle style;

- (void)setupViews;

- (NSEdgeInsets)edgeInsets;

@end
