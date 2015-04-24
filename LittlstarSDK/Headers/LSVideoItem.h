//
//  LSVideoItem.h
//  LittlstarSDK
//
//  Created by Petri Määttä on 29/12/14.
//  Copyright (c) 2014 Finwe Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>


/**
 *  Class LSVideoItem, describes details of the video, fetched from Littlstar video service.
 */
@interface LSVideoItem : NSObject

// Video item properties

/**
 * Unique video ID.
 */
@property (nonatomic, readonly) NSUInteger videoId;

/**
 * Video title.
 */
@property (nonatomic, readonly) NSString *title;

/**
 * Short video description.
 */
@property (nonatomic, readonly) NSString *desc;

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

@end
