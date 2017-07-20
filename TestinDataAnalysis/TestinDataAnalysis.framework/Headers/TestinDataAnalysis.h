//
//  TestinDataAnalysis.h
//  TestinDataAnalysis SDK version 4.1.4
//
//  Created by Testin on 16/7/29.
//  Copyright © 2016年 testin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface TestinDataAnalysis : NSObject

/**
 *  初始化TestinDataAnalysis SDK
 *
 *  @param appkey  平台申请的appkey
 *  @param launchOptions  your application delegate's launchOptions
 */
+ (void)initWithAppkey:(NSString *)appkey launchOptions:(NSDictionary *)launchOptions;

/**
 *  初始化TestinDataAnalysis SDK 携带url
 *
 *  @param appkey  平台申请的appkey
 *  @param launchOptions  optional app delegate launchOptions
 *  @param withBaseServerURL  动态serverurl 适用于第三方部署 hostname
 *  @param withWebSocketURL  动态websocketurl 适用于第三方可视化部署 hostname
 */

+ (void)initWithAppkey:(NSString *)appkey launchOptions:(NSDictionary *)launchOptions withBaseServerURL:(NSString *)serverURL withWebSocketURL:(NSString *)websocketURL;

/**
 *  提交指标数据
 *  这里的指标名称必须和后台创建的指标名称相对应,对于后台没创建的指标,我们将不做统计处理
 *  默认对指标的统计以数值累加,default为1
 *
 *  @param eventName  指标名称
 */
+ (void)tracker:(NSString *)eventName;

/**
 *  自定义指标数值
 *
 *  @param eventName    指标名称
 *  @param value        指标值
 */
+ (void)tracker:(NSString *)eventName withValue:(NSNumber *)value;

/**
 *  根据变量名获取变量值
 *
 *  @param variableName  变量名
 *  @param defaultvalue  默认变量值
 *
 *  @return 变量值
 */
+ (id)getExperimentVariable:(NSString *)variableName defaultValue:(id)defaultvalue;

/**
 *  设置是否显示调试悬浮按钮 SDK 4.1.2 集成了可视化和集成调试入口
 *
 *  @param isTouchAssist  显示(YES) 不显示(NO)
 */
+ (void)setDebugTouchAssist:(BOOL)isTouchAssist;

/**
 *  设置精细化分流属性
 *
 *  @param customProperties  自定义属性
 */
+ (void)setCustomTrackerProperties:(NSMutableDictionary *)customProperties;

/**
 *  设置自定义标识符
 *
 *  @param clientId  设置自定义唯一标识符(需要在initWithAppkey 之前调用，不设置将由SDK自动生成)
 */
+ (void)setClientId:(NSString *)clientId;

/**
 *  设置是否只是wifi环境上报数据
 *
 *  @param onlyWifiEnvironmentUpload
 */
+ (void)setOnlyWifi:(BOOL)onlyWifiEnvironmentUpload;

/**
 *  开启可视化编辑模式  此方法被废弃 开启可视化请 使用 + (void)setDebugTouchAssist:(BOOL)isTouchAssist 替代
 */
+ (void)enableEditor __unavailable;

/**
 *  获取当前运行的实验信息
 *
 *  @return 返回的NSArray
 *  若处于轮空状态时,@"expName" @"expId" @"expVersionId" @"expVersionName" 的值为 CONTROL
 */
+ (NSArray *)getAllCurrentExperiments;

/**
 *  获取SDK版本号 SDK 4.0.5 以后提供
 */
+ (NSString *)libVersion;

/**
 *  根据变量名获取变量值 优先从缓存读取 缓存不存在 请求server实时获取
 *
 *  @param variableName       变量名
 *  @param defaultvalue       默认变量值
 *  @param timeout            网络访问超时时间 如果设置为0,则为默认时间
 *  @param completionHandler  回调处理器 请求server 回调处理
 */

+ (void)asynchronousGetExperimentVariable:(NSString *)variableName
                             defaultValue:(id)defaultvalue
                          timeoutInterval:(NSTimeInterval)timeout
                        completionHandler:(void (^)(id variableValue, NSError *error))completionHandler;

/**
 *  实时拉取配置
 *
 *  @param timeout            网络访问超时时间 如果设置为0,则为默认时间
 *  @param completionHandler  回调处理器 请求server 回调处理
 */
+ (void)asynchronousLoadExperimentConfigWithTimeInterval:(NSTimeInterval)timeout
                                       completionHandler:(void (^)(BOOL success, NSError *error))completionHandler;

@end
