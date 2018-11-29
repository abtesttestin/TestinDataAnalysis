//
//  TestinDataBugoutDelegate.h
//  
//
//  Copyright (c) 2018年 wubo. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 bugout代理
 */
@protocol TestinDataBugoutDelegate <NSObject>

@optional

/**
 崩溃信息回调

 @param stackTrace 崩溃的堆栈信息
 */
- (void)receivedCrashNotification:(NSString*)stackTrace;

/**
 触发摇一摇回调
 */
- (void)receivedShakeFeedbackNotification;

/**
 摇一摇模块初始化完成回调
 */
- (void)receivedShakeFeedbackInitCompletedNotification;
@end
