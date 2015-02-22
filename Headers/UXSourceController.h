//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UXViewController.h"

#import "UXNavigationControllerDelegate-Protocol.h"
#import "_UXSourceSplitViewDelegate-Protocol.h"

@class NSArray, NSMapTable, NSOperationQueue, NSSegmentedControl, NSString, NSView, UXTransitionController, _UXSourceSplitView, _UXViewControllerOneToOneTransitionContext;

@interface UXSourceController : UXViewController <UXNavigationControllerDelegate, _UXSourceSplitViewDelegate>
{
    NSView *_tabBarView;
    BOOL _isTransitioning;
    _UXViewControllerOneToOneTransitionContext *_transitionCtx;
    UXTransitionController *_transitionController;
    id <UXNavigationControllerDelegate> _currentNavigationDelegate;
    long long _preferredStyle;
    long long _style;
    NSArray *_rootViewControllers;
    UXViewController *_selectedViewController;
    UXViewController<UXSourceList> *_sourceListViewController;
    NSString *_sourceListAutosaveName;
    NSSegmentedControl *_segmentedControl;
    _UXSourceSplitView *_splitView;
    NSMapTable *_navigationControllerByRootViewController;
    NSMapTable *_transitionControllerClassByToViewControllerClass;
    NSOperationQueue *_viewControllerOperations;
}

