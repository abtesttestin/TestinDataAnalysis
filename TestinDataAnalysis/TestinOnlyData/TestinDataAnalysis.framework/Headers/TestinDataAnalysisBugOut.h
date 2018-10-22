//
//  TestinDataAnalysisBugOut.h
//  TestinDataAnalysis
//  For Cocos&&Unity 插件使用
//  Created by wubo on 2018/8/14.
//  Copyright © 2018年 testin. All rights reserved.
//

#ifndef TestinDataAnalysisBugOut_h
#define TestinDataAnalysisBugOut_h

#define BUGOUT_TYPE_JAVA    0
#define BUGOUT_TYPE_CPP     1
#define BUGOUT_TYPE_OBJC    2
#define BUGOUT_TYPE_LUA     3
#define BUGOUT_TYPE_JS      4
#define BUGOUT_TYPE_CSHARP  5

// 捕获到崩溃时调用，返回当前调用堆栈，不可在该函数内做复杂的操作
typedef void (*crashNotificationCallBack)(const char*);

typedef struct __BugoutCallback
{
    crashNotificationCallBack     crashNotificationCallBack;        //default NULL
}TestinDataBugoutCallback;

typedef struct __BugoutCConfig
{
    int enabledMonitorException;       // default 1
    int enabledShakeFeedback;          // default 0
    double shakeSenseSpeed;            // default 3.0
    int reportOnlyWIFI;                // default 0
    int enableUserSteps;               // default 1
    int crashScreenshot;               // default 0
    int snapshotMode;                  // default 1
    TestinDataBugoutCallback callback; // callback struct
    
}TestinDataBugCConfig;
#ifdef __cplusplus
extern "C" {
#endif
    void bugoutInit(const char* cAppId);
    void bugoutInitWithConfig(const char* cAppId, TestinDataBugCConfig config);
    void bugoutReportException(int nType,const char* cMessage,const char* cStacktrace,int isExit);
    void bugoutSetUserData(const char* cKey, const char* cData);
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wstrict-prototypes"
    void bugoutRemoveAllUserData();
    #pragma clang diagnostic pop
    void bugoutEnabledShakeFeedback(int enabled);
    #if 0
    void bugoutLog(const char* cString);
    #endif
    void bugoutCustomUserSteps(const char* userSteps);
    
#ifdef __cplusplus
}
#endif

#endif /* TestinDataAnalysisBugOut_h */
