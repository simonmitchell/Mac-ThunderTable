//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//



@import  AppKit;

@class NSIndexPath, NSString;

@interface UXCollectionViewLayoutAttributes : NSObject <NSCopying>
{
    unsigned long long _hash;
    NSString *_elementKind;
    NSString *_reuseIdentifier;
    CGRect _frame;
    struct CGPoint _center;
    CGSize _size;
    double _alpha;
    long long _zIndex;
    BOOL _isFloating;
    CGRect _floatingFrame;
    BOOL _isFloatingPinned;
    NSIndexPath *_indexPath;
    NSString *_representedElementKind;
    NSString *_isCloneString;
    struct {
        unsigned int isCellKind:1;
        unsigned int isDecorationView:1;
        unsigned int isHidden:1;
        unsigned int isClone:1;
    } _layoutFlags;
}

+ (id)layoutAttributesForDecorationViewOfKind:(id)arg1 withIndexPath:(NSIndexPath *)indexPath;
+ (id)layoutAttributesForSupplementaryViewOfKind:(id)arg1 withIndexPath:(NSIndexPath *)indexPath;
+ (id)layoutAttributesForCellWithIndexPath:(NSIndexPath *)indexPath;
@property(retain, nonatomic) NSIndexPath *indexPath; // @synthesize indexPath=_indexPath;
@property(nonatomic) BOOL isFloatingPinned; // @synthesize isFloatingPinned=_isFloatingPinned;
@property(nonatomic) CGRect floatingFrame; // @synthesize floatingFrame=_floatingFrame;
@property(nonatomic) BOOL isFloating; // @synthesize isFloating=_isFloating;
@property(nonatomic) long long zIndex; // @synthesize zIndex=_zIndex;
@property(nonatomic) double alpha; // @synthesize alpha=_alpha;
@property(nonatomic) CGSize size; // @synthesize size=_size;
@property(nonatomic) struct CGPoint center; // @synthesize center=_center;
@property(readonly, nonatomic) NSString *representedElementKind; // @synthesize representedElementKind=_representedElementKind;
@property(readonly, nonatomic) unsigned long long representedElementCategory;
- (BOOL)_isSupplementaryView;
- (BOOL)_isDecorationView;
- (BOOL)_isCell;
- (unsigned long long)hash;
- (BOOL)_isTransitionVisibleTo:(id)arg1;
- (BOOL)_isEquivalentTo:(id)arg1;
- (BOOL)isEqual:(id)arg1;
- (id)description;
@property(nonatomic) CGRect frame; // @synthesize frame=_frame;
@property(nonatomic) CGRect bounds;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)_setIndexPath:(NSIndexPath *)indexPath;
- (id)_reuseIdentifier;
- (void)_setReuseIdentifier:(NSString *)reuseIdentifier;
- (id)_elementKind;
- (void)_setElementKind:(id)arg1;
- (BOOL)_isClone;
- (void)_setIsClone:(BOOL)arg1;
@property(nonatomic, getter=isHidden) BOOL hidden;
- (void)dealloc;
- (id)init;

@end

