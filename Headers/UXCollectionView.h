//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//


@import AppKit;

#import "UXCollectionViewLayout.h"
#import "UXCollectionViewDelegate-Protocol.h"
#import "UXCollectionViewDataSource-Protocol.h"
#import "UXCollectionDocumentView.h"

typedef NS_OPTIONS(NSUInteger, UXCollectionViewScrollPosition) {
    UXCollectionViewScrollPositionNone                 = 0,
    
    // The vertical positions are mutually exclusive to each other, but are bitwise or-able with the horizontal scroll positions.
    // Combining positions from the same grouping (horizontal or vertical) will result in an NSInvalidArgumentException.
    UXCollectionViewScrollPositionTop                  = 1 << 0,
    UXCollectionViewScrollPositionCenteredVertically   = 1 << 1,
    UXCollectionViewScrollPositionBottom               = 1 << 2,
    
    // Likewise, the horizontal positions are mutually exclusive to each other.
    UXCollectionViewScrollPositionLeft                 = 1 << 3,
    UXCollectionViewScrollPositionCenteredHorizontally = 1 << 4,
    UXCollectionViewScrollPositionRight                = 1 << 5
};

NS_ASSUME_NONNULL_BEGIN

@class CALayer, NSArray, NSIndexPath, NSMutableArray, NSMutableDictionary, NSMutableSet, UXCollectionDocumentView, UXCollectionViewLayout, UXCollectionViewUpdate, _UXCollectionViewRearrangingCoordinator, UXCollectionViewCell, UXCollectionReusableView;

@interface UXCollectionView : NSScrollView

+ (Class)documentClass;

@property(readonly, nonatomic, getter=isDecelerating) BOOL decelerating;

@property(readonly, nonatomic, getter=isScrolling) BOOL scrolling;

@property(nonatomic) BOOL allowsPaintingSelection;

@property(nonatomic) BOOL allowsLassoSelection;

@property(nonatomic) BOOL allowsContinuousSelection;

@property(retain, nonatomic) UXCollectionViewLayout * _Nullable collectionViewLayout;

- (BOOL)lassoInvertsSelection;

- (void)setLassoInvertsSelection:(BOOL)invertsSelection;

- (BOOL)accessibilityPerformPressWithItemAtIndexPath:(NSIndexPath *)indexPath;

- (id)accessibilityChildren;

- (id)accessibilityContentSiblingCellFromIndexPath:(NSIndexPath *)indexPath direction:(id)direction;

- (void)_scrollPage:(BOOL)animated;

- (void)_scrollToEnd:(BOOL)animated;

- (void)accessibilitySelectItemsAtIndexPaths:(NSArray <NSIndexPath *> *)paths;

- (void)accessibilitySelected:(BOOL)selected itemAtIndexPath:(NSIndexPath *)indexPath;

- (void)performBatchUpdates:(void (^ __nullable)(void))updates completion:(void (^ __nullable)(BOOL finished))completion;

- (void)moveItemAtIndexPath:(NSIndexPath *)indexPath toIndexPath:(NSIndexPath *)indexPath;

- (void)insertItemsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths;

- (void)deleteItemsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths;

- (void)reloadItemsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths;

- (void)insertSections:(NSIndexSet *)sections;

- (void)deleteSections:(NSIndexSet *)sections;

- (void)reloadSections:(NSIndexSet *)sections;

- (void)moveSection:(NSInteger)section toSection:(NSInteger)newSection;

- (void)scrollRect:(CGRect)rect toscrollPosition:(UXCollectionViewScrollPosition)postion withInsets:(NSEdgeInsets)insets animated:(BOOL)animated;

- (void)scrollToItemAtIndexPath:(NSIndexPath *)indexPath atscrollPosition:(UXCollectionViewScrollPosition)postion animated:(BOOL)animated;

- (CGPoint)_scrollAmountForMovingRect:(CGRect)rect toscrollPosition:(UXCollectionViewScrollPosition)position inDestinationRect:(CGRect)destinationRect;

