//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UXViewController.h"
//#import "UXPopoverControllerDelegate-Protocol.h"

@import  AppKit;

typedef NS_OPTIONS(NSUInteger, UIPopoverArrowDirection) {
    UIPopoverArrowDirectionUp = 1UL << 0,
    UIPopoverArrowDirectionDown = 1UL << 1,
    UIPopoverArrowDirectionLeft = 1UL << 2,
    UIPopoverArrowDirectionRight = 1UL << 3,
    UIPopoverArrowDirectionAny = UIPopoverArrowDirectionUp | UIPopoverArrowDirectionDown | UIPopoverArrowDirectionLeft | UIPopoverArrowDirectionRight,
    UIPopoverArrowDirectionUnknown = NSUIntegerMax
};

@class NSArray, NSString, UXPopover, UXBarButtonItem;

NS_ASSUME_NONNULL_BEGIN

@interface UXPopoverController : UXViewController <NSPopoverDelegate>

@property(copy, nonatomic) NSArray<__kindof NSView *> * _Nullable passthroughViews;
//@property(nonatomic) __weak id <UXPopoverControllerDelegate> delegate; // @synthesize delegate=_delegate;

- (void)dismissPopoverAnimated:(BOOL)animated;

- (void)dismissPopover;

- (void)presentPopoverFromBarButtonItem:(UXBarButtonItem *)barItem permittedArrowDirections:(UIPopoverArrowDirection)directions animated:(BOOL)animated;

- (void)presentPopoverFromRect:(CGRect)rect inView:(NSView *)view preferredEdge:(NSRectEdge)edge;

@property(retain, nonatomic) UXViewController *contentViewController;

@property(nonatomic) CGSize popoverContentSize;

- (void)setPopoverContentSize:(CGSize)size animated:(BOOL)animated;

@property(readonly, nonatomic, getter=isPopoverVisible) BOOL popoverVisible;

@property(nonatomic) NSInteger popoverBehavior;

- (UXPopover *)popover;

- (instancetype)initWithContentViewController:(UXViewController *)contentViewController;

@end

NS_ASSUME_NONNULL_END

