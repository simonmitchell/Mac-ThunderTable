//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UXCollectionViewController.h"

@class UXTableView;

@interface UXTableViewController : UXCollectionViewController
{
    id <UXTableViewDelegate> _tableViewDelegate;
}

typedef NS_ENUM(NSUInteger, UXTableViewStyle) {
    UXTableViewStylePlain = 0,
    UXTableViewStyleGrouped = 1
};

+ (Class)collectionViewClass;
- (void)cxx_destruct;
- (void)_updateContentInsetFromLayoutGuides;
- (id)preferredFirstResponder;
- (void)viewDidAppear;
- (void)viewWillAppear;
- (void)viewDidLoad;
- (void)didUpdateLayoutGuides;
- (void)viewDidLayoutSubviews;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;
- (id)init;
- (id)initWithStyle:(UXTableViewStyle)style;

@property(readonly, nonatomic) id <UXTableViewDelegate> tableViewDelegate; // @synthesize tableViewDelegate=_tableViewDelegate;
@property(readonly, nonatomic) UXTableView *tableView;

@end

