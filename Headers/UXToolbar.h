//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UXBar.h"

NS_ASSUME_NONNULL_BEGIN

@class UXBarButtonItem;

@interface UXToolbar : UXBar
{
    id <UXToolbarDelegate> _delegate;
}

@property(nonatomic, weak) id <UXToolbarDelegate> _Nullable delegate;

- (void)setItems:(nullable NSArray<UXBarButtonItem *> *)items animated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
