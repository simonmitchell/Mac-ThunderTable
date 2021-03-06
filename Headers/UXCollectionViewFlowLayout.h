//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UXCollectionViewLayout.h"

@class NSDictionary, NSMutableDictionary;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UICollectionViewScrollDirection) {
    UICollectionViewScrollDirectionVertical,
    UICollectionViewScrollDirectionHorizontal
};

@interface UXCollectionViewFlowLayout : UXCollectionViewLayout

+ (Class)invalidationContextClass;

@property(nonatomic) NSEdgeInsets sectionInset;

@property(nonatomic) CGSize footerReferenceSize;

@property(nonatomic) CGSize headerReferenceSize;

@property(nonatomic) CGSize itemSize;

@property(nonatomic) CGFloat minimumInteritemSpacing;

@property(nonatomic) CGFloat minimumLineSpacing;

@property(nonatomic) UICollectionViewScrollDirection scrollDirection;

- (NSArray <NSIndexPath *> *)indexPathsForItemsInRect:(CGRect)rect;

- (BOOL)shouldUpdateVisibleCellLayoutAttributes;

- (UXCollectionViewLayoutAttributes *)layoutAttributesForFooterInSection:(NSInteger)section;

- (UXCollectionViewLayoutAttributes *)layoutAttributesForHeaderInSection:(NSInteger)section;

- (UXCollectionViewLayoutAttributes *)layoutAttributesForItemAtIndexPath:(NSIndexPath *)indexPath usingData:(NSData *)data;

- (UXCollectionViewLayoutAttributes *)layoutAttributesForFooterInSection:(NSInteger)section usingData:(NSData *)data;

- (UXCollectionViewLayoutAttributes *)layoutAttributesForHeaderInSection:(NSInteger)section usingData:(NSData *)data;

- (NSIndexPath * _Nullable)indexPathForItemAtPoint:(CGPoint)point;

- (NSArray <UXCollectionViewLayoutAttributes *> * _Nullable)indexesForSectionFootersInRect:(CGRect)rect;

- (NSArray <UXCollectionViewLayoutAttributes *> * _Nullable)indexesForSectionHeadersInRect:(CGRect)rect;

- (NSArray <NSIndexPath *> * _Nullable)indexPathsForItemsInRect:(CGRect)rect usingData:(NSData *)data;

- (id)indexesForSectionFootersInRect:(CGRect)rect usingData:(NSData *)data;

- (id)indexesForSectionHeadersInRect:(CGRect)rect usingData:(NSData *)data;

- (CGSize)synchronizeLayout;

- (UXCollectionViewLayoutAttributes *)finalLayoutAttributesForFooterInDeletedSection:(NSInteger)section;

- (UXCollectionViewLayoutAttributes *)finalLayoutAttributesForHeaderInDeletedSection:(NSInteger)section;

- (UXCollectionViewLayoutAttributes *)finalLayoutAttributesForDeletedItemAtIndexPath:(NSIndexPath *)indexPath;

- (UXCollectionViewLayoutAttributes *)initialLayoutAttributesForFooterInInsertedSection:(NSInteger)section;

- (UXCollectionViewLayoutAttributes *)initialLayoutAttributesForHeaderInInsertedSection:(NSInteger)section;

- (UXCollectionViewLayoutAttributes *)initialLayoutAttributesForInsertedItemAtIndexPath:(NSIndexPath *)indexPath;


@end

NS_ASSUME_NONNULL_END


