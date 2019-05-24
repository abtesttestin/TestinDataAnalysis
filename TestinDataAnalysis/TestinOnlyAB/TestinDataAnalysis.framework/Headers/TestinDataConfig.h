//
//  TestinDataConfig.h
//  TestinDataAnalysis
//
//  Created by wubo on 2018/8/1.
//  Copyright © 2018年 testin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TestinDataBugoutDelegate.h"
#import "TestinDataAnalysisBugOut.h"
#import "TestinAdView.h"
#import "TestinADWebViewController.h"
#import "TestinImageView.h"
#import "TestinAdNative.h"
@interface TestinDataConfig : NSObject
/**
 * 广告appkey
 */
@property(nonatomic,copy)NSString* adAppKey;

/**
 *设置是否禁止广告控件自动跳转页面 默认为NO 不禁止  设置为YES 可以跳转到用户需要的页面 不使用平台提供的页面
 */
@property(nonatomic,assign)BOOL forbidAutoAdSkip;
/*
 * 是否开启打印广告模块日志
 */
@property(nonatomic,assign)BOOL printAdLog;
/*
 * 设置广告平台serverUrl 不设置会使用默认的线上地址
 */
@property(nonatomic,copy)NSString * adServerUrl;
/**
 *ABTestappkey
 */
@property(nonatomic,copy)NSString* abAppKey;
/**
 *下拉配置url
 */
@property(nonatomic,copy)NSString* configUrl;
/**
 *上报数据url
 */
@property(nonatomic,copy)NSString* uploadUrl;

/**
 *AB上报和下拉url
 */
@property(nonatomic,copy)NSString* abServerUrl;

/**
 *自定义DataSocketUrl
 */
@property(nonatomic,copy)NSString* dataSocketUrl;

/**
 *自定义ABSocketUrl
 */
@property(nonatomic,copy)NSString* abSocketUrl;

/**
 悬浮按钮(小助手)，延迟显示的时间间隔。默认为：1
 */
@property(nonatomic,assign)NSTimeInterval debugTouchAssistDelayInterval;
/**
  可视化图片截图压缩比。默认为：0.5  如果希望可视化编辑图片像素要求不高 可以设置0.2 左右 保证速率
 */
@property(nonatomic,assign)float visualImageCompressRate;
/**
 *  设置是否显示调试悬浮按钮  集成了可视化和集成调试入口
 */
@property(nonatomic,assign) BOOL debugTouchAssist;//默认是NO
/*
 * 设置是否开启打印AB模块日志
 *
 */
@property(nonatomic,assign)BOOL printABLog;

/**
 设置AB多维标签是否携带自定义标签 默认为NO
 */
@property(nonatomic,assign)BOOL isMultidimensionalWithCustomLabel;

//========以下bug收集相关========
/**
 *
 * 数据通知的代理
 */
@property(nonatomic, strong) id delegate;
/**
 *Exception monitor enabled, default YES.
 *启用异常监视器,默认：YES
 */
@property(nonatomic, assign) BOOL enabledMonitorException;

/**
 *是否开启崩溃截图,默认：NO
 */
@property(nonatomic, assign) BOOL crashScreenshot;

/**
 *Enabled feedback, default NO.
 *启用摇一摇反馈，默认:NO
 */
@property(nonatomic, assign) BOOL enabledShakeFeedback;
/**
 *
 *Response speed settings, the greater the value of the slower response speed, the smaller the faster the response, the value is too large may lose response, the default 3.0
 *响应速度设置值越大，响应速度越慢，响应越快，值越大，则可能丢失响应，默认为3.0。
 *
 *
 */
@property(nonatomic, assign) NSTimeInterval shakeSenseSpeed;
/**
 * only wifi report data, default YES.
 * 只有WiFi报告数据，默认:YES
 */
@property(nonatomic, assign) BOOL reportOnlyWIFI;

/**
 * use user location info, default NO.
 * 是否开启用户定位信息。默认：NO
 * 如APP上有定位设置，推荐设置为：YES
 */
@property(nonatomic, assign) BOOL useLocationInfo;

/**
 * Whether or not to open the user's operation steps,default YES.
 * 是否开启用户操作步骤。默认：YES
 */
@property(nonatomic, assign) BOOL enableUserSteps;
/**
 *Open the system log. default NO
 *开启系统日志。默认：NO
 */
@property(nonatomic, assign) BOOL enableSysLog;

/**
 屏幕快照模式  0 为App模式 1为游戏类模式  默认为游戏类模式
 */
@property(nonatomic,assign)int snapshotMode;
/*
 * 设置是否打印BugOut日志
 *
 */
@property(nonatomic,assign)BOOL printBugOutLog;

// ---base config optimize---

/**
 设置是否自动触发App事件（start&end事件）
 */
@property(nonatomic,assign)BOOL supportAutoAppTrack;

/**
 设置是否开始自动埋点viewClick事件
 */
@property(nonatomic,assign)BOOL supportAutoViewClickTrack;

/**
 设置是否开始自动埋点viewPage事件
 */
@property(nonatomic,assign)BOOL supportAutoViewPageTrack;

/**
 针对UIControl控件以及子类
 设置是否对已经可视化埋点的位置支持主动埋点 默认是不支持,限制的
 */
@property(nonatomic,assign)BOOL supportUIControlAutoTrackForAlreadyVTrack;

/**
 设置是否支持触摸开始时候track 此方法主要针对UIControl 实现了UITouchDown 事件的情况
 */
@property(nonatomic,assign)BOOL supportTouchBeginState;

/**
 是否支持获取IDFA
 */
@property(nonatomic,assign)BOOL enableIDFA;

/**
 设置主窗口的属性名称 不设置 默认值 读取window属性
 需要在窗口初始化完毕后调用
 */
@property(nonatomic,assign)SEL widowSelector;

/**
 设置可视化编辑的UIWindow 默认值取application 索引为0的窗口编辑 建议设置程序的主窗口
 */
@property (nonatomic, strong) UIWindow *visualWindow;

/**
 设置是否有智能分流试验 如果有智能分流试验 为了数据准确性请设置 isAutoShuntMode=YES
 */
@property(nonatomic,assign)BOOL isAutoShuntMode;

/**
 设置是否取消使用图片指纹标识符 取消(YES) 不取消(NO) 
 */
@property(nonatomic,assign)BOOL fobitImageIdentification;
+(TestinDataConfig*)shareConfig;
@end
