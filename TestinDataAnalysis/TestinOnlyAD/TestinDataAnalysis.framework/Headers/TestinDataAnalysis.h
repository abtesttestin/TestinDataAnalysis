//
//  TestinDataAnalysis.h
//  TestinDataAnalysis SDK version 5.1.3
//  BugOut version 1.0.5
//  build:A
//  module:AD
//  Created by Testin on 16/7/29.
//  Copyright © 2016年 Testin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TestinDataConfig.h"
FOUNDATION_EXPORT double TestinDataAnalysisVersionNumber;

FOUNDATION_EXPORT const unsigned char TestinDataAnalysisVersionString[];

@interface TestinDataAnalysis : NSObject

/**
 初始化BugOut业务

 @param pid 对应bugout Appkey
 @param launchOptions  your application delegate's launchOptions
 */
+(void)initWithProjectId:(NSString * _Nullable)pid launchOptions:(NSDictionary * _Nonnull)launchOptions;

/**
 初始化BugOut业务 携带Congig信息

 @param pid 对应bugout Appkey
 @param config 可以设置用户自己的配置 不采用默认配置 传入此值
 @param launchOptions  your application delegate's launchOptions
 */
+ (void)initWithProjectId:(NSString * _Nullable)pid WithConfig:(TestinDataConfig*_Nullable)config launchOptions:(NSDictionary * _Nullable)launchOptions;

/**
 初始化AB业务
 
 @param appkey 必传  平台申请的appkey
 @param config 相关 配置信息
 @param launchOptions your application delegate's launchOptions
 */
+ (void)initWithAppkey:(NSString *_Nonnull)appkey WithConfig:(TestinDataConfig*_Nullable)config launchOptions:(NSDictionary *_Nullable)launchOptions;


/**
 初始化广告业务
 
 @param adAppKey 平台申请的媒体id
 @param config 相关配置信息
 @param launchOptions your application delegate's launchOptions
 */
+(void)initWithAdAppKey:(NSString* _Nullable)adAppKey WithConfig:(TestinDataConfig*_Nullable)config launchOptions:(NSDictionary * _Nullable)launchOptions;

//------------------**AD**---------------------



/**
 拉取广告素材数据

 @param adSeatId 广告位ID
 @param successhander 拉取成功回调
 @param failhander   拉取失败回调
 */
+(void)loadAdDataByAdSeatId:(NSString*)adSeatId onReceverSuccess:(void(^)(id resultData)) successhander onReceverFail:(void(^)(id resultData)) failhander;

/**
 主动曝光接口

 @param adSeatId 广告位ID
 @param adcontentid 广告内容ID
 @param reid 拉取素材数据返回的请求校验码
 */
+(void)adExpoSure:(NSString*)adSeatId AdContentId:(NSString*)adcontentid RequestId:(NSString*)reid;

/**
 主动点击接口

 @param adSeatId 广告位ID
 @param adcontentid 广告内容ID
 @param reid 拉取素材数据返回的请求校验码
 */
+(void)adTrack:(NSString*)adSeatId AdContentId:(NSString*)adcontentid RequestId:(NSString*)reid;

//------------------**AD**---------------------

//------------------**BUGOUT**---------------------
/**
 用户自定义操作信息（会存储于系统操作步骤中）
 
 @param stepMessage 用户自定义操作信息
 */
+ (void)setCustomUserSteps:(NSString *_Nonnull)stepMessage;

/**
 设置用户自定义属性 bug采集
 
 @param data 设置的属性值
 @param key 设置的属性key
 */
+ (void)setUserData:(NSString*_Nonnull)data forKey:(NSString*_Nonnull)key;

/**
 移除所有自定义属性 bug采集
 */
+ (void)removeAllUserData;

/**
 关闭/开启摇一摇
 
 @param enabled 默认YES
 */
+ (void)enabledShakeFeedback:(BOOL)enabled;

/**
 上报自定义异常信息
 
 @param exception 自定义异常
 */
+ (void)reportCustomizedException:(NSException*_Nonnull)exception;

