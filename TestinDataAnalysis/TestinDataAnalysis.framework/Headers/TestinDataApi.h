//
//  TestinDataApi.h
//  TestinDataAnalysis
//
//  Created by Testin on 2017/8/22.
//  Copyright © 2017年 Testin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface TestinDataApi : NSObject

/**
 初始化方法

 @param appkey AB测试的appkey
 @param pid 项目id
 @param launchOptions
 */
+ (void)initWithAppkey:(NSString * _Nullable)appkey projectId:(NSString * _Nullable)pid launchOptions:(NSDictionary * _Nonnull)launchOptions;

/**
 初始化方法 （主要适用于私有云）

 @param appkey AB测试的appkey
 @param pid 项目id
 @param launchOptions launchOptions
 @param serverURL AB测试url
 @param testinDataServerURL 数据分析url
 @param configURL 配置信息url
 @param websocketURL 可视化的url
 @param testinDataSocketURL 运营分析可视化url
 */
+ (void)initWithAppkey:(NSString * _Nullable)appkey
             projectId:(NSString * _Nullable)pid
         launchOptions:(NSDictionary * _Nonnull)launchOptions
     withBaseServerURL:(NSString * _Nullable)serverURL
withTestinDataBaseServerURL:(NSString * _Nullable)testinDataServerURL
   withConfigServerURL:(NSString * _Nullable)configURL
      withWebSocketURL:(NSString * _Nullable)websocketURL
withTestinDataWebSocketURL:(NSString * _Nullable)testinDataSocketURL;

/**
 初始化方法

 @param pid 项目id
 @param launchOptions
 */
+ (void)initWithProjectId:(NSString * _Nullable)pid launchOptions:(NSDictionary * _Nonnull)launchOptions;

/**
 初始化(主要适用于私有云)

 @param pid 项目id
 @param launchOptions
 @param testinDataServerURL 运营分析数据url
 @param configURL 配置信息url
 @param websocketURL 可视化url
 */
+ (void)initWithProjectId:(NSString * _Nullable)pid
            launchOptions:(NSDictionary * _Nonnull)launchOptions
withTestinDataBaseServerURL:(NSString * _Nullable)testinDataServerURL
      withConfigServerURL:(NSString * _Nullable)configURL
         withWebSocketURL:(NSString * _Nullable)websocketURL;

/**
 埋点方法

 @param event 事件名称
 */
+ (void)tracker:(NSString * _Nonnull)event;

/**
 埋点方法 带属性值

 @param event 事件名称
 @param attributes 事件属性
 */
+ (void)tracker:(NSString * _Nonnull)event attributes:(NSDictionary * _Nullable)attributes;

//+(void)trackViewPage:(NSString *)viewPageIdtifier attributes:(NSDictionary *)attributes;

/**
 设置调试小助手是否显示

 @param isTouchAssist YES 为显示 NO 为隐藏 默认隐藏
 */
+ (void)setDebugTouchAssist:(BOOL)isTouchAssist;

/**
 设置可视化编辑的UIWindow 默认值取application 索引为0的窗口编辑

 @param visualWindow 可视化窗口（建议设置程序的主窗口）
 */
+ (void)setVisualWindow:(UIWindow * _Nonnull)visualWindow;

/**
 指定的UIViewController增加viewPage 事件

 @param viewController 指定的viewController
 @param attributes 自定义属性
 */
+ (void)trackViewPage:(UIViewController * _Nonnull)viewController attributes:(NSDictionary * _Nullable)attributes;

/**
 关联用户ID

 @param uid userID
 */
+ (void)bindTestinDataUID:(NSString * _Nonnull)uid;

/**
 关联用户ID 带用户属性

 @param uid
 @param profileDict 用户属性
 */
+ (void)bindTestinDataUID:(NSString * _Nonnull)uid attributes:(NSDictionary * _Nullable)profileDict;

/**
 指定埋点计时开始

 @param event 事件名称
 */
+ (void)beginTracker:(NSString * _Nonnull)event;

