//
//  ABCStroke.h
//  n2sample
//
//  Copyright (c) 2017 Neolab. All rights reserved.
//

#import <Foundation/Foundation.h>

#define MAX_NODE_NUMBER 1024

@class NJNode;
@interface ABCStroke : NSObject {
    @public
    float *point_x, *point_y, *point_p;
    UInt64 *time_stamp;
    UInt64 start_time;
}

@property (strong, nonatomic) NSArray *nodes;
@property (nonatomic) int dataCount;
@property (nonatomic) float inputScale;
@property (nonatomic) float targetScale;
@property (nonatomic) UInt32 penColor;
@property (nonatomic) NSUInteger penThickness;

- (instancetype) initWithRawDataX:(float *)point_x Y:(float*)point_y pressure:(float *)point_p
                        time_diff:(int *)time penColor:(UInt32)penColor penThickness:(NSUInteger)thickness startTime:(UInt64)start_at size:(int)size;
- (instancetype) initWithRawDataX:(float *)x Y:(float*)y pressure:(float *)p time_diff:(int *)time
                         penColor:(UInt32)penColor penThickness:(NSUInteger)thickness startTime:(UInt64)start_at size:(int)size normalizer:(float)inputScale;
- (void)renderWithScale:(CGFloat)scale;

- (NSMutableArray *)getArrPoint;

@end