+ (Class)_defaultTransitionControllerClass;
+ (id)_autosaveDefaultsKeyForName:(id)arg1;
@property(readonly) NSOperationQueue *viewControllerOperations; // @synthesize viewControllerOperations=_viewControllerOperations;
@property(readonly, nonatomic) NSMapTable *transitionControllerClassByToViewControllerClass; // @synthesize transitionControllerClassByToViewControllerClass=_transitionControllerClassByToViewControllerClass;
@property(readonly, nonatomic) NSMapTable *navigationControllerByRootViewController; // @synthesize navigationControllerByRootViewController=_navigationControllerByRootViewController;
@property(readonly, nonatomic) _UXSourceSplitView *splitView; // @synthesize splitView=_splitView;
@property(readonly, nonatomic) NSSegmentedControl *segmentedControl; // @synthesize segmentedControl=_segmentedControl;
@property(copy, nonatomic) NSString *sourceListAutosaveName; // @synthesize sourceListAutosaveName=_sourceListAutosaveName;
@property(retain, nonatomic) UXViewController<UXSourceList> *sourceListViewController; // @synthesize sourceListViewController=_sourceListViewController;
@property(retain, nonatomic) UXViewController *selectedViewController; // @synthesize selectedViewController=_selectedViewController;
@property(copy, nonatomic) NSArray *rootViewControllers; // @synthesize rootViewControllers=_rootViewControllers;
@property(nonatomic) long long style; // @synthesize style=_style;
@property(nonatomic) long long preferredStyle; // @synthesize preferredStyle=_preferredStyle;
- (void)cxx_destruct;
- (void)_setupDelegateForNavigationController:(id)arg1 operation:(long long)arg2 fromViewController:(id)arg3 toViewController:(id)arg4;
- (BOOL)navigationController:(id)arg1 shouldBeginInteractivePopFromViewController:(id)arg2 toViewController:(id)arg3;
- (id)navigationController:(id)arg1 animationControllerForOperation:(long long)arg2 fromViewController:(id)arg3 toViewController:(id)arg4;
- (id)navigationController:(id)arg1 interactionControllerForAnimationController:(id)arg2;
- (void)navigationController:(id)arg1 didShowViewController:(id)arg2;
- (void)navigationController:(id)arg1 willShowViewController:(id)arg2;
- (void)sourceSplitView:(id)arg1 didResizeMasterWidth:(double)arg2;
- (id)_contextForTransitionOperation:(long long)arg1 fromViewController:(id)arg2 toViewController:(id)arg3 transition:(unsigned long long)arg4;
- (void)_beginTransitionWithContext:(id)arg1 operation:(long long)arg2;
- (void)_prepareViewController:(id)arg1 forAnimationInContext:(id)arg2 completion:(CDUnknownBlockType)arg3;
- (id)transitionCoordinator;
- (void)dismissViewControllerAnimated:(BOOL)arg1 completion:(CDUnknownBlockType)arg2;
- (void)presentViewController:(id)arg1 animated:(BOOL)arg2 completion:(CDUnknownBlockType)arg3;
- (void)removeDestination:(id)arg1 animated:(BOOL)arg2 completion:(CDUnknownBlockType)arg3;
- (void)_removeDestination:(id)arg1 animated:(BOOL)arg2 completion:(CDUnknownBlockType)arg3;
- (void)_navigateToDestination:(id)arg1 animated:(BOOL)arg2 completion:(CDUnknownBlockType)arg3;
- (void)navigateToDestination:(id)arg1 animated:(BOOL)arg2 completion:(CDUnknownBlockType)arg3;
- (id)preferredFirstResponder;
- (void)viewWillAppear;
- (void)viewDidLoad;
- (void)keyDown:(id)arg1;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)didChangeSelectedViewController;
- (void)willAddNavigationController:(id)arg1;
- (void)segmentChanged:(id)arg1;
@property(nonatomic) unsigned long long selectedIndex;
- (void)setSelectedIndex:(unsigned long long)arg1 animated:(BOOL)arg2;
- (void)setSelectedViewController:(id)arg1 animated:(BOOL)arg2;
- (void)setRootViewControllers:(id)arg1 destination:(id)arg2 completion:(CDUnknownBlockType)arg3;
- (void)_setPreferredStyle:(long long)arg1 animated:(BOOL)arg2;
- (void)_setStyle:(long long)arg1 animated:(BOOL)arg2 completion:(CDUnknownBlockType)arg3;
- (void)_updateStyleForViewController:(id)arg1 transitionContext:(id)arg2 completion:(CDUnknownBlockType)arg3;
@property(readonly, nonatomic) BOOL alternateTitleEnabled;
- (id)tabBarView;
- (long long)_effectiveStyleForViewController:(id)arg1;
- (void)_setSelectedIndex:(unsigned long long)arg1 animated:(BOOL)arg2 sender:(id)arg3;
- (void)_setSelectedViewController:(id)arg1 animated:(BOOL)arg2 sender:(id)arg3;
- (void)_didChangeSelectedViewControllerFromSender:(id)arg1;
- (id)_popTransitoryViewControllersInNavigationController:(id)arg1 animated:(BOOL)arg2;
- (void)_setLeftContentInset:(double)arg1;
- (double)_savedSourceListWidth;
- (void)_saveSourceListWidth:(double)arg1;
- (id)_accessoryViewController;
- (void)_updateSegmentedControl;
- (void)_configureManagedNavigationController:(id)arg1;
- (void)unregisterTransitionControllerForTransitionToViewControllerClass:(Class)arg1;
- (void)registerTranistionControllerClass:(Class)arg1 forViewControllerClass:(Class)arg2;
- (void)registerTransitionControllerClass:(Class)arg1 forViewControllerClass:(Class)arg2;
- (id)destinationForNavigationIdentifier:(id)arg1 title:(id)arg2;
- (id)destinationForViewController:(id)arg1;
- (void)unregisterTransitoryViewController:(id)arg1;
- (void)registerTransitoryViewController:(id)arg1;
@property(readonly, nonatomic) id <UXNavigationDestination> currentNavigationDestination;
- (void)removeRootViewControllerAtIndex:(long long)arg1;
- (void)insertRootViewController:(id)arg1 atIndex:(long long)arg2;
- (void)addRootViewController:(id)arg1;
- (void)dealloc;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) NSUInteger hash;
@property(readonly) Class superclass;

@end

