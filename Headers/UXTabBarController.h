//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UXViewController.h"

@class NSArray, NSSegmentedControl;

NS_ASSUME_NONNULL_BEGIN

@interface UXTabBarController : UXViewController

@property(readonly, nonatomic) NSSegmentedControl *segmentedControl;

@property(nonatomic, weak) UXViewController * _Nullable selectedViewController;

@property(copy, nonatomic) NSArray <UXViewController *> * _Nullable viewControllers;

@property(nonatomic) NSUInteger selectedIndex;

- (void)segmentChanged:(id)change;

@end

NS_ASSUME_NONNULL_END

