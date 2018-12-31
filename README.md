<p align="left" >
  <img src="http://prj.testin.cn:8200/abtest-wiki/abtest-doc/uploads/7e23f765a45b5219cd765e53e92fbfa2/67878DB22483AB928C7BD93795E9E750.png" title="Testin logo" float=left>
</p>

![GitHub license](https://img.shields.io/badge/build-passing-brightgreen.svg)
![CocoaPods Compatible](https://img.shields.io/badge/pod-v5.1.4-blue.svg)
![Platform](https://img.shields.io/badge/platform-ios-lightgrey.svg)
![owner](https://img.shields.io/badge/owner-Testin-green.svg)

## 欢迎您使用 Testin A/B、Data、BugOut 三合一产品,对,没错3种功能 尽在Testin！

- **AB测试**(Testin AB):
 对iOS应用我们提供两种A/B测试模式：可视化模式和编程模式。
>>**可视化模式**:
仅需在第一次集成SDK时添加相关代码，之后进行的每一个可视化模式的A/B测试试验，产品和运营只需要通过可视化的操作方式就可以完成新版本编辑、指标埋点、新版本上线、对比新老版本数据、产品决策等整个A/B测试流程。可视化模式适用于App UI相关的A/B测试，例如修改按钮文案、按钮颜色、控件透明度、隐藏控件、替换控件背景图等场景。可视化模式的优势在于，产品和运营同学可以零代码独立完成新版本的编辑，并且新版本可以实时在用户的App中生效，不需要等待应用市场的审核，极大加快了产品迭代的速度。对于iOS可视化模式支持的控件类型请见常见问题答疑。  
**编程模式**:需要在每一个A/B测试的试验中添加相关的代码。相比可视化模式，编程模式的优势在于App的大小改版都可以通过编程模式实现，应用范围比可视化模式广泛，例如将支付流程从3步改成2步，只能通过编程模式实现。编程模式需要配合App应用市场的发版，不能像可视化模式一样实时生效。

- **数据运营分析**(Testin Data):
Testin Data是一款可以私有化部署的用户行为分析产品。

- **缺陷管理**(Testin BugOut):
Testin Bugout是一款完全免费的缺陷管理系统，可以收集来自各个渠道和设备的Bug问题，通过自定义自动化规则并与企业的开发工具集成，
帮助企业高效的收集，跟进，解决Bug问题

- **广告平台**(Testin AD):
Testin AD是一个互动广告平台，广告主可获得更好的投放效果，媒体方能得到更好的流量变现效率，受众端具有更好的用户体验。

## Requirements
- iOS 7.0 or later
- Xcode 7.3 or later

## Getting Started
- Read this <a href="https://data.testin.cn/docs/api/iosv4/index.html" target="_blank">API reference</a>
- Read this <a href="https://data.testin.cn/docs/" target="_blank">Help doc</a>
- Read this <a href="https://cocoadocs.org/docsets/TestinDataAnalysis/5.1.4/Classes/TestinDataAnalysis.html" target="_blank">documentation @ CocoaDocs</a>

## How To Use

<pre>
#import < TestinDataAnalysis/TestinDataAnalysis.h >

<del>[TestinDataAnalysis enableEditor];</del> //4.1.2 及之后版本废除此API方法。

<del>[TestinDataAnalysis setDebugTouchAssist:YES]; //开启悬浮助手，整合可视化开关和集成调试功能。
[TestinDataAnalysis initWithAppkey:@"Your AppKey" launchOptions:launchOptions];</del>
AB:
TestinDataConfig* config=[TestinDataConfig shareConfig];
config.debugTouchAssist=YES;//开启悬浮助手，整合可视化开关和集成调试功能。
[TestinDataAnalysis initWithAppkey:@"Your AppKey" WithConfig:config launchOptions:launchOptions];//初始化AB业务
BugOut:
TestinDataConfig* config=[TestinDataConfig shareConfig];
config.enabledShakeFeedback=YES;//开启摇一摇上报bug
config.enabledMonitorException=YES;//开启崩溃异常捕捉
[TestinDataAnalysis initWithProjectId:@"BugOut AppKey" WithConfig:config launchOptions:launchOptions];//初始化bugout业务
AD:
TestinDataConfig * config = [TestinDataConfig shareConfig];
config.printAdLog = YES;//开启广告日志
[TestinDataAnalysis initWithAdAppKey:@"媒体主申请的AppKey" WithConfig:config launchOptions:launchOptions];//初始化AD业务
    
</pre>

```
+ (id)getExperimentVariable:(NSString *)variableName defaultValue:(id)defaultvalue;

example :
NSString *value = [TestinDataAnalysis getExperimentVariable:@"themeColor" defaultValue:@"red"];
    if ([value isEqualToString:@"red"]) {
        button.backgroundColor = [UIColor redColor];
    } else if ([value isEqualToString:@"green"]) {
        button.backgroundColor = [UIColor redColor];
    } else {
        //do something
}
```
```
+ (void)track:(NSString *)eventName;//指标数值每次加1
+ (void)track:(NSString *)eventName withValue:(NSNumber *)value;// 自定义指标数值

example :
[TestinDataAnalysis track:@"settingClick"];
[TestinDataAnalysis track:@"settingClick" withValue:@1];
Testin Data 部分请参考相关API

```
- For details about how to use the library and clear examples, see <a href="http://ab.testin.cn/docs/" target="_blank">The detailed How to use</a>
## Noun explanation
- [Noun details](http://ab.testin.cn/docs/dict.html)

## Installation 
There are three ways to use TestinDataAnalysis in your project:
- download from [Here](http://ab.testin.cn/docs/iossdk.html)
- using CocoaPods
### Installation with CocoaPods

[CocoaPods](http://cocoapods.org/) is a dependency manager for Objective-C, which automates and simplifies the process of using 3rd-party libraries in your projects. See the [Get Started](http://cocoapods.org/#get_started) section for more details.

#### Podfile
To integrate TestinDataAnalysis into your Xcode project using CocoaPods, specify it in your `Podfile`:

```ruby
platform :ios, '7.0'
target 'TargetName' do
pod 'TestinDataAnalysis' '5.1.4'
end
```

Then, run the following command:

```bash
$ pod install
```
### Build Project
At this point your workspace should build without error. If you are having problem, you can call me to solve it.

## Author
- [Testin A/B Testing Developer](https://github.com/abtesttestin)

## Licenses

All source code is licensed under the [MIT License](https://raw.githubusercontent.com/abtesttestin/TestinDataAnalysis/master/LICENSE).
