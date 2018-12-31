//
//  TestinADWebViewController.h
//  TestinDataAnalysis
//
//  Created by wubo on 2018/11/29.
//  Copyright © 2018年 cn.Testin. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TestinADWebViewController : UIViewController
@property(nonatomic,copy)NSString* loadUrlStr;//加载url
//设置导航栏的背景颜色
@property (nonatomic, strong) UIColor * navBackgroundColor;
//设置导航栏的标题字体颜色
@property (nonatomic, strong) UIColor * navTitleColor;
//设置“返回”和“关闭”按钮的字体颜色
@property (nonatomic, strong) UIColor * navButtonColor;
//是否隐藏导航栏 默认为：NO
@property (nonatomic, assign) BOOL isHidden;
@end

NS_ASSUME_NONNULL_END
