//
//  AiPenUtils.h
//  AbcPen-ipad
//
//  Created by dev001 on 2018/6/29.
//  Copyright © 2018年 北京暄暄科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PenKit/PenKit.h>

#define NOTIFI_AIPEN_STAUS                  @"NOTIFI_AIPEN_STATUS"
#define NOTIFI_AIPEN_POINT                  @"NOTIFI_AIPEN_POINT"
#define NOTIFI_PAPERSIZE_READY              @"NOTIFI_PAPERSIZE_READY"
#define NOTIFI_AIPEN_N2_ACTIVEPAGE          @"NOTIFI_AIPEN_N2_ACTIVEPAGE"

#define TheAiPen [AiPenUtils shareInstance]

@interface AiPenUtils : NSObject

@property (nonatomic, assign) BOOL isStudent;

@property (nonatomic, assign, getter=penType) ABCPenType penType;
@property (nonatomic, strong, getter=strPenName) NSString *strPenName;
@property (nonatomic, assign, getter=connStatus) BlueType connStatus;
@property (nonatomic, assign) BOOL isHint; //是否需要弹出提示
@property (nonatomic, assign) BOOL blueToothOpen;//蓝牙是否打开

@property (nonatomic, assign) CGSize canvasSize;
@property (nonatomic, assign) CGSize paperSize;

#pragma mark - NeoSmartpen
@property (nonatomic, assign, getter=hasN2PenRegistered) BOOL hasN2PenRegistered;


//创建实例
+ (AiPenUtils *) shareInstance;
//必须先设置笔类型
- (void)setPenType:(ABCPenType)penType;

- (void)setWBSizeWithPaperW:(float)paperW
                     paperH:(float)paperH
                 isPortrait:(BOOL)isPortrait;

- (void)disconnectDeviceAndClear:(BOOL) clearDevice;
- (void)searchDeviceByBlue:(BOOL)isAuto;

- (void)showDeviceView;

#pragma mark - NeoSmartpen

-(void) autoConnectN2;

-(void) startConnectN2;

-(void) resetRegistrationN2;

@end