/**
 上报自定义异常
 
 @param type 1 @"cpp" 3 @"lua" 4 @"js" 5 @"c#"
 @param msg 非oc调用
 @param stackTrace 自定义的异常信息
 */
+ (void)reportCustomizedException:(NSNumber*_Nonnull)type message:(NSString*_Nonnull)msg
                       stackTrace:(NSString*_Nonnull)stackTrace;


/**
 上报自定义异常2
 
 @param type 1 @"cpp" 3 @"lua" 4 @"js" 5 @"c#"
 @param msg 非oc调用
 @param stackTrace 自定义的异常信息
 @param isExit  是否系统退出 默认 NO
 */
+ (void)reportCustomizedException:(NSNumber*_Nonnull)type message:(NSString*_Nonnull)msg
                       stackTrace:(NSString*_Nonnull)stackTrace exit:(BOOL)isExit;

/**
 是否临时关闭异常信息采集上报

 @param isCloseCollect 是否关闭 默认为NO
 */
+(void)closeExceptionCollect:(BOOL)isCloseCollect;

//------------------**BUGOUT**---------------------

/**
 设置app渠道来源
 默认为：App Store
 
 @param chan 渠道名称
 */
+ (void)setAppChannel:(NSString * _Nonnull)chan;

/**
 设置用户ID
 
 @param uid userID
 */
+ (void)bindTestinDataUID:(NSString * _Nonnull)uid;

/**
 设置用户ID 带其他用户属性
 
 @param uid 用户id
 @param profileDict 用户属性
 */
+ (void)bindTestinDataUID:(NSString * _Nonnull)uid attributes:(NSDictionary * _Nullable)profileDict;


//-------------------**AB**-------------------

/**
 *  提交指标数据
 *  这里的指标名称必须和后台创建的指标名称相对应,对于后台没创建的指标,我们将不做统计处理
 *  默认对指标的统计以数值累加,default为1
 *
 *  @param eventName  指标名称
 */
+ (void)track:(NSString *_Nonnull)eventName;

/**
 *  自定义指标数值
 *
 *  @param eventName    指标名称
 *  @param value        指标值
 */
+ (void)track:(NSString *_Nonnull)eventName withValue:(NSNumber *_Nonnull)value;

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
 *  设置是否取消使用图片指纹标识符
 *
 *  @param isFobitImageId  取消(YES) 不取消(NO)
 *  默认为NO(轮播图不建议取消)
 */
+(void)fobitImageIdentification:(BOOL)isFobitImageId;

/**
 设置可视化编辑的UIWindow 默认值取application 索引为0的窗口编辑
 
 @param visualWindow 可视化窗口（建议设置程序的主窗口）
 */
+ (void)setVisualWindow:(UIWindow * _Nonnull)visualWindow;
/**
 * 设置是否有智能分流试验 如果有智能分流试验 为了数据准确性请 设置 isAuto 为YES
 *  @param isAuto
 */
+ (void)setAutoShuntMode:(BOOL)isAuto;

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
 *  获得标识符
 *  @return 标识符
 */
+ (NSString* _Nonnull)getClientId;


/**
 *  设置是否只是wifi环境上报数据
 *
 *  @param onlyWifiEnvironmentUpload 默认是NO
 */
+ (void)setOnlyWifi:(BOOL)onlyWifiEnvironmentUpload;
/**
 *  获取当前运行的实验信息
 *
 *  @return 返回的NSArray 包含--layerId(层id)、layerName(层名称)、expName(实验名称)、expId(实验Id)、expVersionId(版本Id)、expVersionName(版本名称)、running(是否触发实验).
 *  若处于轮空状态时,@"expName" @"expId" @"expVersionId" @"expVersionName" 的值为 CONTROL
 */
+ (NSArray * _Nonnull)getAllCurrentExperiments;

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

//-------------------**AB**-------------------


/**
 设置是否自动触发App事件（start&end事件）

 @param isAuto 默认不触发
 */
