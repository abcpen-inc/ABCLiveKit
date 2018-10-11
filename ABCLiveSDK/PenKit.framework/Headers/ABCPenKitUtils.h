//
//  ABCPenKitUtils.h
//  PenKit
//
//  Created by bing on 2017/5/17.
//  Copyright © 2017年 北京暄暄网络科技有限公司. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define N2_PEN_PAPER_WIDTH 81.0f
#define N2_PEN_PAPER_HEIGHT 111.0f

//#define UNIQUEID @"uniqueId"
#define N2_NODE_ID @"n2_node_id"
#define N2_SYNC_ONWER_ID @"n2_sync_onwer_id"
#define SYNCSTATE @"syncState"  //0未同步，1同步中 2已同步

typedef enum BlueType{
    BlueType_NotConnected = 100, //未连接
    BlueType_Connected,          //连接成功
    BlueType_DisConnected,       //断开连接
    BlueType_Connecting,       //搜索中连接中（N2）
    BlueType_ConnectFail,        //连接失败
    BlueType_N2UNREGISTERED      //N2未注册
}BlueType;

typedef enum ABCPenType{
    ABCPenType_Pen = 1, //笔声智能笔
    ABCPenType_Equil = 2, //Equil笔
    ABCPenType_Pen2 = 3, //笔声智能笔2代
    ABCPenType_N2 = 4, //NeoSmartpen//请使用 startConnectN2进行直连
    ABCPenType_AFPen = 5
}ABCPenType;

@protocol ABCPenKitUtilsDelegate <NSObject>

@optional
- (void)findDeviceObject:(NSArray *)arrSource;
- (void)connectStatusChange:(BlueType)blueType;
- (void)n2ConnectStatusChange:(BlueType)blueType;
- (void)activeN2NotePageNumForFirstStroke:(int) pageNum;
- (void)getBluePadPoint:(CGPoint)point position:(int)position pressure:(float)pressure; //韩国本
- (void)getBluePadPoint:(CGPoint)point canvasScale:(float)canvasScale touchState:(int)touchState pressure:(float)pressure;  //robot new
- (void)getBluePadPoint:(CGPoint)point touchState:(int)touchState pressure:(float)pressure;  //robot new

- (void)getBluePadOriginalPoint:(CGPoint)point touchState:(int)touchState pressure:(float)pressure;  //N2

- (void)paperSizeReady;
- (void)addSelectPaperView:(UIView *)selView;

//offline本子列表
- (void)showOfflineDataList:(NSArray *)array;
- (void)synchroFish:(NSInteger)nodeId arrStroke:(NSArray *)arrStroke;
- (void)synchroProcess:(float)process noteId:(NSInteger) nodeId;

@end

@interface ABCPenKitUtils : NSObject

@property (nonatomic, assign) ABCPenType penType;
@property (nonatomic, assign) BlueType connState;
@property (nonatomic, assign, getter=isConnected) BOOL isConnected;//兼容老版
@property (nonatomic, assign) CGSize size;
@property (nonatomic, weak) id<ABCPenKitUtilsDelegate> delegate;
@property (nonatomic, assign) int temperature;
@property (nonatomic, assign) int smFlag;
@property (nonatomic, assign) CGSize paperSize;

@property (nonatomic, assign, getter=connIndex) NSInteger connIndex;//非N2笔连接的笔

//N2 offline
@property (nonatomic, strong) NSMutableArray *menuList;

@property (nonatomic, strong) NSString *currectOnwerId;

@property (nonatomic, assign) NSInteger currectNodeId;

@property (nonatomic, assign) NSInteger currectPageId;


//创建实例
+ (ABCPenKitUtils *) shareInstance;
//连接选择的蓝牙设备
- (void)startConnectDevice:(NSInteger)index;
/**
 *  开蓝牙搜索设备
 */
- (void)searchDeviceByBlue:(BOOL)isAuto;

- (void)disconnectDevice;
/**
 *  断开蓝牙设备
 */
- (void)disconnectDeviceAndClear:(BOOL) clearDevice;
//断开equil设备
- (void)closeEquilPen;
//检查设备是否连接
- (void)checkDeviceIsConnect;

//设置起始点
- (void)setCalibration:(BOOL)isAuto;


#pragma mark - NeoSmartpen

-(void) autoConnectN2;

-(void) startConnectN2;

-(void) resetRegistrationN2;

-(BOOL) hasN2PenRegistered;

//清除robot设备,修改老师端后删除
- (void)removeAllDevice;

-(void) setN2OffLineDelegate:(BOOL)isClear; //isClear YES清空 NO设置

//nodeId
-(void) synchroOneBookById:(int)ownerId nodeId:(int) nodeId;

-(void) synchroAllBook;

-(NSString *) resetCurrectOwnerId;

@end
