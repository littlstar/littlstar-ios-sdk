//
//  LSResultPage.h
//  LittlstarSDK
//
//  Created by Littlstar on 11/05/2015
//  Copyright (c) 2015 Little Star Media, Inc. (Littlstar). All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Class LSResultPage, describes details of the container that is used for delivering the Littlstar service items.
 */
@interface LSResultPage : NSObject

/**
 * Result array of requested items, paged.
 */
@property (nonatomic, readonly) NSArray *itemArray;

/**
 * The current page of the results.
 */
@property (nonatomic, readonly) NSUInteger currentPage;

/**
 * The next page of the results, if available, value is 0 if no more pages.
 */
@property (nonatomic, readonly) NSUInteger nextPage;

/**
 * The total page count of the results.
 */
@property (nonatomic, readonly) NSUInteger pageCount;

@end
