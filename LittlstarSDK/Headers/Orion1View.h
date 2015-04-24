//
//  Orion1View.h
//  LittlstarSDK
//
//  Created by Hannu Limma on 13.04.2015.
//  Copyright (c) 2015 Finwe Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <LittlstarSDK/LSContentManager.h>
#import <LittlstarSDK/LSVideoItem.h>

@protocol Orion1ViewDelegate;

/**
 *  Class Orion1View, provides simple OrionView for viewing 360 image or video.
 */
@interface Orion1View : UIView

/**
 *  Orion1View delegate, callback interface for the caller object.
 */
@property (nonatomic, weak) id <Orion1ViewDelegate> delegate;

/**
 *  Gesture mode disabled. When set YES, no gestures (panning etc.) can be used to
 *  control OrionContent internally. Default NO.
 */
@property (nonatomic) BOOL touchGesturesDisabled;

/**
 *  Sensors disabled. Turning the device rotates the view, the user is able "turn" in the video view. Uses the device gyroscope sensors to function. Default NO.
 */
@property (nonatomic) BOOL sensorsDisabled;

/**
 *  VR mode enabled. Divides view into two halves so that the video suitable for a HMD device, e.g. cardboard or googles. Default NO.
 */
@property (nonatomic) BOOL vrModeEnabled;

/**
 *  Preview image mode. When set YES, preloaded UIImage or new texture generated from given video URL is shown
 *  in 360 video view. Default NO.
 */
@property (nonatomic) BOOL previewImageMode;

/**
 *  Current video total duration in seconds.
 */
@property (nonatomic, readonly) CGFloat totalDuration;

/**
 *  Initializes orion 360 video with given video item, license file url.
 *
 *  NOTE: If the selected video is stored locally Orion1View automatically selects it instead of remote video.
 *
 *  @param videoItem       The video item of the selected video, defined in LSVideoItem.h.
 *  @param contentManager  Reference to LSContentManager
 *  @param licenseFileUrl  Url to license file
 */
-(void)initVideoWithVideoItem:(LSVideoItem*)videoItem contentManager:(LSContentManager*)contentManager licenseFileUrl:(NSURL *)licenseFileUrl;

/**
 *  Plays 360 video starting from given location.
 *
 *  @param seekTo Given location in seconds
 */
-(void)play:(CGFloat)seekTo;

/**
 *  Plays 360 video.
 */
-(void)play;

/**
 *  Pauses 360 video.
 */
-(void)pause;

/**
 *  Returns true, if current 360 video playback is paused.
 *
 *  @return YES, if current video playback is paused, otherwise NO
 */
-(BOOL)isPaused;

/**
 *  Seeks 360 video to given location.
 *
 *  @param seekTo Given location in seconds
 */
-(void)seekTo:(CGFloat)seekTo;

@end

/**
 *  Orion1ViewDelegate protocol defines the optional methods implemented by
 *  delegates of the Orion1View class.
 */
@protocol Orion1ViewDelegate
@optional

/**
 *  Tells the delegate that 360 video reached end.
 *
 *  @param orion1View Orion1View
 */
- (void)orion1ViewVideoDidReachEnd:(Orion1View*)orion1View;

/**
 *  Tells the delegate that 360 video is ready to be played, called after initialization of the video.
 *
 *  @param orion1View Orion1View
 */
- (void)orion1ViewReadyToPlayVideo:(Orion1View*)orion1View;

/**
 *  Tells the delegate that video progress values were updated.
 *
 *  @param orion1View    Orion1View
 *  @param currentTime   Current progress time
 *  @param availableTime Available time
 *  @param totalDuration Total video duration
 */
- (void)orion1ViewDidUpdateProgress:(Orion1View*)orion1View currentTime:(CGFloat)currentTime availableTime:(CGFloat)availableTime totalDuration:(CGFloat)totalDuration;

/**
 *  Tells the delegate that 360 video buffering status changed, e.g. in initialization phase or due to a slow network connection.
 *
 *  @param orion1View Orion1View
 *  @param buffering  New buffering status
 */
- (void)orion1ViewDidChangeBufferingStatus:(Orion1View*)orion1View buffering:(BOOL)buffering;

@end