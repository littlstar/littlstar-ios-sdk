//
//  LSPhotoItem.h
//  LittlstarSDK
//
//  Created by Littlstar on 11/05/2015
//  Copyright (c) 2015 Little Star Media, Inc. (Littlstar). All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <LittlstarSDK/LSUser.h>

/**
 *  Class LSPhotoItem, describes details of the photo, fetched from Littlstar service.
 */
@interface LSPhotoItem : NSObject

// Photo item properties

/**
 * Unique item ID within photos.
 */
@property (nonatomic, readonly) NSUInteger photoId;

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
 * URL for 360 photo, can be used as a background image in UI etc.
 */
@property (nonatomic, readonly) NSString *thumbURL;

/**
 * URL to another small image, can be used as a thumbnail image for 360 photo.
 */
@property (nonatomic, readonly) NSString *smallThumbURL;

/**
 * Photo owner user info.
 */
@property (nonatomic, readonly) LSUser *user;

@end
