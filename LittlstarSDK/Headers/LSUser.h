//
//  LSUser.h
//  LittlstarSDK
//
//  Created by Petri Määttä on 20/04/15.
//  Copyright (c) 2015 Finwe Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Class LSUser, describes details of the Littlstar user.
 */
@interface LSUser : NSObject

/**
 * User ID which is used for fetching the video listing for the specific purpose.
 */
@property (nonatomic, readonly) NSString *lsUserName;

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

@end
