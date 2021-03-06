//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UXCollectionViewCell.h"

@class NSColor, NSLayoutConstraint, NSMutableArray, UXLabel, UXView, _UXButton;

typedef NS_ENUM(NSInteger, UITableViewCellSeparatorStyle) {
    UITableViewCellSeparatorStyleNone,
    UITableViewCellSeparatorStyleSingleLine,
    UITableViewCellSeparatorStyleSingleLineEtched   // This separator style is only supported for grouped style table views currently
};

typedef NS_ENUM(NSUInteger, UITableViewCellStyle) {
    UITableViewCellStyleDefault = 0,
    UITableViewCellStyleSubtitle = 1,
    UITableViewCellStyleValue1 = 2
};

typedef NS_ENUM(NSInteger, UITableViewCellSelectionStyle) {
    UITableViewCellSelectionStyleNone,
    UITableViewCellSelectionStyleBlue,
    UITableViewCellSelectionStyleGray,
    UITableViewCellSelectionStyleDefault
};

typedef NS_ENUM(NSInteger, UITableViewCellAccessoryType) {
    UITableViewCellAccessoryNone,                                                      // don't show any accessory view
    UITableViewCellAccessoryDisclosureIndicator,                                       // regular chevron. doesn't track
    UITableViewCellAccessoryDetailDisclosureButton,                 // info button w/ chevron. tracks
    UITableViewCellAccessoryCheckmark,                                                 // checkmark. doesn't track
    UITableViewCellAccessoryDetailButton // info button. tracks
};

NS_ASSUME_NONNULL_BEGIN

@interface UXTableViewCell : UXCollectionViewCell

@property(readonly, nonatomic) UXView *internalHighlightedBackgroundView;

@property(retain, nonatomic, setter=_setSeparatorColor:) NSColor * _Nullable _separatorColor;

@property(nonatomic, setter=_setSeparatorHeight:) CGFloat _separatorHeight;

@property(nonatomic, setter=_setSeparatorStyle:) UITableViewCellSeparatorStyle _separatorStyle;

@property(nonatomic) NSEdgeInsets separatorInset;

@property(nonatomic) CGFloat indentationWidth;

@property(nonatomic) NSInteger indentationLevel;

@property(nonatomic) UITableViewCellSelectionStyle selectionStyle;

@property(nonatomic, getter=isHighlighted) BOOL highlighted;

@property(retain, nonatomic) NSColor * _Nullable highlightColor;

@property(retain, nonatomic) UXView * _Nullable accessoryView;

@property (nonatomic) UITableViewCellAccessoryType accessoryType;              // default is UITableViewCellAccessoryNone. use to set standard type

@property(retain, nonatomic) UXLabel * _Nullable detailTextLabel;

@property(retain, nonatomic) UXLabel * _Nullable textLabel;

@property(retain, nonatomic) UXView * _Nullable selectedBackgroundView;

@property(retain, nonatomic) UXView * _Nullable backgroundView;

@property(nonatomic) UITableViewCellStyle style;

@property(readonly, nonatomic) UXView *lowerSpace;

@property(readonly, nonatomic) UXView *upperSpace;

@property(readonly, nonatomic) UXView *defaultSelectedBackgroundView;

@property(readonly, nonatomic) _UXButton *internalAccessoryView;

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier;

@end

NS_ASSUME_NONNULL_END

