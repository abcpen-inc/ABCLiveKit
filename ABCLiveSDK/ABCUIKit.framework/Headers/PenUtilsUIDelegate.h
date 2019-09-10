//
//  PenUtilsUIDelegate.h
//  ABCUIKit
//
//  Created by Qoo on 2018/11/8.
//  Copyright © 2018年 北京暄暄科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

#define PenManagerDelegate [PenUtilsUIDelegate shareInstance]

@interface PenUtilsUIDelegate : NSObject

+ (PenUtilsUIDelegate *)shareInstance;

@end

