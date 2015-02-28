//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@import AppKit;

@class NSDraggingSession;

@protocol NSDraggingSource <NSObject>
- (unsigned long long)draggingSession:(NSDraggingSession *)arg1 sourceOperationMaskForDraggingContext:(long long)arg2;

@optional
- (BOOL)ignoreModifierKeysForDraggingSession:(NSDraggingSession *)arg1;
- (void)draggingSession:(NSDraggingSession *)arg1 endedAtPoint:(CGPoint)arg2 operation:(unsigned long long)arg3;
- (void)draggingSession:(NSDraggingSession *)arg1 movedToPoint:(CGPoint)arg2;
- (void)draggingSession:(NSDraggingSession *)arg1 willBeginAtPoint:(CGPoint)arg2;
@end

