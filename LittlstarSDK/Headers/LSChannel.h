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
@property (nonatomic, assign) NSUInteger channelId;

/**
 * Unique item ID.
 */
@property (nonatomic, strong) NSString *slug;

/**
 * Video title.
 */
@property (nonatomic, strong) NSString *title;

/**
 * Video count for a specific channel.
 */
@property (nonatomic, assign) NSUInteger videosCount;

/**
 * Photo count given for a specific channel.
 */
@property (nonatomic, assign) NSUInteger photosCount;

/**
 * Sponsored channel.
 */
@property (nonatomic, assign) BOOL sponsored;

/**
 * Featured channel.
 */
@property (nonatomic, assign) BOOL featured;

/**
 * Creation date of item
 */
@property (nonatomic, strong) NSString *creationDate;

/**
 * URL for 360 photo, can be used as a background image in UI etc.
 */
@property (nonatomic, strong) NSString *thumbURL;

/**
 * URL to another small image, can be used as a thumbnail image for 360 photo.
 */
@property (nonatomic, strong) NSString *bannerURL;

/**
 * Channel owner user info.
 */
@property (nonatomic, strong) LSUser *user;

@end