- (NSIndexPath * _Nullable)nextIndexPath:(NSIndexPath *)indexPath;

- (NSIndexPath * _Nullable)previousIndexPath:(NSIndexPath *)indexPath;

- (NSArray <UXView *> *)contentSupplementaryViews;

- (NSArray <UXView *> *)visibleSupplementaryViews;

- (NSArray<NSIndexPath *> * _Nullable)indexPathsForContentItemsInSections:(NSIndexSet *)sections;

- (NSArray<NSIndexPath *> * _Nullable)indexPathsForContentItems;

- (NSArray<NSIndexPath *> * _Nullable)indexPathsForVisibleItemsInSections:(NSIndexSet *)sections;

- (NSArray<NSIndexPath *> * _Nullable)indexPathsForVisibleItems;

- (NSArray<__kindof UXCollectionViewCell *> *)contentCells;

- (NSArray<__kindof UXCollectionViewCell *> *)visibleCells;

- (NSInteger)numberOfContentCells;

- (NSInteger)numberOfVisibleCells;

- (UXCollectionReusableView *)viewForSupplementaryElementOfKind:(NSString *)kind atIndexPath:(NSIndexPath *)indexPath;

- (UXCollectionViewCell *)cellForItemAtIndexPath:(NSIndexPath *)indexPath;

- (NSIndexPath * _Nullable)indexPathForSupplementaryView:(UXCollectionReusableView *)view;

- (NSIndexPath * _Nullable)indexPathForCell:(UXCollectionViewCell *)cell;

- (NSIndexPath * _Nullable)indexPathForSupplementaryElementOfKind:(NSString *)kind atPoint:(CGPoint)point;

- (NSIndexPath * _Nullable)indexPathForSupplementaryElementOfKind:(NSString *)kind hitByEvent:(NSEvent *)event;

- (NSIndexPath * _Nullable)indexPathForItemAtPoint:(CGPoint)point;

- (NSIndexPath * _Nullable)indexPathForItemHitByEvent:(NSEvent *)event;

- (id _Nullable)layoutAttributesForSupplementaryElementOfKind:(NSString *)kind atIndexPath:(NSIndexPath *)indexPath;

- (id _Nullable)layoutAttributesForItemAtIndexPath:(NSIndexPath *)indexPath;

- (NSInteger)numberOfItemsInSection:(NSInteger)section;

- (NSInteger)numberOfSections;

- (void)resetScrollingOverdraw;

- (CGRect)documentContentRect;

- (void)updateLayout;

- (void)setCollectionViewLayout:(UXCollectionViewLayout *)layout animated:(BOOL)animated completion:(void (^ __nullable)(void))completion;

- (void)setCollectionViewLayout:(UXCollectionViewLayout *)layout animated:(BOOL)animated;

- (UXCollectionReusableView *)dequeueReusableSupplementaryViewOfKind:(NSString *)kind withReuseIdentifier:(NSString *)reuseIdentifier forIndexPath:(NSIndexPath *)indexPath;

- (UXCollectionViewCell *)dequeueReusableCellWithReuseIdentifier:(NSString *)reuseIdentifier forIndexPath:(NSIndexPath *)indexPath;

- (void)registerNib:(NSNib *)nib forSupplementaryViewOfKind:(NSString *)kind withReuseIdentifier:(NSString *)reuseIdentifier;

- (void)registerClass:(Class)viewClass forSupplementaryViewOfKind:(NSString *)kind withReuseIdentifier:(NSString *)reuseIdentifier;

- (Class)registeredClassForSupplementaryViewOfKind:(NSString *)kind withReuseIdentifier:(NSString *)reuseIdentifier;

- (void)registerNib:(NSNib *)nib forCellWithReuseIdentifier:(NSString *)reuseIdentifier;

- (void)registerClass:(Class)viewClass forCellWithReuseIdentifier:(NSString *)reuseIdentifier;

- (Class)registeredClassForCellWithReuseIdentifier:(NSString *)reuseIdentifier;

