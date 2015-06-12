//
//  LSNotification.h
//  FinweComponents
//
//  Created by Finwe Ltd on 29/05/15.
//  Copyright (c) 2015 Finwe Ltd. All rights reserved.
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
@property (nonatomic, readonly) NSUInteger notificationId;

/**
 * Notification action.
 */
@property (nonatomic, readonly) NSString *action;

/**
 * Creation date of item
 */
@property (nonatomic, readonly) NSString *creationDate;

/**
 * Update date of item
 */
@property (nonatomic, readonly) NSString *updateDate;

/**
 * User that trigged the action.
 */
@property (nonatomic, readonly) LSUser *user;

/**
 * Notification string.
 */
@property (nonatomic, readonly) NSString *notification;

@property (nonatomic, readonly) id recipient;
@end
