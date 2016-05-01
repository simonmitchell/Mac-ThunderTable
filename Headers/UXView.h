//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@import  AppKit;

NS_ASSUME_NONNULL_BEGIN

@class NSArray, NSMutableArray, NSVisualEffectView, UXViewController, UXEventTracker;

typedef NS_ENUM(NSInteger, UIViewAnimationCurve) {
    UIViewAnimationCurveEaseInOut,         // slow at beginning and end
    UIViewAnimationCurveEaseIn,            // slow at beginning
    UIViewAnimationCurveEaseOut,           // slow at end
    UIViewAnimationCurveLinear
};

@interface UXView : NSView

+ (void)animateWithDuration:(double)duration delay:(double)delay usingSpringWithDamping:(double)damping initialSpringVelocity:(double)velocity options:(unsigned long long)options animations:(void (^ __null_unspecified)(void))animations completion:(void (^ __nullable)(BOOL finished))completion;

+ (void)animateWithDuration:(double)duration animations:(void (^ __null_unspecified)(void))animations;

+ (void)animateWithDuration:(double)duration animations:(void (^ __null_unspecified)(void))animations completion:(void (^ __nullable)(BOOL finished))completion;

+ (void)animateWithDuration:(double)duration delay:(double)delay options:(unsigned long long)options animations:(void (^ __null_unspecified)(void))animations completion:(void (^ __nullable)(BOOL finished))completion;

+ (id)defaultSpringAnimationForKey:(NSString * _Nonnull)key mass:(CGFloat)mass stiffness:(CGFloat)stiffness damping:(CGFloat)damping velocity:(CGFloat)velocity;

@property(nonatomic) BOOL accessibilityChildrenHidden;

@property(nonatomic) BOOL userInteractionEnabled;

@property(nonatomic, getter=isExclusiveTouch) BOOL exclusiveTouch;

- (id _Nonnull)snapshotViewFromRect:(CGRect)rect;

- (id _Nonnull)snapshotView;

- (id _Nonnull)snapshotForRect:(CGRect)rect;

- (void)sendSubviewToBack:(NSView * _Nonnull)view;

- (void)bringSubviewToFront:(NSView * _Nonnull)view;

@property(readonly, nonatomic) CGPoint center;

@property(readonly, nonatomic) NSArray *eventTrackers;

- (void)removeEventTracker:(UXEventTracker *)tracker;

- (void)addEventTracker:(UXEventTracker *)tracker;

@property(nonatomic) long long contentMode;

- (BOOL)blurEnabled;

- (void)setBlurEnabled:(BOOL)blur;

@end

NS_ASSUME_NONNULL_END
