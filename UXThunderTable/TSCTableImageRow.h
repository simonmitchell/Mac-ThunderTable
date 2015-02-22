//
//  TSCTableImageRow.h
//  American Red Cross Disaster
//
//  Created by Phillip Caudell on 29/08/2013.
//  Copyright (c) 2013 madebyphill.co.uk. All rights reserved.
//

#import "TSCTableRow.h"

@interface TSCTableImageRow : TSCTableRow

@property (nonatomic, strong) NSImage *image;
@property (nonatomic, strong) NSColor *backgroundColor;
@property (nonatomic) long long contentMode;

+ (id)rowWithImage:(NSImage *)image;
+ (id)rowWithImage:(NSImage *)image contentMode:(long long)contentMode;
+ (id)rowWithImage:(NSImage *)image backgroundColor:(NSColor *)backgroundColor;
+ (id)rowWithImageURL:(NSURL *)url placeholderImage:(NSImage *)placeholderImage;

@end
