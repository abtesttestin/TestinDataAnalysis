//
//  TestinAdNative.h
//  TestinDataAnalysis
//
//  Created by wubo on 2018/12/18.
//  Copyright © 2018年 testin. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 本地广告处理类
 */
@interface TestinAdNative : NSObject

/**
 拉取广告位素材

 @param adSeatId
 @param successhander
 @param failhander
 @return 返回 TestinAdNative 实例
 */
+(instancetype)loadAdDataByAdSeatId:(NSString*)adSeatId onReceverSuccess:(void(^)(id resultData)) successhander onReceverFail:(void(^)(id resultData)) failhander;

/**
 广告位曝光
 */
-(void)onAdExpoSure;

/**
 广告位点击
 */
-(void)onAdTrack;

@end

NS_ASSUME_NONNULL_END
