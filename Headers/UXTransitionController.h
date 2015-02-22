//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//



#import "UXViewControllerAnimatedTransitioning-Protocol.h"
#import "UXViewControllerInteractiveTransitioning-Protocol.h"

@class NSString, UXNavigationController;

@interface UXTransitionController : NSObject <UXViewControllerAnimatedTransitioning, UXViewControllerInteractiveTransitioning>
{
    long long _operation;
    double _percentComplete;
}

@property(readonly, nonatomic) double percentComplete; // @synthesize percentComplete=_percentComplete;
@property(nonatomic) long long operation; // @synthesize operation=_operation;
- (BOOL)navigationController:(UXNavigationController *)navigationController shouldBeginInteractivePopFromViewController:(UXViewController *)fromViewController toViewController:(UXViewController *)toViewController;
- (id)navigationController:(UXNavigationController *)navigationController animationControllerForOperation:(long long)arg2 fromViewController:(UXViewController *)fromViewController toViewController:(UXViewController *)toViewController;
- (id)navigationController:(UXNavigationController *)navigationController interactionControllerForAnimationController:(id)arg2;
- (void)animateTransition:(id)arg1;
- (double)transitionDuration:(id)arg1;
- (void)updateInteractiveTransition:(double)arg1 inContext:(id)arg2;
- (void)startInteractiveTransition:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) NSUInteger hash;
@property(readonly) Class superclass;

@end

