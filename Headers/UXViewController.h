//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@import AppKit;

#import "UXLayoutSupport-Protocol.h"
#import "CDStructures.h"

@class NSArray, NSResponder, NSString, UXNavigationController, UXNavigationItem, UXSourceController, UXTabBarItem, UXView, UXTransitionController, UXBarItem, UXTabBarController, UXPopoverController;

@protocol UXNavigationDestination;

typedef NS_ENUM(NSInteger, UIModalTransitionStyle) {
    UIModalTransitionStyleCoverVertical = 0,
    UIModalTransitionStyleFlipHorizontal,
    UIModalTransitionStyleCrossDissolve,
    UIModalTransitionStylePartialCurl,
};

typedef NS_ENUM(NSInteger, UIModalPresentationStyle) {
    UIModalPresentationFullScreen = 0,
    UIModalPresentationPageSheet,
    UIModalPresentationFormSheet,
    UIModalPresentationCurrentContext,
    UIModalPresentationCustom,
    UIModalPresentationOverFullScreen,
    UIModalPresentationOverCurrentContext,
    UIModalPresentationPopover,
    UIModalPresentationNone = -1,
};

typedef NS_ENUM(NSInteger, UIDeviceOrientation) {
    UIDeviceOrientationUnknown,
    UIDeviceOrientationPortrait,            // Device oriented vertically, home button on the bottom
    UIDeviceOrientationPortraitUpsideDown,  // Device oriented vertically, home button on the top
    UIDeviceOrientationLandscapeLeft,       // Device oriented horizontally, home button on the right
    UIDeviceOrientationLandscapeRight,      // Device oriented horizontally, home button on the left
    UIDeviceOrientationFaceUp,              // Device oriented flat, face up
    UIDeviceOrientationFaceDown             // Device oriented flat, face down
};

typedef NS_ENUM(NSInteger, UIInterfaceOrientation) {
    UIInterfaceOrientationUnknown            = UIDeviceOrientationUnknown,
    UIInterfaceOrientationPortrait           = UIDeviceOrientationPortrait,
    UIInterfaceOrientationPortraitUpsideDown = UIDeviceOrientationPortraitUpsideDown,
    UIInterfaceOrientationLandscapeLeft      = UIDeviceOrientationLandscapeRight,
    UIInterfaceOrientationLandscapeRight     = UIDeviceOrientationLandscapeLeft
};

NS_ASSUME_NONNULL_BEGIN

@interface UXViewController : NSViewController

+ (Class)viewClass;

@property(retain, nonatomic) UXView * _Nullable presentedViewControllerContainerView;

@property(nonatomic) BOOL automaticallyAdjustsScrollViewInsets;

@property(nonatomic) NSRectEdge edgesForExtendedLayout;

@property(nonatomic) UIModalPresentationStyle modalPresentationStyle;

@property(nonatomic) BOOL isEditing;

- (NSMenu * _Nullable)menuForEvent:(NSEvent *)event;

- (id <UXLayoutSupport>)bottomLayoutGuide;

- (id <UXLayoutSupport>)topLayoutGuide;

- (void)didUpdateLayoutGuides;

- (void)invalidateIntrinsicLayoutInsets;

- (NSEdgeInsets)intrinsicLayoutInsets;

- (CGSize)preferredContentSizeCappedToSize:(CGSize)cappedSize;

@property CGSize preferredContentSize;

- (UXTransitionController *)transitionCoordinator;

- (void)setEditing:(BOOL)editing animated:(BOOL)animated;

- (void)dismissViewControllerAnimated:(BOOL)animated completion:(void (^ __nullable)(void))completion;

- (void)presentViewController:(NSViewController *)viewController animated:(BOOL)animated completion:(void (^ __nullable)(void))completion;

@property(readonly, nonatomic) UXViewController * _Nullable presentedViewController;

- (void)didMoveToParentViewController:(NSViewController * _Nullable)viewController;

- (void)willMoveToParentViewController:(NSViewController * _Nullable)viewController;

- (void)removeFromParentViewController;

- (void)removeChildViewControllerAtIndex:(NSInteger)index;

- (void)addChildViewController:(NSViewController *)viewController;

- (void)viewDidLiveResize;

- (void)viewWillLiveResize;

- (void)viewDidLayoutSubviews;

- (void)viewWillLayoutSubviews;

- (void)viewUpdateLayer;

- (void)awakeFromNib;

@property(readonly, nonatomic) NSResponder *preferredFirstResponder;

@property(copy) NSString * _Nullable title;

@property(readonly, nonatomic) UXView * _Nullable uxView;

@property(nonatomic) BOOL hidesBottomBarWhenPushed;

- (NSInteger)preferredToolbarPosition;

- (UXViewController * _Nullable)toolbarViewController;

- (void)setToolbarViewController:(UXViewController * _Nullable)arg1;

- (NSArray <UXBarItem *> * _Nullable)toolbarItems;

- (void)setToolbarItems:(NSArray <UXBarItem *> * _Nullable)items animated:(BOOL)animated;

- (void)setToolbarItems:(NSArray <UXBarItem *> * _Nullable)items;

- (NSArray <UXBarItem *> * _Nullable)accessoryBarItems;

- (void)setAccessoryBarItems:(NSArray <UXBarItem *> * _Nullable)items;

- (UXViewController * _Nullable)accessoryViewController;

- (void)setAccessoryViewController:(UXViewController * _Nullable)accessoryViewController;

@property(readonly, nonatomic) UXNavigationItem * navigationItem;

@property(readonly, nonatomic) UXNavigationController * _Nullable navigationController;

- (UXTabBarController * _Nullable)tabBarController;

- (UXTabBarItem * _Nullable)tabBarItem;

- (UXPopoverController * _Nullable)popoverController;

- (void)updateViewConstraints;

- (void)prepareForTransitionWithContext:(id)context completion:(CDUnknownBlockType)completion;

@property(readonly, nonatomic) UIInterfaceOrientation interfaceOrientation;

- (void)viewDidDisappear:(BOOL)animated;

- (void)viewWillDisappear:(BOOL)animated;

- (void)viewDidAppear:(BOOL)animated;

- (void)viewWillAppear:(BOOL)animated;

@property(nonatomic) BOOL hidesSourceListWhenPushed;

- (BOOL)isTransitory;

- (void)setTransitory:(BOOL)transitory;

- (void)viewControllersForNavigationDestination:(id)arg1 completion:(CDUnknownBlockType)arg2;

- (void)willEncodeNavigationDestination:(id)arg1;

- (id <UXNavigationDestination>)navigationDestination;

- (NSString *)navigationIdentifier;

@property (readonly, nonatomic) UXSourceController * _Nullable sourceController;

@end

NS_ASSUME_NONNULL_END