+(void)supportAutoAppTrack:(BOOL)isAuto;
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
 * 获取SDK版本号
 *
 @return 返回SDK 版本号
 */
+ (NSString * _Nonnull)libVersion;

/**
 * 获取BugOut版本号
 *
 @return 返回BugOut版本号
 */
+(NSString* _Nonnull)libBugOutVersion;

/**
 用于区别多个系统弹框(UIAlertController、UIActionSheet、UIAlertView)
 使用方法：在系统弹框初始化完成后，请调用此方法

 @param alertTag 为当前弹框的初始tag(每个弹框的差值尽量大些)
 */
+(void)beginExecuteAlertInnerTag:(NSInteger)alertTag;


/**
 用于给弹框里每个按钮赋值（tag值）
 UIAlertController使用方法：[self presentViewController:alertController animated:YES completion:^{
 [TestinDataAnalysis endExecuteAlertViewInnerTag];
 }];
 UIActionSheet和UIAlertView的使用方法：
 请在对应的代理方法-(void)didPresentActionSheet:(UIActionSheet *)actionSheet和-(void)didPresentAlertView:(UIAlertView *)alertView中调用此方法。
 */
+(void)endExecuteAlertViewInnerTag;

/**
 获取包的UUID

 @return 返回包的UUID
 */
+(NSString*_Nonnull)executableUUID;



/**
 设置主窗口的属性名称 不设置 默认值 读取window属性
 需要在窗口初始化完毕后调用  示例:[TestinDataAnalysis setMainWindowSelector:@selector(xxxx)];
 @param seletor 设置主窗口的属性方法
 */
+(void)setMainWindowSelector:(SEL _Nonnull )seletor;

//-------------------**DATA**-----------------
/**
 上报埋点
 @param event 埋点名称
 */
+ (void)tracker:(NSString * _Nonnull)event;

/**
 上报埋点 携带属性
 
 @param event 埋点名称
 @param attributes 属性
 */
+ (void)tracker:(NSString * _Nonnull)event attributes:(NSDictionary * _Nullable)attributes;

/**
 上报埋点 携带属性和自定义数值
 
 @param event 埋点名称
 @param attributes 自定义属性
 @param value 自定义数值 默认为1
 */
+ (void)tracker:(NSString * _Nonnull)event attributes:(NSDictionary * _Nullable)attributes withValue:(NSNumber*_Nullable)value;

/**
 指定的UIViewController增加viewPage 事件
 
 @param viewController 指定的viewController
 @param attributes 自定义属性
 */
+ (void)trackViewPage:(UIViewController * _Nonnull)viewController attributes:(NSDictionary * _Nullable)attributes;

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
 清除用户所有属性
 */
+ (void)deleteAllProfile;
//-------------------**DATA**-----------------




@end

@interface UIView (TestinView)
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

/**
 * 针对SDCycleScrollView轮播图框架，所设置的唯一标识。
 * 如SDCycleScrollView是pod导入的，我们的SDK是手动导入的，则建议使用tag。
 * 使用方法：cell.tag = itemIndex + 1;
 * 如SDCycleScrollView和我们的SDK导入方式一致，则可以使用此唯一标识。
 * 使用方法：cell.testinDataViewIdentifier = [NSString stringWithFormat:@"%ld",itemIndex];
 */
@property(nonatomic,copy)NSString* _Nullable testinDataViewIdentifier;
/**
 *  UITableViewCell和UICollectionCell 是否复用
 *
 *  @param forbitReUseTag  YES(开启不复用) NO(原程序运行)
 *  如果cell的个数较多，且没有关闭复用的，建议使用不复用
 *  使用方法：tableView.forbitReUseTag = YES/NO;
 *          collectionView.forbitReUseTag = YES/NO;
 *  (tableView和collectionView为对象名称)
 *  如您没有设置则默认为NO，可能会导致修改cell的时候出现重复修改的现象。
 *  默认为NO
 */
@property(nonatomic,assign)BOOL forbitReUseTag;//是否禁止对象重用(针对UITableViewCell和UICollectionViewCell 复用机制)

@end


