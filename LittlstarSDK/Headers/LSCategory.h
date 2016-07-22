//
//  LSCategory.h
//  LittlstarSDK
//
//  Created by Littlstar on 11/05/2015
//  Copyright (c) 2015 Little Star Media, Inc. (Littlstar). All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Class LSCategory, describes details of the Littlstar category.
 */
@interface LSCategory : NSObject

/**
 * Unique category ID within categories.
 */
@property (nonatomic, assign) NSUInteger categoryId;

/**
 * Unique item ID in LS service.
 */
@property (nonatomic, strong) NSString *slug;

/**
 * Category display name.
 */
@property (nonatomic, strong) NSString *categoryDisplayName;

/**
 * Video count per category.
 */
@property (nonatomic, assign) NSUInteger categoryVideoCount;

/**
 * Photo count per category.
 */
@property (nonatomic, assign) NSUInteger categoryPhotoCount;

/**
 * Thumb image per category.
 */
@property (nonatomic, strong) NSString *thumbURL;

@end
