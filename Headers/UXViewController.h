//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@import AppKit;

#import "UXLayoutSupport-Protocol.h"
#import "CDStructures.h"

@class NSArray, NSResponder, NSString, UXNavigationController, UXNavigationItem, UXSourceController, UXTabBarItem, UXView;

@interface UXViewController : NSViewController
{
    UXNavigationItem *_navigationItem;
    UXTabBarItem *_tabBarItem;
    UXViewController *_accessoryViewController;
    NSArray *_accessoryBarItems;
    UXViewController *_toolbarViewController;
    NSArray *_toolbarItems;
    BOOL _hidesBottomBarWhenPushed;
    CGSize _ux_preferredContentSize;
    BOOL _viewDidLoad;
    BOOL _ignoreViewController;
    id <UXLayoutSupport> _topLayoutGuide;
    id <UXLayoutSupport> _bottomLayoutGuide;
    BOOL _isEditing;
    BOOL _automaticallyAdjustsScrollViewInsets;
    long long _modalPresentationStyle;
    unsigned long long _edgesForExtendedLayout;
    UXView *_presentedViewControllerContainerView;
}

+ (Class)viewClass;
@property(retain, nonatomic) UXView *presentedViewControllerContainerView; // @synthesize presentedViewControllerContainerView=_presentedViewControllerContainerView;
@property(nonatomic) BOOL automaticallyAdjustsScrollViewInsets; // @synthesize automaticallyAdjustsScrollViewInsets=_automaticallyAdjustsScrollViewInsets;
@property(nonatomic) unsigned long long edgesForExtendedLayout; // @synthesize edgesForExtendedLayout=_edgesForExtendedLayout;
@property(nonatomic) long long modalPresentationStyle; // @synthesize modalPresentationStyle=_modalPresentationStyle;
@property(nonatomic) BOOL isEditing; // @synthesize isEditing=_isEditing;
- (void)cxx_destruct;
- (id)menuForEvent:(id)arg1;
- (id)bottomLayoutGuide;
- (id)topLayoutGuide;
- (void)_setupLayoutGuidesForView:(id)arg1;
- (void)didUpdateLayoutGuides;
- (void)invalidateIntrinsicLayoutInsets;
- (NSEdgeInsets)intrinsicLayoutInsets;
- (CGSize)preferredContentSizeCappedToSize:(CGSize)arg1;
@property CGSize preferredContentSize;
- (BOOL)_requiresWindowForTransitionPreparation;
- (id)_ancestorViewControllerOfClass:(Class)arg1;
- (void)_animateView:(id)arg1 fromFrame:(CGRect)arg2 toFrame:(CGRect)arg3;
- (id)transitionCoordinator;
- (void)setEditing:(BOOL)arg1 animated:(BOOL)arg2;
- (void)dismissViewControllerAnimated:(BOOL)arg1 completion:(CDUnknownBlockType)arg2;
- (void)presentViewController:(id)arg1 animated:(BOOL)arg2 completion:(CDUnknownBlockType)arg3;
@property(readonly, nonatomic) UXViewController *presentedViewController;
- (void)didMoveToParentViewController:(id)arg1;
- (void)willMoveToParentViewController:(id)arg1;
- (void)removeFromParentViewController;
- (void)removeChildViewControllerAtIndex:(long long)arg1;
- (void)addChildViewController:(id)arg1;
- (void)viewDidLiveResize;
- (void)viewWillLiveResize;
- (void)viewDidLayoutSubviews;
- (void)viewWillLayoutSubviews;
- (void)viewUpdateLayer;
- (void)viewDidDisappear;
- (void)viewWillDisappear;
- (void)viewDidAppear;
- (void)viewWillAppear;
- (void)_sendViewDidLoad;
- (void)loadView;
- (CGRect)_defaultInitialFrame;
- (BOOL)acceptsFirstResponder;
- (void)awakeFromNib;
@property(readonly, nonatomic) NSResponder *preferredFirstResponder;
@property(copy) NSString *title;
- (void)setView:(id)arg1;
@property(readonly, nonatomic) UXView *uxView;
- (void)_loadViewIfNotLoaded;
- (void)_setupResponderChainIfNecessary;
- (void)_prepareForAnimationInContext:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (id)initWithCoder:(id)arg1;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;
- (id)init;
@property(nonatomic) BOOL hidesBottomBarWhenPushed;
- (long long)preferredToolbarPosition;
- (id)toolbarViewController;
- (void)setToolbarViewController:(id)arg1;
- (id)toolbarItems;
- (void)setToolbarItems:(id)arg1 animated:(BOOL)arg2;
- (void)setToolbarItems:(id)arg1;
- (id)accessoryBarItems;
- (void)setAccessoryBarItems:(id)arg1;
- (id)accessoryViewController;
- (void)setAccessoryViewController:(id)arg1;
@property(readonly, nonatomic) UXNavigationItem *navigationItem;
@property(readonly, nonatomic) UXNavigationController *navigationController;
- (id)tabBarController;
- (id)tabBarItem;
- (id)popoverController;
- (void)updateViewConstraints;
- (void)prepareForTransitionWithContext:(id)arg1 completion:(CDUnknownBlockType)arg2;
@property(readonly, nonatomic) long long interfaceOrientation;
- (void)viewDidDisappear:(BOOL)animated;
- (void)viewWillDisappear:(BOOL)animated;
- (void)viewDidAppear:(BOOL)animated;
- (void)viewWillAppear:(BOOL)animated;
@property(nonatomic) BOOL hidesSourceListWhenPushed;
- (BOOL)isTransitory;
- (void)setTransitory:(BOOL)arg1;
- (void)viewControllersForNavigationDestination:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)willEncodeNavigationDestination:(id)arg1;
- (id)navigationDestination;
- (id)navigationIdentifier;
@property(readonly, nonatomic) UXSourceController *sourceController;

@end

