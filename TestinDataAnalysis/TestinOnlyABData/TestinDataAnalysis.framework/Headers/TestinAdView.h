//
//  TestinAdView.h
//  TestinDataAnalysis
//
//  Created by wubo on 2018/12/6.
//  Copyright © 2018年 testin. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface TestinAdView : UIView
@property(nonatomic,copy)NSString* _Nullable testinAdtitile;
@property(nonatomic,strong)UIViewController* _Nullable parentViewController;
@property(nonatomic,assign)BOOL canTouch;
@property(nonatomic,assign)BOOL showAdCloseIcon;
@property(nonatomic,strong)UIImage* _Nullable adCloseIcon;
@property(nonatomic,assign)BOOL showAdIcon;
@property(nonatomic,strong)UIImage* _Nullable adIcon;
@property (nonatomic,copy) void(^ _Nullable onReceiveAdSucess)(void);
@property (nonatomic,copy) void(^ _Nullable onReceiveAdFailed)(void);
@property (nonatomic,copy) void(^ _Nullable onLoadAdFailed)(void);
@property (nonatomic,copy) void(^ _Nullable onAdTrack)(NSString*_Nonnull);
@property (nonatomic,copy) void(^ _Nullable onAdExpoSure)(void);
@property (nonatomic,copy) void(^ _Nullable onAdCompleted)(void);
@property (nonatomic,copy) void(^ _Nullable onAdClosed)(void);

-(void)loadTestinAd;
-(void)testinAdClick;
-(void)testinAdClosed;


@end

@interface TestinBannerAdView : TestinAdView

+(instancetype _Nonnull)createTestinAdBannerViewWithFrame:(CGRect)frame adSeatId:(NSString* _Nonnull)adSeatId parentViewController:(UIViewController* _Nullable)parentViewController showAdIcon:(BOOL)showAdIcon adIcon:(UIImage*_Nullable)adIcon onReceiveAdSucess:(void(^_Nullable)(void))onReceiveAdSucess onReceiveAdFailed:(void(^_Nullable)(void))onReceiveAdFailed onLoadAdFailed:(void(^_Nullable)(void))onLoadAdFailed onAdExpoSure:(void(^_Nullable)(void))onAdExpoSure onAdTrack:(void(^_Nullable)(NSString* _Nullable targetUrl))onAdTrack;

@end

@interface TestinFloatAdView : TestinAdView

+(instancetype _Nonnull)createTestinAdFloatViewWithFrame:(CGRect)frame adSeatId:(NSString * _Nonnull)adSeatId parentViewController:(UIViewController *_Nullable)parentViewController showAdIcon:(BOOL)showAdIcon adIcon:(UIImage* _Nullable)adIcon showCloseIcon:(BOOL)show adCloseIcon:(UIImage*_Nullable)adCloseIcon onReceiveAdSucess:(void (^_Nullable)(void))onReceiveAdSucess onReceiveAdFailed:(void (^_Nullable)(void))onReceiveAdFailed onLoadAdFailed:(void (^_Nullable)(void))onLoadAdFailed onAdExpoSure:(void (^_Nullable)(void))onAdExpoSure onAdTrack:(void (^_Nullable)(NSString* _Nullable targetUrl))onAdTrack onAdClosed:(void(^_Nullable)(void))onAdClosed;

@end

@interface TestinLauchAdView : TestinAdView

 +(instancetype _Nonnull)createTestinAdLauchViewWithFrame:(CGRect)frame adSeatId:(NSString * _Nonnull)adSeatId parentViewController:(UIViewController *_Nullable)parentViewController showAdIcon:(BOOL)showAdIcon adIcon:(UIImage* _Nullable)adIcon showCloseIcon:(BOOL)show adCloseIcon:(UIImage*_Nullable)adCloseIcon onReceiveAdSucess:(void (^_Nullable)(void))onReceiveAdSucess onReceiveAdFailed:(void (^_Nullable)(void))onReceiveAdFailed onLoadAdFailed:(void (^_Nullable)(void))onLoadAdFailed onAdExpoSure:(void (^_Nullable)(void))onAdExpoSure onAdTrack:(void (^_Nullable)(NSString* _Nullable targetUrl))onAdTrack onAdCompleted:(void(^_Nullable)(void))onAdCompleted onAdClosed:(void(^_Nullable)(void))onAdClosed;

@end

@interface TestinScreenAdView : TestinAdView

+(instancetype _Nonnull)createTestinAdScreenViewWithFrame:(CGRect)frame adSeatId:(NSString * _Nonnull)adSeatId parentViewController:(UIViewController *_Nullable)parentViewController showAdIcon:(BOOL)showAdIcon adIcon:(UIImage* _Nullable)adIcon showCloseIcon:(BOOL)show adCloseIcon:(UIImage*_Nullable)adCloseIcon onReceiveAdSucess:(void (^_Nullable)(void))onReceiveAdSucess onReceiveAdFailed:(void (^_Nullable)(void))onReceiveAdFailed onLoadAdFailed:(void (^_Nullable)(void))onLoadAdFailed onAdExpoSure:(void (^_Nullable)(void))onAdExpoSure onAdTrack:(void (^_Nullable)(NSString* _Nullable targetUrl))onAdTrack onAdClosed:(void(^_Nullable)(void))onAdClosed;

@end



