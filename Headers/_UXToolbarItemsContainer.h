//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UXView.h"
#import "_UXBarItemsContainer-Protocol.h"

@class NSArray, NSMutableArray, NSString;

@interface _UXToolbarItemsContainer : UXView <_UXBarItemsContainer>
{
    NSMutableArray *__addedConstraints;
    BOOL _singleItemMode;
    BOOL _isTransitioning;
    NSArray *_items;
    double _interitemSpacing;
}

+ (id)toolbarItemsContainerForToolbar:(id)arg1 items:(id)arg2;
@property(nonatomic) double interitemSpacing; // @synthesize interitemSpacing=_interitemSpacing;
@property(readonly, nonatomic) NSArray *items; // @synthesize items=_items;
- (void)cxx_destruct;
- (void)updateConstraints;
- (void)prepareForTransistion;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) NSUInteger hash;
@property(readonly) Class superclass;

@end

