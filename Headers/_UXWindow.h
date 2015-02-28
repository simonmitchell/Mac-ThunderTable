//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@import AppKit;

@protocol _UXWindowDelegate;

@interface _UXWindow : NSWindow
{
}

- (BOOL)makeFirstResponder:(id)arg1;
- (void)recalculateKeyViewLoop;
- (void)tintColorDidChange;
- (void)beginCriticalSheet:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (void)beginSheet:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (void)dealloc;
- (id)initWithContentRect:(CGRect)rect;

// Remaining properties
@property id <_UXWindowDelegate> delegate; // @dynamic delegate;

@end

