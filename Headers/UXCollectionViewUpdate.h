//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//



@class NSArray, NSMutableArray, NSMutableDictionary, NSMutableIndexSet, UXCollectionView, UXCollectionViewData;

@interface UXCollectionViewUpdate : NSObject
{
    UXCollectionView *_collectionView;
    NSArray *_updateItems;
    UXCollectionViewData *_oldModel;
    UXCollectionViewData *_newModel;
    CGRect _oldVisibleBounds;
    CGRect _newVisibleBounds;
    NSMutableIndexSet *_movedItems;
    NSMutableIndexSet *_movedSections;
    NSMutableIndexSet *_deletedSections;
    NSMutableIndexSet *_insertedSections;
    long long *_oldSectionMap;
    long long *_newSectionMap;
    long long *_oldGlobalItemMap;
    long long *_newGlobalItemMap;
    NSMutableArray *_deletedSupplementaryIndexesSectionArray;
    NSMutableArray *_insertedSupplementaryIndexesSectionArray;
    NSMutableDictionary *_deletedSupplementaryTopLevelIndexesDict;
    NSMutableDictionary *_insertedSupplementaryTopLevelIndexesDict;
    NSMutableArray *_viewAnimations;
    NSMutableArray *_gaps;
}

- (id)oldIndexPathForSupplementaryElementOfKind:(id)arg1 newIndexPath:(NSIndexPath *)indexPath;
- (id)newIndexPathForSupplementaryElementOfKind:(id)arg1 oldIndexPath:(NSIndexPath *)indexPath;
- (void)_computeGaps;
- (void)_computeSupplementaryUpdates;
- (void)_computeItemUpdates;
- (void)_computeSectionUpdates;
- (void)dealloc;
- (id)initWithCollectionView:(id)arg1 updateItems:(id)arg2 oldModel:(id)arg3 newModel:(id)arg4 oldVisibleBounds:(CGRect)arg5 newVisibleBounds:(CGRect)arg6;

@end

