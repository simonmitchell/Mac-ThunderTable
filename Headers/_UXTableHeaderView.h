//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UXCollectionReusableView.h"

@class NSBox, UXLabel, UXView;

@interface _UXTableHeaderView : UXCollectionReusableView
{
    BOOL _floating;
    UXView *_contentView;
    UXLabel *_titleLabel;
    NSBox *_separator;
}

@property(readonly, nonatomic) NSBox *separator; // @synthesize separator=_separator;
@property(readonly, nonatomic) UXLabel *titleLabel; // @synthesize titleLabel=_titleLabel;
@property(readonly, nonatomic) UXView *contentView; // @synthesize contentView=_contentView;
@property(nonatomic, getter=isFloating) BOOL floating; // @synthesize floating=_floating;
- (void)cxx_destruct;
- (void)mouseDown:(id)arg1;
- (void)prepareForReuse;
- (id)initWithFrame:(CGRect)frame;

@end

