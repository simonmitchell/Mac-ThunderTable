//
//  TSCTableImageViewCell.m
//  American Red Cross Disaster
//
//  Created by Phillip Caudell on 26/09/2013.
//  Copyright (c) 2013 madebyphill.co.uk. All rights reserved.
//

#import "TSCTableImageViewCell.h"
#import "TSCThemeManager.h"

@implementation TSCTableImageViewCell

- (void)layoutSubviews
{
    [super layoutSubviews];
    
    self.cellImageView.frame = CGRectMake(0, 0, self.contentView.frame.size.width, self.contentView.frame.size.height);
    self.cellImageView.layer.masksToBounds = YES;
    self.cellImageView.layer.cornerRadius = 7;
}

@end