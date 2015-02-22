//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "_UXViewControllerTransitionContext.h"

@class UXView, UXViewController;

@interface _UXViewControllerOneToOneTransitionContext : _UXViewControllerTransitionContext
{
    UXViewController *_fromViewController;
    UXViewController *_toViewController;
    CGRect _fromStartFrame;
    CGRect _fromEndFrame;
    CGRect _toEndFrame;
    CGRect _toStartFrame;
}

@property(nonatomic) CGRect toStartFrame; // @synthesize toStartFrame=_toStartFrame;
@property(nonatomic) CGRect toEndFrame; // @synthesize toEndFrame=_toEndFrame;
@property(nonatomic) CGRect fromEndFrame; // @synthesize fromEndFrame=_fromEndFrame;
@property(nonatomic) CGRect fromStartFrame; // @synthesize fromStartFrame=_fromStartFrame;
@property(retain, nonatomic) UXViewController *toViewController; // @synthesize toViewController=_toViewController;
@property(retain, nonatomic) UXViewController *fromViewController; // @synthesize fromViewController=_fromViewController;
- (void)cxx_destruct;
@property(readonly, nonatomic) UXView *fromView;
@property(readonly, nonatomic) UXView *toView;
- (CGRect)finalFrameForViewController:(id)arg1;
- (CGRect)initialFrameForViewController:(id)arg1;
- (id)viewControllerForKey:(id)arg1;

@end