/**
 指定埋点计时结束

 @param event 事件名称
 */
+ (void)endTracker:(NSString * _Nullable)event;

/**
 指定埋点计时结束(携带属性)

 @param event 事件名称
 @param profileDict 属性
 */
+ (void)endTracker:(NSString * _Nullable)event attributes:(NSDictionary * _Nullable)profileDict;

/**
  清除事件计时器
 */
+ (void)clearTrackerTimer;

/**
 设置事件公共的属性

 @param profileDict 公共事件属性
 */
+ (void)setCommonProfile:(NSDictionary * _Nonnull)profileDict;

/**
 删除某一个公有事件属性

 @param profileName 事件属性名称
 */
+ (void)unsetCommonProfile:(NSString * _Nonnull)profileName;

/**
 清除所有公有事件属性
 */
+ (void)clearAllCommonProfile;

/**
 设置用户profile

 @param profileDict 用户属性
 */
+ (void)setProfile:(NSDictionary * _Nonnull)profileDict;

/**
 设置用户单个profile

 @param profileName 属性名称
 @param content 属性值
 */
+ (void)setProfileName:(NSString * _Nonnull)profileName content:(id _Nonnull)content;



/**
 清除用户属性

 @param profileName 属性名称
 */
+ (void)deleteProfile:(NSString * _Nonnull)profileName;



/**
 设置是否开始自动埋点viewClick事件

 @param isAuto isAuto
 */
+ (void)supportAutoViewClickTrack:(BOOL)isAuto;

/**
 设置是否开始自动埋点viewPage事件
 
 @param isAuto isAuto
 */
+ (void)supportAutoViewPageTrack:(BOOL)isAuto;

/**
 * 针对UIControl控件以及子类
 设置是否对已经可视化埋点的位置支持主动埋点 默认是不支持,限制的

 @param isSupport
 */
+ (void)supportUIControlAutoTrackForAlreadyVTrack:(BOOL)isSupport;
/**
 忽略的自动埋点的类型

 @param viewType
 */
+ (void)ignoreAutoTrackViewType:(Class _Nonnull)viewType;

/**
 忽略的自动埋点的Controller

 @param controllers 举例:NSArray * array =@[@"XxxxController",@"YyyyController"];
 */
+ (void)ignoreAutoTrackUIViewControllers:(NSArray * _Nonnull)controllers;

/**
  设置是否支持触摸开始时候track 此方法主要针对UIControl 实现了UITouchDown 事件的情况

 @param isSupport YES 是支持 默认是不支持
 */
+ (void)supportTouchBeginState:(BOOL)isSupport;

/**
 是否支持获取IDFA

 @param isIDFA 
 */
+ (void)enableIDFA:(BOOL)isIDFA;

/**
 *  设置是否只是wifi环境上报数据
 *
 *  @param onlyWifiEnvironmentUpload
 */
+ (void)setOnlyWifi:(BOOL)onlyWifiEnvironmentUpload;

/**
 *  获取SDK版本号
 */
+ (NSString * _Nonnull)libVersion;

@end
/**
 实现此协议的UIViewController,用户可以自定义属性和页面标识符会通过AutoTrack自动采集
 */
@protocol TestinDataAutoTrackerUtil

@required

/**
 设置的页面属性

 @return 自定义的页面属性
 */
- (NSDictionary * _Nullable)getTrackAttributes;
@required

/**
 设置页面标识符

 @return 自定义的页面标识符
 */
- (NSString * _Nullable) getViewPageIdentifier;
@end

@interface UIView (TestinDataView)
/**
  * track 是在hook的方法之前调用,还是之后调用 默认为hook方法之前
 */
@property (nonatomic, assign) BOOL testinDataAllowTrackBehindHookMethod;

/**
 是否禁止埋点
 */
@property (nonatomic, assign) BOOL testinDataForbidTrack;

/**
 view 的额外信息 类型为字典 利用分析
 */
@property (nonatomic, assign) NSDictionary * _Nullable testinDataViewExtInfo;


@end

