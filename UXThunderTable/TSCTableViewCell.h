//
//  TSCTableViewCell.h
//  American Red Cross Disaster
//
//  Created by Phillip Caudell on 16/08/2013.
//  Copyright (c) 2013 madebyphill.co.uk. All rights reserved.
//

@interface TSCTableViewCell : UXTableViewCell

@property (nonatomic, weak) UXViewController *parentViewController;
@property (nonatomic, strong) NSIndexPath *currentIndexPath;
@property (nonatomic, strong) NSView *separatorTopView;
@property (nonatomic, strong) NSView *separatorBottomView;
@property (nonatomic, assign) BOOL shouldDisplaySeparators;
@property (nonatomic, strong) UXImageView *imageView;

@end
