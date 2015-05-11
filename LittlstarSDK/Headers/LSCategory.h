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
 * Unique category ID.
 */
@property (nonatomic, readonly) NSUInteger categoryId;

/**
 * Category name.
 */
@property (nonatomic, readonly) NSString *categoryName;

/**
 * Category display name.
 */
@property (nonatomic, readonly) NSString *categoryDisplayName;

/**
 * Video count per category.
 */
@property (nonatomic, readonly) NSUInteger categoryVideoCount;

@end
