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
@property (nonatomic, readwrite, assign) NSUInteger photoId;

/**
 * Unique item ID in LS service.
 */
@property (nonatomic, readwrite, strong) NSString *slug;

/**
 * Video title.
 */
@property (nonatomic, readwrite, strong) NSString *title;

/**
 * Short video description.
 */
@property (nonatomic, readwrite, strong) NSString *desc;

/**
 * View count for a specific video.
 */
@property (nonatomic, readwrite, assign) NSUInteger views;

/**
 * Star count given for a specific video.
 */
@property (nonatomic, readwrite, assign) NSUInteger stars;

/**
 * Downvote count for a specific video.
 */
@property (nonatomic, readwrite, assign) NSUInteger downVotes;

/**
 * User star value, valid only when logged in.
 */
@property (nonatomic, readwrite, assign) BOOL stared;

/**
 * User downvote value, valid only when logged in.
 */
@property (nonatomic, readwrite) BOOL downvoted;

/**
 * Creation date of item
 */
@property (nonatomic, readwrite, strong) NSString *creationDate;

/**
 * URL for 360 photo, can be used as a background image in UI etc.
 */
@property (nonatomic, readwrite, strong) NSString *thumbURL;

/**
 * URL to another small image, can be used as a thumbnail image for 360 photo.
 */
@property (nonatomic, readwrite, strong) NSString *smallThumbURL;

/**
 * Local file URL. LSPlayer uses this if not null and local file exists.
 */
@property (nonatomic, readwrite) NSURL *localURL;

/**
 * Photo owner user info.
 */
@property (nonatomic, readwrite, strong) LSUser *user;

/**
 * Property that tells whether the photo is 3d and mode side by side.
 */
@property (nonatomic, readwrite) BOOL sbs3d;

/**
 * Property that tells whether the photo is 3d and mode over and under.
 */
@property (nonatomic, readwrite) BOOL ou3d;

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
 *  Default value 0(centered).
 */
@property (nonatomic) CGFloat yawAngle;

/**
 * Sponsored photo.
 */
@property (nonatomic, assign) BOOL sponsored;

/**
 * Featured photo.
 */
@property (nonatomic, assign) BOOL featured;

@property (nonatomic, strong) NSString *largeURL;
@property (nonatomic, strong) NSString *originalURL;

@end
