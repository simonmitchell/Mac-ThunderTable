//
//  UXSourceList-Protocol.h
//  UXThunderTable
//
//  Created by Simon Mitchell on 09/05/2015.
//  Copyright (c) 2015 3SidedCube. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "UXNavigationDestination-Protocol.h"

@protocol UXSourceList <NSObject>

@property (readonly) CGFloat maxSourceListWidth;

@property (readonly) CGFloat minSourceListWidth;

@property BOOL collapsed;

- (void)updateSelection;

- (void)selectNavigationDestination:(id <UXNavigationDestination> _Nonnull)destination;

@end
