//
//  LSVideoItem.h
//  LittlstarSDK
//
//  Created by Littlstar on 11/05/2015
//  Copyright (c) 2015 Little Star Media, Inc. (Littlstar). All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <LittlstarSDK/LSUser.h>

/**
 * States for downloading videos
 */
enum {
    LSVideoNotDownloaded = 0,
    LSVideoDownloading,
    LSVideoDownloaded
};
typedef NSUInteger LSVideoDownloadState;


/**
 *  Class LSVideoItem, describes details of the video, fetched from Littlstar video service.
 */
@interface LSVideoItem : NSObject

// Video item properties

/**
 * Unique item ID within videos.
 */
@property (nonatomic, readwrite) NSUInteger videoId;

/**
 * Unique item ID in LS service.
 */
@property (nonatomic, readwrite) NSString *slug;

/**
 * Video title.
 */
@property (nonatomic, readwrite) NSString *title;

/**
 * Short video description.
 */
@property (nonatomic, readwrite) NSString *desc;

/**
 * View count for a specific video.
 */
@property (nonatomic, readwrite) NSUInteger views;

/**
 * Star count given for a specific video.
 */
@property (nonatomic, readwrite) NSUInteger stars;

/**
 * Downvote count for a specific video.
 */
@property (nonatomic, readwrite) NSUInteger downVotes;

/**
 * User star value, valid only when logged in.
 */
@property (nonatomic, readwrite) BOOL stared;

/**
 * User downvote value, valid only when logged in.
 */
@property (nonatomic, readwrite) BOOL downvoted;

/**
 * Creation date of item
 */
@property (nonatomic, readwrite) NSString *creationDate;

/**
 * Video URL for the video in LS service.
 */
@property (nonatomic, readwrite) NSString *videoURL;

/**
 * Live video HLS URL for the video in LS service.
 */
@property (nonatomic, readwrite) NSString *hlsURL;


/**
 * URL for 2D image, can be used as a background image in UI etc. May be nil value.
 */
@property (nonatomic, readwrite) NSString *bannerURL;

/**
 * URL to a small image, can be used as a thumbnail image for video.
 */
@property (nonatomic, readwrite) NSString *thumbURL;

/**
 * URL to another small image, can be used as a thumbnail image for video.
 */
@property (nonatomic, readwrite) NSString *smallThumbURL;

/**
 * Property that tells whether the video is downloadable.
 */
@property (nonatomic, readwrite) BOOL download;

/**
 * Video owner user info.
 */
@property (nonatomic, readwrite) LSUser *user;

/**
 * Download state of a video defined in VideoItem.
 */
@property (nonatomic, readwrite) LSVideoDownloadState downloadState;

/**
 * Property that tells whether the video is live stream.
 */
@property (nonatomic, readwrite) BOOL live;

/**
 * Property that tells whether the video is 3d and mode side by side.
 */
@property (nonatomic, readwrite) BOOL sbs3d;

/**
 * Property that tells whether the video is 3d and mode over and under.
 */
@property (nonatomic, readwrite) BOOL ou3d;

/**
 * Property that tells whether the video loops.
 */
@property (nonatomic, readwrite) BOOL loop;

/**
 *  Initial diagonal fov (field of view) in degrees (fovMin -> fovMax).
 *
 *  Default value 90.
 */
@property (nonatomic) CGFloat fovDefault;

/**
 *  Maximum diagonal fov (field of view) in degrees (fovMin -> 180).
 *
 *  Default value 120.
 */
@property (nonatomic) CGFloat fovMax;

/**
 *  Minimum diagonal fov (field of view) in degrees (0 -> fovMax).
 *
 *  Default value 60.
 */
@property (nonatomic) CGFloat fovMin;

/**
 *  Initial yaw angle(rotation around y-axis) in degrees.
 *
 *  Default value 180(centered).
 */
@property (nonatomic) CGFloat yawAngle;

@end
