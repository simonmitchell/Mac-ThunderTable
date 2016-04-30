//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@import AppKit;

@class NSString, NSTitlebarAccessoryViewController, NSToolbarItem, UXToolbar, UXViewController, _UXWindow, UXNavigationController;

@interface UXWindowController : NSWindowController <NSToolbarDelegate, NSWindowDelegate>
{
    NSTitlebarAccessoryViewController *_titlebarAccessoryViewController;
    UXToolbar *_currentAccessoryToolbar;
    NSToolbarItem *_navigationBarToolbarItem;
}

+ (id)defaultWindow;
@property __weak NSToolbarItem *navigationBarToolbarItem; // @synthesize navigationBarToolbarItem=_navigationBarToolbarItem;

- (void)cxx_destruct;
- (void)windowDidBecomeFirstResponder:(id)arg1;

- (void)windowDidRecalculateKeyViewLoop:(id)arg1;
- (void)windowWillRecalculateKeyViewLoop:(id)arg1;

- (void)windowWillExitFullScreen:(id)arg1;
- (void)windowWillEnterFullScreen:(id)arg1;

- (CGRect)window:(_UXWindow *)arg1 willPositionSheet:(id)arg2 usingRect:(CGRect)arg3;
- (void)_updateAccessoryBar;
- (void)_updateToolbarItem;
- (void)_popoverWillShow:(id)arg1;
- (void)_setupAccessoryBar;
- (void)_setupNavigationBarToolbarItem;
- (void)_setAccessoryBarHidden:(BOOL)hidden;

@property(readonly, nonatomic) double _accessoryBarHeight;

- (id)toolbar:(id)arg1 itemForItemIdentifier:(id)arg2 willBeInsertedIntoToolbar:(BOOL)arg3;
- (id)toolbarDefaultItemIdentifiers:(id)identifiers;
- (id)toolbarAllowedItemIdentifiers:(id)identifiers;
- (void)setWindow:(_UXWindow *)window;
- (UXNavigationController *)rootNavigationController;
@property(retain, nonatomic) UXViewController *rootViewController;
@property(readonly, nonatomic) NSTitlebarAccessoryViewController *titlebarAccessoryViewController;
- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context;
- (void)_tearDownViewControllerHierarchyForViewController:(UXViewController *)arg1;
- (void)teardownViewControllerHierarchy;
- (void)dealloc;
- (id)initWithWindow:(_UXWindow *)window;
- (id)initWithRootViewController:(UXViewController *)vc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) NSUInteger hash;
@property(readonly) Class superclass;

@end

