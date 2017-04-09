![logo](https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1491757674584&di=18f1a244f0c4235a85f22c13a8bad261&imgtype=0&src=http%3A%2F%2Fcdn.huodongxing.com%2Ffile%2F20150420%2F11822B573E4AF11B2FB748630CB3D56366%2F30251999772063521.png)

![GitHub license](https://img.shields.io/badge/build-passing-brightgreen.svg)
![CocoaPods Compatible](https://img.shields.io/badge/pod-v4.0.5-blue.svg)
![Platform](https://img.shields.io/badge/platform-ios-lightgrey.svg)
![owner](https://img.shields.io/badge/owner-Testin-green.svg)

## 欢迎您使用Testin A/B 测试，用A/B测试驱动产品优化，就找Testin！
对iOS应用我们提供两种A/B测试模式：可视化模式和编程模式。

- **可视化模式**仅需在第一次集成SDK时添加相关代码，之后进行的每一个可视化模式的A/B测试试验，产品和运营只需要通过可视化的操作方式就可以完成新版本编辑、指标埋点、新版本上线、对比新老版本数据、产品决策等整个A/B测试流程。可视化模式适用于App UI相关的A/B测试，例如修改按钮文案、按钮颜色、控件透明度、隐藏控件、替换控件背景图等场景。可视化模式的优势在于，产品和运营同学可以零代码独立完成新版本的编辑，并且新版本可以实时在用户的App中生效，不需要等待应用市场的审核，极大加快了产品迭代的速度。对于iOS可视化模式支持的控件类型请见常见问题答疑。
- **编程模式**需要在每一个A/B测试的试验中添加相关的代码。相比可视化模式，编程模式的优势在于App的大小改版都可以通过编程模式实现，应用范围比可视化模式广泛，例如将支付流程从3步改成2步，只能通过编程模式实现。编程模式需要配合App应用市场的发版，不能像可视化模式一样实时生效。

## Requirements
- iOS 7.0 or later
- Xcode 7.3 or later

## Getting Started
- Read this <a href="http://ab.testin.cn/docs/api/iosv4/index.html" target="_blank">API reference</a>
- Read this <a href="http://ab.testin.cn/docs/" target="_blank">Help doc</a>
- Read this <a href="http://cocoadocs.org/docsets/TestinDataAnalysis/4.0.5/Classes/TestinDataAnalysis.html" target="_blank">documentation @ CocoaDocs</a>

## How To Use
```
#import <TestinDataAnalysis/TestinDataAnalysis.h>
...
[TestinDataAnalysis enableEditor]; //开启可视化模式，此方法必须在初始化方法前调用，且正式发布的版本需去除本行代码
[TestinDataAnalysis initWithAppkey:@"Your AppKey" launchOptions:launchOptions];
```
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
+ (void)tracker:(NSString *)eventName;//指标数值每次加1
+ (void)tracker:(NSString *)eventName withValue:(NSNumber *)value;// 自定义指标数值

example :
[TestinDataAnalysis tracker:@"settingClick"];
```
- For details about how to use the library and clear examples, see <a href="http://ab.testin.cn/docs/" target="_blank">The detailed How to use</a>

## Installation 
There are three ways to use TestinDataAnalysis in your project:
- download from [Here](http://ab.testin.cn/docs/iossdk.html)
- using CocoaPods
### Installation with CocoaPods

[CocoaPods](http://cocoapods.org/) is a dependency manager for Objective-C, which automates and simplifies the process of using 3rd-party libraries in your projects. See the [Get Started](http://cocoapods.org/#get_started) section for more details.

#### Podfile
```
platform :ios, '7.0'
	pod 'TestinDataAnalysis'
end
```
### Build Project
At this point your workspace should build without error. If you are having problem, you can call me to solve it.

## Author
- [Testin A/B Testing Developer](https://github.com/abtesttestin)

## Licenses

All source code is licensed under the [MIT License](https://raw.githubusercontent.com/abtesttestin/TestinDataAnalysis/master/LICENSE).
