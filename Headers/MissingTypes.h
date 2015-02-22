//
//  MissingTypes.h
//  UXKitTest
//
//  Created by Michał Kałużny on 06.02.2015.
//  Copyright (c) 2015 justmaku. All rights reserved.
//

#ifndef UXKitTest_MissingTypes_h
#define UXKitTest_MissingTypes_h

#import "UXBarPositioningDelegate-Protocol.h"

@class UXTableView;
@class UXTableViewCell;

@protocol UXNavigationBarDelegate <UXBarPositioningDelegate>
@optional
-(BOOL)navigationBar:(id)arg1 shouldPushItem:(id)arg2;
-(void)navigationBar:(id)arg1 didPushItem:(id)arg2;
-(BOOL)navigationBar:(id)arg1 shouldPopItem:(id)arg2;
-(void)navigationBar:(id)arg1 didPopItem:(id)arg2;
@end

@protocol UXTableViewDataSource <NSObject>
@optional
-(long long)numberOfSectionsIntableView:(UXTableView *)tableView;
-(NSString *)tableView:(UXTableView *)tableView titleForHeaderInSection:(long long)section;
-(NSString *)tableView:(UXTableView *)tableView titleForFooterInSection:(long long)section;
-(BOOL)tableView:(UXTableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath;
-(BOOL)tableView:(UXTableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath;
-(id)sectionIndexTitlesFortableView:(UXTableView *)tableView;
-(long long)tableView:(UXTableView *)tableView sectionForSectionIndexTitle:(id)arg2 atIndex:(long long)arg3;
-(void)tableView:(UXTableView *)tableView commitEditingStyle:(long long)arg2 forRowAtIndexPath:(NSIndexPath *)indexPath;
-(void)tableView:(UXTableView *)tableView moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(id)toIndexPath;

@required
-(long long)tableView:(UXTableView *)tableView numberOfRowsInSection:(long long)section;
-(UXTableViewCell *)tableView:(UXTableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath;
@end

@protocol UXTableViewDelegate <NSObject>

@optional
-(void)tableView:(UXTableView *)tableView willDisplayCell:(UXTableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath;
-(void)tableView:(UXTableView *)tableView willDisplayHeaderView:(id)arg2 forSection:(long long)section;
-(void)tableView:(UXTableView *)tableView willDisplayFooterView:(id)arg2 forSection:(long long)section;
-(void)tableView:(UXTableView *)tableView didEndDisplayingCell:(id)arg2 forRowAtIndexPath:(NSIndexPath *)indexPath;
-(void)tableView:(UXTableView *)tableView didEndDisplayingHeaderView:(id)arg2 forSection:(long long)section;
-(void)tableView:(UXTableView *)tableView didEndDisplayingFooterView:(id)arg2 forSection:(long long)section;
-(double)tableView:(UXTableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath;
-(double)tableView:(UXTableView *)tableView heightForHeaderInSection:(long long)section;
-(double)tableView:(UXTableView *)tableView heightForFooterInSection:(long long)section;
-(double)tableView:(UXTableView *)tableView estimatedHeightForRowAtIndexPath:(NSIndexPath *)indexPath;
-(double)tableView:(UXTableView *)tableView estimatedHeightForHeaderInSection:(long long)section;
-(double)tableView:(UXTableView *)tableView estimatedHeightForFooterInSection:(long long)section;
-(id)tableView:(UXTableView *)tableView viewForHeaderInSection:(long long)section;
-(id)tableView:(UXTableView *)tableView viewForFooterInSection:(long long)section;
-(long long)tableView:(UXTableView *)tableView accessoryTypeForRowWithIndexPath:(NSIndexPath *)indexPath;
-(void)tableView:(UXTableView *)tableView accessoryButtonTappedForRowWithIndexPath:(NSIndexPath *)indexPath;
-(BOOL)tableView:(UXTableView *)tableView shouldHighlightRowAtIndexPath:(NSIndexPath *)indexPath;
-(void)tableView:(UXTableView *)tableView didHighlightRowAtIndexPath:(NSIndexPath *)indexPath;
-(void)tableView:(UXTableView *)tableView didUnhighlightRowAtIndexPath:(NSIndexPath *)indexPath;
-(id)tableView:(UXTableView *)tableView willSelectRowAtIndexPath:(NSIndexPath *)indexPath;
-(id)tableView:(UXTableView *)tableView willDeselectRowAtIndexPath:(NSIndexPath *)indexPath;
-(void)tableView:(UXTableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath;
-(void)tableView:(UXTableView *)tableView didDeselectRowAtIndexPath:(NSIndexPath *)indexPath;
-(long long)tableView:(UXTableView *)tableView editingStyleForRowAtIndexPath:(NSIndexPath *)indexPath;
-(id)tableView:(UXTableView *)tableView titleForDeleteConfirmationButtonForRowAtIndexPath:(NSIndexPath *)indexPath;
-(id)tableView:(UXTableView *)tableView editActionsForRowAtIndexPath:(NSIndexPath *)indexPath;
-(BOOL)tableView:(UXTableView *)tableView shouldIndentWhileEditingRowAtIndexPath:(NSIndexPath *)indexPath;
-(void)tableView:(UXTableView *)tableView willBeginEditingRowAtIndexPath:(NSIndexPath *)indexPath;
-(void)tableView:(UXTableView *)tableView didEndEditingRowAtIndexPath:(NSIndexPath *)indexPath;
-(id)tableView:(UXTableView *)tableView targetIndexPathForMoveFromRowAtIndexPath:(NSIndexPath *)fromIndexPath toProposedIndexPath:(NSIndexPath *)toIndexPath;
-(long long)tableView:(UXTableView *)tableView indentationLevelForRowAtIndexPath:(NSIndexPath *)indexPath;
-(BOOL)tableView:(UXTableView *)tableView shouldShowMenuForRowAtIndexPath:(NSIndexPath *)indexPath;
-(BOOL)tableView:(UXTableView *)tableView canPerformAction:(SEL)aSelector forRowAtIndexPath:(NSIndexPath *)indexPath withSender:(id)sender;
-(void)tableView:(UXTableView *)tableView performAction:(SEL)aSelector forRowAtIndexPath:(NSIndexPath *)indexPath withSender:(id)sender;

@end


#endif
