//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@import AppKit;

@class NSString, UXView, UXViewController;

@protocol UXViewControllerContextTransitioning <NSObject>
- (CGRect)finalFrameForViewController:(UXViewController *)arg1;
- (CGRect)initialFrameForViewController:(UXViewController *)arg1;
- (UXViewController *)viewControllerForKey:(NSString *)arg1;
- (void)completeTransition:(BOOL)arg1;
- (void)cancelInteractiveTransition;
- (void)finishInteractiveTransition;
- (void)updateInteractiveTransition:(double)arg1;
- (long long)presentationStyle;
- (BOOL)transitionWasCancelled;
- (BOOL)isInteractive;
- (BOOL)isAnimated;
- (UXView *)containerView;
@end

