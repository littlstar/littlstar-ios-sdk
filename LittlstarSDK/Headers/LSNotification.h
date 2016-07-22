//
//  LSNotification.h
//  LittlstarSDK
//
//  Created by Littlstar on 29/05/15.
//  Copyright (c) 2015 Little Star Media, Inc. (Littlstar). All rights reserved.
//

#import <Foundation/Foundation.h>
#import <LittlstarSDK/LSUser.h>

/**
 *  Class LSNotification, describes details of the Littlstar notification.
 */
@interface LSNotification : NSObject

/**
 * Unique item ID.
 */
@property (nonatomic, assign) NSUInteger notificationId;

/**
 * Notification action.
 */
@property (nonatomic, strong) NSString *action;

/**
 * Creation date of item
 */
@property (nonatomic, strong) NSString *creationDate;

/**
 * Update date of item
 */
@property (nonatomic, strong) NSString *updateDate;

/**
 * User that trigged the action.
 */
@property (nonatomic, strong) LSUser *user;

/**
 * Notification string.
 */
@property (nonatomic, strong) NSString *notification;

@property (nonatomic, assign) id recipient;
@end
