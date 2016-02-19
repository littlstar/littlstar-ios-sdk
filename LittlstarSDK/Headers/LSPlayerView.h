//
//  LSPlayerView.h
//  LittlstarSDK
//
//  Created by Littlstar on 11/05/2015
//  Copyright (c) 2015 Little Star Media, Inc. (Littlstar). All rights reserved.
//

#import <UIKit/UIKit.h>
#import <LittlstarSDK/LSContentManager.h>
#import <LittlstarSDK/LSVideoItem.h>
#import <LittlstarSDK/LSPhotoItem.h>

@protocol LSPlayerViewDelegate;

/**
 *  Class LSPlayerView, provides simple LSPlayerView for viewing 360 image or video.
 */
@interface LSPlayerView : UIView

/**
 *  LSPlayerView delegate, callback interface for the caller object.
 */
@property (nonatomic, weak) id <LSPlayerViewDelegate> delegate;

/**
 *  Gesture mode disabled. When set YES, no gestures (panning etc.) can be used to
 *  control content internally. Default NO.
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
 *  Device orientation portrait. Affects screen dividing in VR mode. 
 *  If YES -> screen is divided to top and botton halves, else (NO, default) -> to left and right halves.
 */
@property (nonatomic) BOOL uiInterfaceOrientationPortrait;

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
 * Scrolling speed factor, 0.0f - 1.0f, default: 1.0f
 */
@property (nonatomic) CGFloat scrollSpeed;

/**
 *  Initializes Littlstar 360 video with given video item, license file url.
 *
 *  NOTE: If the selected video is stored locally LSPlayerView automatically selects it instead of remote video.
 *
 *  @param videoItem       The video item of the selected video, defined in LSVideoItem.h.
 *  @param contentManager  Reference to LSContentManager
 *  @param licenseFileUrl  Url to license file
 *
 *  @see LSContentManager.h
 *  @see LSVideoItem.h
 */
-(void)initVideoWithVideoItem:(LSVideoItem*)videoItem contentManager:(LSContentManager*)contentManager licenseFileUrl:(NSURL *)licenseFileUrl;

/**
 *  Initializes orion 360 image with given video item, license file url.
 *
 *  @param photoItem       The photo item of the selected photo, defined in LSPhotoItem.h.
 *  @param contentManager  Reference to LSContentManager
 *  @param licenseFileUrl  Url to license file
 *
 *  @see LSContentManager.h
 *  @see LSPhotoItem.h
 */
-(void)initPhotoWithPhotoItem:(LSPhotoItem*)photoItem contentManager:(LSContentManager*)contentManager licenseFileUrl:(NSURL *)licenseFileUrl;

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
 *  LSPlayerViewDelegate protocol defines the optional methods implemented by
 *  delegates of the LSPlayerView class.
 */
@protocol LSPlayerViewDelegate
@optional

/**
 *  Tells the delegate that 360 video reached end.
 *
 *  @param lsPlayerView LSPlayerView
 */
- (void)lsPlayerViewVideoDidReachEnd:(LSPlayerView*)lsPlayerView;

/**
 *  Tells the delegate that 360 video is ready to be played, called after initialization of the video.
 *
 *  @param lsPlayerView LSPlayerView
 */
- (void)lsPlayerViewReadyToPlayVideo:(LSPlayerView*)lsPlayerView;

/**
 *  Tells the delegate that video progress values were updated.
 *
 *  @param lsPlayerView    LSPlayerView
 *  @param currentTime   Current progress time
 *  @param availableTime Available time
 *  @param totalDuration Total video duration
 */
- (void)lsPlayerViewDidUpdateProgress:(LSPlayerView*)lsPlayerView currentTime:(CGFloat)currentTime availableTime:(CGFloat)availableTime totalDuration:(CGFloat)totalDuration;

/**
 *  Tells the delegate that video progress values were updated.
 *
 *  @param lsPlayerView    LSPlayerView
 *  @param currentTime   Current progress time
 *  @param totalDuration Total video duration
 *  @param loadedTimeRanges  This property provides a collection of time ranges for which the player has the media data readily available. The ranges provided might be discontinuous.
 */
- (void)lsPlayerViewDidUpdateProgress:(LSPlayerView*)lsPlayerView currentTime:(CGFloat)currentTime totalDuration:(CGFloat)totalDuration loadedTimeRanges:(NSArray*)loadedTimeRanges;

/**
 *  Tells the delegate that 360 video buffering status changed, e.g. in initialization phase or due to a slow network connection.
 *
 *  @param lsPlayerView LSPlayerView
 *  @param buffering  New buffering status
 */
- (void)lsPlayerViewDidChangeBufferingStatus:(LSPlayerView*)lsPlayerView buffering:(BOOL)buffering;

@end
