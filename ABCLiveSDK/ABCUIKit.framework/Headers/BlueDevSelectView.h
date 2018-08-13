//
//  BlueDevSelectView.h
//  AlphaGo
//
//  Created by wangchun on 2016/10/24.
//  Copyright © 2016年 北京暄暄网络技术有限公司. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BlueDevCell:UITableViewCell

@property (nonatomic, strong) void (^btnConnectClick)(void);

@end


@protocol BlueDevSelectViewDelegate <NSObject>

@optional
- (void)selectBlueDev:(NSInteger)index;
- (void)reSearchDevice;

@end

@interface BlueDevSelectView : UIView

@property (nonatomic, assign) NSString *emptyStr;
@property (nonatomic, assign) NSInteger connIndex;
@property (nonatomic, strong) NSArray *arrSource;
@property (nonatomic, weak) id<BlueDevSelectViewDelegate> blueDevSelectViewDelegate;

@end
