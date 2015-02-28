//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UXCollectionViewFlowLayout.h"
@protocol UXCollectionViewDelegateFlowLayout;

@class NSMutableArray, NSMutableDictionary;

@interface UXTableLayout : UXCollectionViewFlowLayout
{
    struct {
        unsigned int delegateSupplementaryViewDidBeginFloating:1;
        unsigned int delegateSupplementaryViewDidEndFloating:1;
        unsigned int delegateRreferenceSizeForHeaderInSection:1;
        unsigned int delegateLayoutInsetForSectionAtIndex:1;
        unsigned int needsDelegateFlagsUpdate:1;
        unsigned int floatingHeadersDisabled:1;
        unsigned int preparingForUpdates:1;
        unsigned int showsSectionHeaderForSingleSection:1;
        unsigned int showsSectionFooterForSingleSection:1;
    } _tableLayoutFlags;
    NSMutableArray *_layoutAttributesArray;
    NSMutableDictionary *_headerAttributesByIndexPath;
}

@property(readonly, nonatomic) NSMutableDictionary *headerAttributesByIndexPath; // @synthesize headerAttributesByIndexPath=_headerAttributesByIndexPath;
@property(readonly, nonatomic) NSMutableArray *layoutAttributesArray; // @synthesize layoutAttributesArray=_layoutAttributesArray;
- (void)cxx_destruct;
- (id)layoutAttributesForSupplementaryViewOfKind:(id)arg1 atIndexPath:(NSIndexPath *)arg2;
- (id)layoutAttributesForElementsInRect:(CGRect)rect;
- (void)invalidateLayoutWithContext:(id)arg1;
- (id)invalidationContextForBoundsChange:(CGRect)arg1;
- (BOOL)shouldInvalidateLayoutForBoundsChange:(CGRect)arg1;
- (void)prepareLayout;
- (BOOL)_wantsHeaderForSection:(unsigned long long)arg1;
- (NSEdgeInsets)insetForSection:(long long)arg1;
@property(nonatomic) BOOL showsSectionFooterForSingleSection;
@property(nonatomic) BOOL showsSectionHeaderForSingleSection;
@property(nonatomic) BOOL floatingHeadersDisabled;
@property(readonly, nonatomic) id <UXCollectionViewDelegateFlowLayout> delegateFlowLayout;
- (void)_setCollectionView:(UXCollectionView *)collectionView;
- (id)init;

@end

