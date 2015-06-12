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
@property (nonatomic, readonly) NSUInteger videoId;

/**
 * Unique item ID in LS service.
 */
@property (nonatomic, readonly) NSString *slug;

/**
 * Video title.
 */
@property (nonatomic, readonly) NSString *title;

/**
 * Short video description.
 */
@property (nonatomic, readonly) NSString *desc;

/**
 * View count for a specific video.
 */
@property (nonatomic, readonly) NSUInteger views;

/**
 * Star count given for a specific video.
 */
@property (nonatomic, readonly) NSUInteger stars;

/**
 * Downvote count for a specific video.
 */
@property (nonatomic, readonly) NSUInteger downVotes;

/**
 * User star value, valid only when logged in.
 */
@property (nonatomic, readonly) BOOL stared;

/**
 * User downvote value, valid only when logged in.
 */
@property (nonatomic, readonly) BOOL downvoted;

/**
 * Creation date of item
 */
@property (nonatomic, readonly) NSString *creationDate;

/**
 * Video URL for the video in LS service.
 */
@property (nonatomic, readonly) NSString *videoURL;

/**
 * URL for 2D image, can be used as a background image in UI etc. May be nil value.
 */
@property (nonatomic, readonly) NSString *bannerURL;

/**
 * URL to a small image, can be used as a thumbnail image for video.
 */
@property (nonatomic, readonly) NSString *thumbURL;

/**
 * URL to another small image, can be used as a thumbnail image for video.
 */
@property (nonatomic, readonly) NSString *smallThumbURL;

/**
 * Property that tells whether the video is downloadable.
 */
@property (nonatomic, readonly) BOOL download;

/**
 * Video owner user info.
 */
@property (nonatomic, readonly) LSUser *user;

/**
 * Download state of a video defined in VideoItem.
 */
@property (nonatomic, readonly) LSVideoDownloadState downloadState;


@end
