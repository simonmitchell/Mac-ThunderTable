//
//  TSCThemeManager.m
//  American Red Cross Disaster
//
//  Created by Phillip Caudell on 16/08/2013.
//  Copyright (c) 2013 madebyphill.co.uk. All rights reserved.
//

#import "TSCThemeManager.h"
#import "TSCDefaultTheme.h"

@implementation TSCThemeManager

static id <TSCTheme> sharedController = nil;

+ (id <TSCTheme>)sharedTheme
{
    @synchronized(self) {
        
        if (!sharedController) {
            sharedController = [[TSCDefaultTheme alloc] init];
        }
    }
    
    return sharedController;
}

+ (void)setSharedTheme:(id <TSCTheme>)theme
{
    @synchronized(self) {
        sharedController = theme;
    }
}

+ (NSTextAlignment)localisedTextDirectionForBaseDirection:(NSTextAlignment)textDirection
{
    return textDirection;
}

+ (BOOL)isRightToLeft
{
    return NO;
}

@end