//
//  TestinImageView.h
//  TestinDataAnalysis
//
//  Created by wubo on 2018/12/10.   引用YLGifeImage 相关实现
//  Copyright © 2018年 testin. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TestinGIFImage : UIImage

/**
 A C array containing the frame durations.
 
 The number of frames is defined by the count of the `images` array property.
 */

@property (nonatomic, readonly) NSTimeInterval *testinFrameDurations;

/**
 Total duration of the animated image.
 */
@property (nonatomic, readonly) NSTimeInterval testinTotalDuration;

/**
 Number of loops the image can do before it stops
 */
@property (nonatomic, readonly) NSUInteger testinLoopCount;


/**
 根据帧索引获取相应的图片

 @param idx
 @return UIImage
 */
- (UIImage*)getTestinFrameWithIndex:(NSUInteger)idx;

@end


@interface TestinImageView : UIImageView

@property (nonatomic, copy) NSString *testinRunLoopMode;

@end

NS_ASSUME_NONNULL_END
