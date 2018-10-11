//
//  ABCPenPoint.h
//  ABCPenKit
//
//  Created by bing on 2017/10/20.
//  Copyright © 2017年 北京暄暄科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    ABCPenPoint_Hang = 0,
    ABCPenPoint_Begin,
    ABCPenPoint_Move,
    ABCPenPoint_End,
} ABCPenPoint_State;

@interface ABCPenPoint : NSObject

@property(readwrite,nonatomic,assign) float x;
@property(readwrite,nonatomic,assign) float y;
@property(readwrite,nonatomic,assign) float width;
@property(readwrite,nonatomic,assign) float height;
@property(readwrite,nonatomic,assign) float scale;
@property(readwrite,nonatomic,assign) float pressure;//max value 8191
@property(readwrite,nonatomic,assign) ABCPenPoint_State touchState;

@end
