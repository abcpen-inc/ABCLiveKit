//
//  ABCPenKitManager.h
//  PenKit
//
//  Created by Qoo on 2018/10/25.
//  Copyright © 2018年 北京暄暄网络科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

#define NOTIFI_AIPEN_STAUS                  @"NOTIFI_AIPEN_STATUS"
#define NOTIFI_AIPEN_POINT                  @"NOTIFI_AIPEN_POINT"
#define NOTIFI_PAPERSIZE_READY              @"NOTIFI_PAPERSIZE_READY"
#define NOTIFI_AIPEN_N2_ACTIVEPAGE          @"NOTIFI_AIPEN_N2_ACTIVEPAGE"
#define NOTIFI_MORGAN_ACTIVE_NEXTPAGE       @"NOTIFI_MORGAN_ACTIVE_NEXTPAGE"

#define ThePenManager [ABCPenKitManager shareInstance]

@protocol ABCPenKitManagerUIDelegate <NSObject>
- (void)showDeviceView;
- (void)setDeviceViewData:(NSArray *)array;
- (void)setDeviceViewConnIndex:(NSInteger)index;
- (void)setIsStudentUI:(BOOL)isStudent;

- (void)showAlertMsgByTitle:(NSString *)title strMsg:(NSString *)strMsg;
- (void)showToastMsg:(NSString *)msg;
@end

typedef enum BlueType{
    BlueType_NotConnected = 100, //未连接           N2 & Equil & Robot
    BlueType_Connected,          //连接成功         N2 & Equil & Robot
    BlueType_DisConnected,       //断开连接         N2 & Equil & Robot
    BlueType_Connecting,         //搜索中连接中      N2 & Robot
    BlueType_ConnectFail,        //连接失败         Robot
    BlueType_Unregistered        //未注册           N2
}BlueType;

typedef enum ABCPenType{
    ABCPenType_Pen = 1, //笔声智能笔
    ABCPenType_Equil = 2, //Equil笔
    ABCPenType_Pen2 = 3, //笔声智能笔2代
    ABCPenType_N2 = 4, //NeoSmartpen//请使用 startConnectN2进行直连
    ABCPenType_AFPen = 5,
    ABCPenType_Morgan = 6 //摩根
}ABCPenType;

@interface ABCPenKitManager : NSObject

@property (nonatomic, assign) BOOL isStudent;

@property (nonatomic, assign, getter=penType) ABCPenType penType;
@property (nonatomic, strong, getter=strPenName) NSString *strPenName;
@property (nonatomic, assign, getter=connStatus) BlueType connStatus;
@property (nonatomic, assign) BOOL isHint; //是否需要弹出提示
@property (nonatomic, assign) BOOL blueToothOpen;//蓝牙是否打开

@property (nonatomic, assign) CGSize canvasSize;
@property (nonatomic, assign) CGSize paperSize;

@property (nonatomic, weak) id <ABCPenKitManagerUIDelegate> uiDelegate;

#pragma mark - NeoSmartpen
@property (nonatomic, assign, getter=hasN2PenRegistered) BOOL hasN2PenRegistered;


//创建实例
+ (ABCPenKitManager *) shareInstance;
//必须先设置笔类型
- (void)setPenType:(ABCPenType)penType;

- (void)setWBSizeWithPaperW:(float)paperW
                     paperH:(float)paperH
                 isPortrait:(BOOL)isPortrait;

- (void)disconnectDeviceAndClear:(BOOL) clearDevice;
- (void)searchDeviceByBlue:(BOOL)isAuto;

- (void)showDeviceView;

- (void)selectBlueDev:(NSInteger)index;

- (void)closeEquilPen;

#pragma mark - NeoSmartpen
-(void) autoConnectN2;

-(void) startConnectN2;

-(void) resetRegistrationN2;

@end

