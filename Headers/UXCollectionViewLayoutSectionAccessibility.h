//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@import  AppKit;

@class NSArray, UXCollectionView, UXCollectionViewLayoutAccessibility;

@interface UXCollectionViewLayoutSectionAccessibility : NSAccessibilityElement
{
    NSArray *_accessibilityVisibleChildren;
}

- (void)setAccessibilityVisibleChildren:(id)arg1;
- (void)cxx_destruct;
- (id)description;
- (BOOL)accessibilityPerformScrollToVisible;
- (void)accessibilityPerformAction:(id)arg1;
- (id)accessibilityActionDescription:(id)arg1;
- (id)accessibilityActionNames;
- (id)accessibilityAttributeValue:(id)arg1;
- (id)accessibilityAttributeNames;
- (id)accessibilityArrayAttributeValues:(id)arg1 index:(unsigned long long)arg2 maxCount:(unsigned long long)arg3;
- (unsigned long long)accessibilityArrayAttributeCount:(id)arg1;
- (unsigned long long)accessibilityIndexOfChild:(id)arg1;
- (id)accessibilityVisibleChildren;
- (id)accessibilityChildren;
- (CGRect)accessibilityFrame;
- (id)accessibilitySubrole;
- (id)accessibilityRole;
- (id)accessibilityHitTest:(CGPoint)arg1;
- (long long)compare:(id)arg1;
- (id)_siblingInDirection:(unsigned long long)arg1 item:(id)arg2;
- (id)siblingBelowItem:(id)arg1;
- (id)siblingAboveItem:(id)arg1;
- (id)siblingAfterItem:(id)arg1;
- (id)siblingBeforeItem:(id)arg1;
- (id)visibleCellsInSection:(unsigned long long)arg1;
- (id)visibleSupplementaryViewsInSection:(unsigned long long)arg1;
- (void)_dumpVisibleChildren;
- (void)accessibilityPrepareLayout;
- (void)accessibilityInvalidateLayout;
- (void)accessibilityPrepareForCollectionViewUpdates;
- (void)accessibilityDidEndScrolling;
@property(readonly, nonatomic) unsigned long long sectionIndex;
@property(readonly, nonatomic) __weak UXCollectionView *collectionView;
@property(readonly, nonatomic) __weak UXCollectionViewLayoutAccessibility *layoutAccessibility;
- (id)initWithLayoutAccessibility:(id)arg1;

@end

