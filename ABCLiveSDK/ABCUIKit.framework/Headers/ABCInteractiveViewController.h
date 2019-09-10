//
//  ABCInteractiveViewController.h
//  ABCLiveKit
//
//  Created by bing on 2017/6/14.
//  Copyright © 2017年 北京暄暄科技有限公司. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ABCViewCrtlDelegate.h"

@interface ABCInteractiveViewController : UIViewController

@property(nonatomic, weak) id<ABCViewCrtlDelegate> delegate;

@property(nonatomic, strong) ABCRoomMo *roomMo;

-(instancetype) initABCInteractiveViewCtrlWithRoomMo:(ABCRoomMo *) roomMo;

- (void)closeRoom:(BOOL) isNeedSend needDismiss:(BOOL)needDismiss;

-(void) refreshToken:(void (^)(NSString *token)) tokenBlock;

-(void) sendLocalMessage:(NSString *) content;

-(void) onMessageRecive:(NSArray *) messages;

-(void) sendMessage:(NSString *) msg;


@end
