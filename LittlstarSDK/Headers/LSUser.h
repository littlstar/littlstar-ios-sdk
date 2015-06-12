//
//  LSUser.h
//  LittlstarSDK
//
//  Created by Littlstar on 11/05/2015
//  Copyright (c) 2015 Little Star Media, Inc. (Littlstar). All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Class LSUser, describes details of the Littlstar user.
 */
@interface LSUser : NSObject

/**
 * Unique item ID in LS service.
 */
@property (nonatomic, readonly) NSString *slug;

/**
 * Title for showing the full video owner name on UI.
 */
@property (nonatomic, readonly) NSString *lsUserDisplayName;

/**
 * Littlstar user biography if added to service, may be nil if not defined to service, can be nil.
 */
@property (nonatomic, readonly) NSString *lsUserBio;

/**
 * Littlstar user avatar icon URL, default icon is Littlstar specified if not user set.
 */
@property (nonatomic, readonly) NSString *lsUserIconURL;

/**
 * User first name, may be nil.
 */
@property (nonatomic, readonly) NSString *firstName;

/**
 * User last name, may be nil.
 */
@property (nonatomic, readonly) NSString *lastName;

/**
 *  Number of videos uploaded by the user.
 */
@property (nonatomic, readonly) NSUInteger videosCount;

/**
 *  Number of photos uploaded by the user.
 */
@property (nonatomic, readonly) NSUInteger photosCount;

/**
 * Property indicating if the user is being followed, valid only when logged in.
 */
@property (nonatomic, readonly) BOOL following;

/**
 * Creation, i.e. registration date of the user.
 */
@property (nonatomic, readonly) NSString *creationDate;

/**
 *  Number of other users following the user.
 */
@property (nonatomic, readonly) NSUInteger followersCount;

/**
 *  Number of other users that the user is following.
 */
@property (nonatomic, readonly) NSUInteger followingCount;


@end