- (CGSize)contentSizeForFrameSize:(CGSize)frameSize;

- (CGSize)frameSizeForContentSize:(CGSize)contentSize;

- (void)windowDidChangeBackingProperties:(id)properties;

- (void)clipViewBoundsDidChange:(NSNotification *)change;

- (void)scrollViewDidEndLiveScrollNotification:(NSNotification *)notification;

- (void)scrollViewWillStartLiveScrollNotification:(NSNotification *)notification;

- (void)setContentOffset:(CGPoint)offset animated:(BOOL)animated;

- (void)setContentOffset:(CGPoint)offset;

- (void)setDocumentBounds:(CGRect)bounds;

- (CGRect)documentBounds;

- (CGSize)documentSize;

- (CGPoint)contentOffset;

- (CGPoint)layoutPointForCollectionViewPoint:(CGPoint)viewPoint;

- (CGPoint)collectionViewPointForLayoutPoint:(CGPoint)layoutPoint;

- (BOOL)isBusy;

- (void)reloadData;

- (void)setNeedsLayout;

@property (nonatomic) BOOL allowsEmptySelection;
@property (nonatomic) BOOL allowsMultipleSelection;
@property (nonatomic) BOOL allowsSelection;

- (void)deselectAllItems:(BOOL)animated;

- (void)selectAllItems:(BOOL)animated;

- (void)deselectItemsAtIndexPaths:(NSArray <NSIndexPath *> *)indexPaths animated:(BOOL)animated;

- (void)deselectItemAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;

- (void)selectItemsAtIndexPaths:(NSArray <NSIndexPath *> *)indexPaths byExtendingSelection:(BOOL)extend animated:(BOOL)animated scrollItemAtIndex:(NSIndexPath *)index toPosition:(UXCollectionViewScrollPosition)position;

- (void)selectItemsAtIndexPaths:(NSArray <NSIndexPath *> *)indexPaths byExtendingSelection:(BOOL)extend animated:(BOOL)animated;

- (void)selectItemAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated scrollPosition:(UXCollectionViewScrollPosition)position;

- (BOOL)selectedItemAtIndexPath:(NSIndexPath *)indexPath;

- (BOOL)selectableItemAtIndexPath:(NSIndexPath *)indexPath;

- (unsigned long long)numberOfSelectedItems;

- (NSArray <NSIndexPath *> * _Nullable)indexPathsForSelectedItems;

@property (nonatomic, weak, nullable) NSObject<UXCollectionViewDataSource> *dataSource;
@property (nonatomic, weak, nullable) NSObject<UXCollectionViewDelegate> *delegate;

- (id)initWithFrame:(CGRect)frame collectionViewLayout:(UXCollectionViewLayout *)layout;

- (void)draggingSession:(id)session endedAtPoint:(CGPoint)point operation:(unsigned long long)operation;

- (void)draggingSession:(id)session movedToPoint:(CGPoint)point;

- (void)draggingSession:(id)session willBeginAtPoint:(CGPoint)point;

- (unsigned long long)draggingSession:(id)session sourceOperationMaskForDraggingContext:(long long)context;

@property(readonly, nonatomic) BOOL isRearranging_;

@property(nonatomic) double rearrangingPreviewDelay_;

@property(nonatomic) BOOL rearrangingContinuouslyUpdateInsideCells_;

@property(nonatomic) long long rearrangingInitiationMode_;

@property(nonatomic) BOOL rearrangingExternalDropEnabled_;

@property(nonatomic) BOOL rearrangingAllowAutoscroll_;

@property(nonatomic) BOOL rearrangingEnabled_;

- (id)_rearrangingCoordinator;

@end

@interface NSIndexPath (UXCollectionViewAdditions)

+ (NSIndexPath *)indexPathForItem:(NSInteger)item inSection:(NSInteger)section;

@property(readonly, nonatomic) NSUInteger section;

@property(readonly, nonatomic) NSUInteger item;

@end

NS_ASSUME_NONNULL_END


