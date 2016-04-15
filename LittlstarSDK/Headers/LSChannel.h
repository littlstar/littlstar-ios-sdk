//
//  LSChannel.h
//  LittlstarSDK
//
//  Created by Littlstar on 11/05/2015
//  Copyright (c) 2015 Little Star Media, Inc. (Littlstar). All rights reserved.
//

#import <Foundation/Foundation.h>
#import <LittlstarSDK/LSUser.h>

/**
 *  Class LSChannel, describes details of the Littlstar channel.
 */
@interface LSChannel : NSObject

/**
 * Unique item ID.
 */
@property (nonatomic, readonly) NSUInteger channelId;

/**
 * Unique item ID.
 */
@property (nonatomic, readonly) NSString *slug;

/**
 * Video title.
 */
@property (nonatomic, readonly) NSString *title;

/**
 * Video count for a specific channel.
 */
@property (nonatomic, readonly) NSUInteger videosCount;

/**
 * Photo count given for a specific channel.
 */
@property (nonatomic, readonly) NSUInteger photosCount;

/**
 * Sponsored channel.
 */
@property (nonatomic, readonly) BOOL sponsored;

/**
 * Featured channel.
 */
@property (nonatomic, readonly) BOOL featured;

/**
 * Creation date of item
 */
@property (nonatomic, readonly) NSString *creationDate;

/**
 * URL for 360 photo, can be used as a background image in UI etc.
 */
@property (nonatomic, readonly) NSString *thumbURL;

/**
 * URL to another small image, can be used as a thumbnail image for 360 photo.
 */
@property (nonatomic, readonly) NSString *bannerURL;

/**
 * Channel owner user info.
 */
@property (nonatomic, readonly) LSUser *user;

@end
