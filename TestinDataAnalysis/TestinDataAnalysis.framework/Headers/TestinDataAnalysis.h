//
//  TestinDataAnalysis.h
//  TestinDataAnalysis SDK version 5.0.0
//
//  Created by Testin on 16/7/29.
//  Copyright © 2016年 Testin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <TestinDataAnalysis/TestinDataApi.h>

FOUNDATION_EXPORT double TestinDataAnalysisVersionNumber;

FOUNDATION_EXPORT const unsigned char TestinDataAnalysisVersionString[];
@interface TestinDataAnalysis : NSObject

/**
 *  初始化TestinDataAnalysis SDK
 *
 *  @param appkey  平台申请的appkey
 *  @param launchOptions  your application delegate's launchOptions
 */
+ (void)initWithAppkey:(NSString * _Nonnull)appkey launchOptions:(NSDictionary * _Nullable)launchOptions;


/**
 *  初始化TestinDataAnalysis SDK 携带url
 *
 *  @param appkey  平台申请的appkey
 *  @param launchOptions  optional app delegate launchOptions
 *  @param withBaseServerURL  动态serverurl 适用于第三方部署 hostname
 *  @param withWebSocketURL  动态websocketurl 适用于第三方可视化部署 hostname
 */

+ (void)initWithAppkey:(NSString * _Nonnull)appkey launchOptions:(NSDictionary * _Nullable)launchOptions withBaseServerURL:(NSString * _Nullable)serverURL withWebSocketURL:(NSString * _Nullable)websocketURL;

/**
 *  提交指标数据
 *  这里的指标名称必须和后台创建的指标名称相对应,对于后台没创建的指标,我们将不做统计处理
 *  默认对指标的统计以数值累加,default为1
 *
 *  @param eventName  指标名称
 */
+ (void)tracker:(NSString * _Nonnull)eventName;

/**
 *  自定义指标数值
 *
 *  @param eventName    指标名称
 *  @param value        指标值
 */
+ (void)tracker:(NSString * _Nonnull)eventName withValue:(NSNumber * _Nonnull)value;

/**
 *  根据变量名获取变量值
 *
 *  @param variableName  变量名
 *  @param defaultvalue  默认变量值
 *
 *  @return 变量值
 */
+ (id _Nonnull)getExperimentVariable:(NSString * _Nonnull)variableName defaultValue:(id _Nonnull)defaultvalue;

/**
 *  设置是否显示调试悬浮按钮 SDK 4.1.2 集成了可视化和集成调试入口
 *
 *  @param isTouchAssist  显示(YES) 不显示(NO)
 */
+ (void)setDebugTouchAssist:(BOOL)isTouchAssist;
/**
 设置可视化编辑的UIWindow 默认值取application 索引为0的窗口编辑
 
 @param visualWindow 可视化窗口（建议设置程序的主窗口）
 */
+ (void)setVisualWindow:(UIWindow * _Nonnull)visualWindow;
/**
 *  设置精细化分流属性
 *
 *  @param customProperties  自定义属性
 */
+ (void)setCustomTrackerProperties:(NSMutableDictionary * _Nonnull)customProperties;

/**
 *  设置自定义标识符
 *
 *  @param clientId  设置自定义唯一标识符(需要在initWithAppkey 之前调用，不设置将由SDK自动生成)
 */
+ (void)setClientId:(NSString * _Nonnull)clientId;

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
 *  @return 返回的NSArray 包含--layerId(层id)、layerName(层名称)、expName(实验名称)、expId(实验Id)、expVersionId(版本Id)、expVersionName(版本名称)、running(是否触发实验).
 *  若处于轮空状态时,@"expName" @"expId" @"expVersionId" @"expVersionName" 的值为 CONTROL
 */
+ (NSArray * _Nonnull)getAllCurrentExperiments;

/**
 *  获取SDK版本号 SDK 4.0.5 以后提供
 */
+ (NSString * _Nonnull)libVersion;

/**
 *  根据变量名获取变量值 优先从缓存读取 缓存不存在 请求server实时获取
 *
 *  @param variableName       变量名
 *  @param defaultvalue       默认变量值
 *  @param timeout            网络访问超时时间 如果设置为0,则为默认时间
 *  @param completionHandler  回调处理器 请求server 回调处理
 */

+ (void)asynchronousGetExperimentVariable:(NSString * _Nonnull)variableName
                             defaultValue:(id _Nonnull)defaultvalue
                          timeoutInterval:(NSTimeInterval)timeout
                        completionHandler:(void (^_Nonnull)(id _Nullable variableValue, NSError * _Nullable error))completionHandler;

/**
 *  实时拉取配置
 *
 *  @param timeout            网络访问超时时间 如果设置为0,则为默认时间
 *  @param completionHandler  回调处理器 请求server 回调处理
 */
+ (void)asynchronousLoadExperimentConfigWithTimeInterval:(NSTimeInterval)timeout
                                       completionHandler:(void (^_Nonnull)(BOOL success, NSError * _Nullable error))completionHandler;

/**
 上传埋点数据
 */
+ (void)flush;

/**
 判断是否为新用户

 @return BOOL YES 为新用户 NO 非新用户
 */
+ (BOOL)isNewUser;

@end
