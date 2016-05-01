//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UXCollectionView.h"
#import "UXTableView.h"
#import "UXCollectionViewDataSource-Protocol.h"
#import "UXTableViewCell.h"

@class NSColor, NSIndexPath, NSMenu, UXCollectionView, UXCollectionViewLayout;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UITableViewStyle) {
    UITableViewStylePlain,          // regular table view
    UITableViewStyleGrouped         // preferences style table view
};

typedef NS_ENUM(NSInteger, UITableViewScrollPosition) {
    UITableViewScrollPositionNone,
    UITableViewScrollPositionTop,
    UITableViewScrollPositionMiddle,
    UITableViewScrollPositionBottom
};                // scroll so row of interest is completely visible at top/center/bottom of view

typedef NS_ENUM(NSInteger, UITableViewRowAnimation) {
    UITableViewRowAnimationFade,
    UITableViewRowAnimationRight,           // slide in from right (or out to right)
    UITableViewRowAnimationLeft,
    UITableViewRowAnimationTop,
    UITableViewRowAnimationBottom,
    UITableViewRowAnimationNone,            // available in iOS 3.0
    UITableViewRowAnimationMiddle,          // available in iOS 3.2.  attempts to keep cell centered in the space it will/did occupy
    UITableViewRowAnimationAutomatic = 100  // available in iOS 5.0.  chooses an appropriate animation style for you
};

@interface UXTableView : UXCollectionView

+ (Class)documentClass;

@property(nonatomic, setter=_setFloatingHeadersDisabled:) BOOL _floatingHeadersDisabled;

@property(nonatomic) NSEdgeInsets separatorInset;

@property(copy, nonatomic) NSColor * _Nullable separatorColor;

@property(nonatomic) UITableViewCellSeparatorStyle separatorStyle;

@property(nonatomic) CGFloat rowHeight;

@property(nonatomic, weak) id <UXTableViewDelegate> _Nullable tableViewDelegate;

@property(nonatomic, weak) id <UXTableViewDataSource> _Nullable tableViewDataSource;

@property(nonatomic) CGFloat alpha;

- (void)collectionView:(UXCollectionView *)collectionView layout:(UXCollectionViewLayout *)layout supplementaryViewDidEndFloatingAtIndexPath:(NSIndexPath *)indexPath kind:(NSString *)kind;

- (void)collectionView:(UXCollectionView *)collectionView layout:(UXCollectionViewLayout *)layout supplementaryViewDidBeginFloatingAtIndexPath:(NSIndexPath *)indexPath kind:(NSString *)kind;

- (CGSize)collectionView:(UXCollectionView *)collectionView layout:(UXCollectionViewLayout *)layout sizeForItemAtIndexPath:(NSIndexPath *)indexPath;

- (CGSize)collectionView:(UXCollectionView *)collectionView layout:(UXCollectionViewLayout *)layout referenceSizeForFooterInSection:(NSInteger)section;

- (CGSize)collectionView:(UXCollectionView *)collectionView layout:(UXCollectionViewLayout *)layout referenceSizeForHeaderInSection:(NSInteger)section;

- (void)collectionView:(UXCollectionView *)collectionView itemWasRightClickedAtIndexPath:(NSIndexPath *)indexPath withEvent:(NSEvent *)event;

- (void)deselectRowAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;

- (void)selectRowAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated scrollPosition:(UITableViewScrollPosition)scrollPosition;

- (NSIndexPath * _Nullable)indexPathForSelectedRow;

- (NSIndexPath * _Nullable)indexPathForClickedRow;

- (void)moveRowAtIndexPath:(NSIndexPath *)sourceIndexPath toIndexPath:(NSIndexPath *)destinationIndexPath;

- (void)insertRowsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;

- (void)deleteRowsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;

- (void)reloadRowsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;

- (void)insertSections:(NSIndexSet *)sections withRowAnimation:(UITableViewRowAnimation)animation;

- (void)deleteSections:(NSIndexSet *)sections withRowAnimation:(UITableViewRowAnimation)animation;

- (void)endUpdates;
- (void)beginUpdates;

@property (nonatomic, readonly, nullable) NSArray<NSIndexPath *> *indexPathsForVisibleRows;

- (void)sizeToFit;

- (CGSize)sizeThatFits:(CGSize)size;

- (NSInteger)numberOfRowsInSection:(NSInteger)section;

- (UXCollectionReusableView *)dequeueReusableHeaderFooterViewWithReuseIdentifier:(NSString *)reuseIdentifier forSection:(NSInteger)section;

- (UXTableViewCell *)dequeueReusableCellWithReuseIdentifier:(NSString *)reuseIdentifier forIndexPath:(NSIndexPath *)indexPath;

- (UXTableViewCell *)dequeueReusableCellWithIdentifier:(NSString *)identifier forIndexPath:(NSIndexPath *)indexPath;

- (void)registerClass:(Class)aClass forCellReuseIdentifier:(NSString *)reuseIdentifier;

- (UXTableViewCell *)cellForRowAtIndexPath:(NSIndexPath *)indexPath;

- (BOOL)overdrawEnabled;

- (void)setOverdrawEnabled:(BOOL)overdrawEnabled;

- (id)initWithFrame:(CGRect)frame style:(UITableViewStyle)style;

- (id)initWithFrame:(CGRect)frame collectionViewlayout:(UXCollectionViewLayout *)layout;

@property(nonatomic, getter=isUserInteractionEnabled) BOOL userInteractionEnabled;

@end

@interface NSIndexPath (UXTableView)

+ (id)indexPathForRow:(NSInteger)arg1 inSection:(NSInteger)arg2;

@property(readonly, nonatomic) NSInteger row;

@property(readonly, nonatomic) NSInteger section;

@end

NS_ASSUME_NONNULL_END

