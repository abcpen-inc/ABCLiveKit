//
//  ABCLiveFloatingBoard.h
//  ABCLiveUIKit
//
//  Created by bingo on 2018/8/7.
//  Copyright © 2018年 杭州喧喧科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ABCCoreKit/ABCBaseManager.h>

@class ABCLiveFloatingWindow;


@interface ABCLiveFloatingBoard : NSObject

/*!
 悬浮窗的Window
 */
@property(nonatomic, strong) ABCLiveFloatingWindow *window;

@property(nonatomic, strong) ABCBaseManager *manager;
@property(nonatomic, strong) ABCRoomMo *roomMo;

+ (void)startLiveFloatingBoard:(ABCBaseManager *)manager
                        roomMo:(ABCRoomMo *) roomMo
              withTouchedBlock:(void (^)(ABCBaseManager *manager,ABCRoomMo *roomMo))touchedBlock;

- (void)touchedBoard:(id)sender;

@end




@interface ABCLiveFloatingWindow : UIWindow

@property (nonatomic, weak) ABCLiveFloatingBoard *floatBoard;

- (void)touchedBoard;

@end
