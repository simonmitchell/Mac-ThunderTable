//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSPanGestureRecognizer.h"

@class NSEvent;

@interface UXCollectionViewPanGestureRecognizer : NSPanGestureRecognizer
{
    NSEvent *_mouseDownEvent;
}

@property(retain, nonatomic) NSEvent *mouseDownEvent; // @synthesize mouseDownEvent=_mouseDownEvent;
- (void)uxCancel;
- (void)mouseDown:(id)arg1;

@end

