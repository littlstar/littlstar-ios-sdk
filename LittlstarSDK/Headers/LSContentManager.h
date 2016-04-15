//
//  LSContentManager.h
//  LittlstarSDK
//
//  Created by Littlstar on 11/05/2015
//  Copyright (c) 2015 Little Star Media, Inc. (Littlstar). All rights reserved.
//

#import <Foundation/Foundation.h>
#import <LittlstarSDK/LSVideoItem.h>
#import <LittlstarSDK/LSPhotoItem.h>
#import <LittlstarSDK/LSUser.h>
#import <LittlstarSDK/LSCategory.h>
#import <LittlstarSDK/LSNotification.h>
#import <LittlstarSDK/LSChannel.h>
#import <LittlstarSDK/LSResultPage.h>

@protocol LSContentManagerDelegate;

/**
 *  Class LSContentManager, provides access to available Littlstar 360 video resources.
 */
@interface LSContentManager : NSObject

/**
 * LSContentManager Delegate
 *
 *  @see LSContentManagerDelegate
 */
@property (nonatomic, weak) id <LSContentManagerDelegate> delegate;

/**
 * Mandatory, url to license file, the name of the file needs to match the application bundle name in order to enable the SDK 360 video features, e.g. com.littlstar.example-app.key.lic
 *
 * NOTE: Also the content of the license file needs to match the platform ("iOS"), application version (version=Littlstar) and the bundle ID of the application (e.g. com.littlstar.example-app).
 */
@property (nonatomic) NSURL* licenseFileURL;

/**
 * Mandatory, basic URL that will serve the 360 videos, default: https://littlstar.com/api/v1/
 *
 * NOTE: if enableUnknownSourceUrl field exists in lisence.key.lic file and equals to false, basic service URL needs to match
 * URL given in license file in enableSourceUrlExplicit field.
 */
@property (nonatomic) NSString *serviceBaseURL;

/**
 * User logged in to Littlstar service, if nil not logged in. Can be checked for login status.
 *
 * @see LSUser.h
 */
@property (nonatomic, readonly) LSUser *loggedUser;

- (void)addDelegate: (id<LSContentManagerDelegate>) delegate;
- (void)removeDelegate: (id<LSContentManagerDelegate>) delegate;

/**
 * Function to asynchronously register to the Littlstar service. Mandatory in order to log in. As a result the -(void)lsContentManagerDidFinishRegisterUser is called and the information of registered user wrapped in LSUser object is passed as a parameter. In order to give stars or downvotes to a video the service user needs to be registered and logged in.
 *
 * NOTE: If returned LSUser is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param userName User name as a string
 * @param email User email as a string
 * @param password Password as a string
 * @param confirmation Password confirmation as a string
 */
-(void)registerUser:(NSString*)userName email:(NSString*)email password:(NSString*)password confirmation:(NSString*)confirmation;

/**
 * Function to asynchronously log in to the Littlstar service. As a result the -(void)lsContentManagerDidFinishLoginUser is called and the information of registered user wrapped in LSUser object is passed as a parameter. Successfully logged user is stored in loggedUser (LSUser object) property (see above). In order to give stars or downvotes to a video the service user needs to be registered and logged in.
 *
 * NOTE: The Littlstar service user needs to be registered before logging! Also if returned LSUser is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param userName User name as a string
 * @param password Password as a string
 */
-(void)loginUser:(NSString*)userName password:(NSString*)password;

/**
 * Function to asynchronously log in to the Littlstar service with facebook profile token. As a result the -(void)lsContentManagerDidFinishLoginFBUser is called and the information of registered user wrapped in LSUser object is passed as a parameter. Successfully logged user is stored in loggedUser (LSUser object) property (see above). In order to give stars or downvotes to a video the service user needs to be registered and logged in.
 *
 * NOTE: The Littlstar service user needs to be registered via Facebook SDK before logging! Also if returned LSUser is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param fbProfileToken Facebook profile token received from Facebook SDK
 */
-(void)loginFBUser:(NSString*)fbProfileToken;

/**
 * Function to logout from Littlstar service. Sets the loggedUser property to nil.
 */
-(void)logout;

/**
 * Function to fetch a list of available video items (LSVideoItems) available in Littlstar service.
 * The result array of VideoItems is delivered through -(void)lsContentManagerDidGetVideoItems
 *
 * NOTE: The Littlstar API document ( http://developer.littlstar.com/docs/#all-videos ) states that "This endpoint currently returns a select subset of sponsored and featured videos." So the result array of video items is vastly smaller than the overall count of videos in service.
 *
 * @param page The page index to the item page to be loaded from service.
 *
 * @see LSVideoItem.h
 */
-(void)getVideoItems:(NSUInteger)page;

/**
 * Function to fetch a complete list of photo items (LSPhotoItems) available in Littlstar service.
 * The result array of VideoItems is delivered through -(void)lsContentManagerDidGetPhotoItems
 *
 * @param page The page index to the item page to be loaded from service.
 *
 * @see LSPhotoItem.h
 */
-(void)getPhotoItems:(NSUInteger)page;

/**
 * Request asynchronously the Littlstar user (wrapped in LSUser object defined in LSUser.h) for the specific user ID (NSString).
 * Result array in delegate function -(void)lsContentManagerDidGetUser. Can be used for fetching information about the both video provider and the service user/consumer.
 *
 * NOTE: If returned LSUser is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param lsUserId The ID of Littlstar user in string.
 */
-(void)getUser:(NSString*)lsUserId;

/**
 * Function to asynchronously load videos for a specified Littlstar user, request sent to service defined in serviceBaseURL property.
 * The result videos are delivered in array in -(void)lsContentManagerDidGetVideoItemsByUser delegate function.
 * Video array then contains video items (1...n) (LSVideoItem objects) defined in LSVideoItem.h.
 *
 * NOTE: If returned array of LSVideoItems is nil or video count is 0, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param lsUser LSUser (defined in LSUser.h) whose videos are going to be requested.
 * @param page The page index to the item page to be loaded from service.
 *
 * @see LSUser.h
 */
-(void)getVideoItemsByUser:(LSUser*)lsUser page:(NSUInteger)page;

/**
 * Function to asynchronously load photos for a specified Littlstar user, request sent to service defined in serviceBaseURL property.
 * The result videos are delivered in array in -(void)lsContentManagerDidGetPhotoItemsByUser delegate function.
 * Video array then contains video items (1...n) (LSPhotoItem objects) defined in LSPhotoItem.h.
 *
 * NOTE: If returned array of LSPhotoItems is nil or video count is 0, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param lsUser LSUser (defined in LSUser.h) whose videos are going to be requested.
 * @param page The page index to the item page to be loaded from service.
 *
 * @see LSUser.h
 */
-(void)getPhotoItemsByUser:(LSUser*)lsUser page:(NSUInteger)page;

/**
 * Function to asynchronously request a single video item (LSVideoItem object) for the specified unique video ID.
 * The result video is delivered through -(void)lsContentManagerDidGetVideoById delegate function.
 *
 * NOTE: If returned LSVideoItem is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param videoId A unique video ID as NSUInteger
 */
-(void)getVideoItemByVideoId:(NSUInteger)videoId;

/**
 * Function to asynchronously request a single photo item (LSPhotoItem object) for the specified unique video ID.
 * The result photo is delivered through -(void)lsContentManagerDidGetPhotoById delegate function.
 *
 * NOTE: If returned LSPhotoItem is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param photoId A unique video ID as NSUInteger
 */
-(void)getPhotoItemByPhotoId:(NSUInteger)photoId;

/**
 * Function to asynchronously request comments of a single video by a specified unique video ID.
 * The result comments are delivered through -(void)lsContentManagerDidGetVideoCommentsById delegate function.
 *
 * NOTE: If returned LSResultPage is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param videoId A unique video ID as NSUInteger
 * @param page The page index to the result page to be loaded from service.
 */
-(void)getVideoCommentsByVideoId:(NSUInteger)videoId page:(NSUInteger)page;

/**
 * Function to asynchronously request comments of a single photo by a specified unique photo ID.
 * The result comments are delivered through -(void)lsContentManagerDidGetPhotoCommentsById delegate function.
 *
 * NOTE: If returned LSResultPage is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param photoId A unique photo ID as NSUInteger
 * @param page The page index to the result page to be loaded from service.
 */
-(void)getPhotoCommentsByPhotoId:(NSUInteger)photoId page:(NSUInteger)page;

/**
 * Function to comment the specific video.
 * Updated comments will be delivered through -(void)lsContentManagerDidGetVideoCommentsById delegate call.
 *
 * NOTE: If returned LSVideoItem is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param videoItem The video item of the selected video, defined in LSVideoItem.h.
 * @param comment The comment text.
 *
 * @see LSVideoItem.h
 */
-(void)commentVideoItem:(LSVideoItem*)videoItem comment:(NSString*)comment;

/**
 * Function to comment the specific video.
 * Updated comments will be delivered through -(void)lsContentManagerDidGetPhotoCommentsById delegate call.
 *
 * NOTE: If returned LSPhotoItem is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param photoItem The video item of the selected video, defined in LSPhotoItem.h.
 * @param comment The comment text.
 *
 * @see LSPhotoItem.h
 */
-(void)commentPhotoItem:(LSPhotoItem*)photoItem comment:(NSString*)comment;

/**
 * Function to asynchronously make a search query to video items (LSVideoItem objects) in Littlstar service. The search will go through all the fields in video items for finding a string match.
 * The result array of videos is delivered through -(void)lsContentManagerDidSearchVideosByString delegate function.
 *
 * NOTE: If returned array is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param string A string to be used for searching videos.
 * @param page The page index to the item page to be loaded from service.
 *
 */
-(void)searchVideosByString:(NSString*)string page:(NSUInteger)page;

/**
 * Function to asynchronously make a search query to photo items (LSPhotoItem objects) in Littlstar service. The search will go through all the fields in photo items for finding a string match.
 * The result array of photos is delivered through -(void)lsContentManagerDidSearchPhotosByString delegate function.
 *
 * NOTE: If returned array is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param string A string to be used for searching photos.
 * @param page The page index to the item page to be loaded from service.
 *
 */
-(void)searchPhotosByString:(NSString*)string page:(NSUInteger)page;

/**
 * Function to asynchronously make a search query to user items (LSUser objects) in Littlstar service. The search will go through all the fields in user items for finding a string match.
 * The result array of users is delivered through -(void)lsContentManagerDidSearchUsersByString delegate function.
 *
 * NOTE: If returned array is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param string A string to be used for searching users.
 * @param page The page index to the item page to be loaded from service.
 *
 */
-(void)searchUsersByString:(NSString*)string page:(NSUInteger)page;

/**
 * Function to asynchronously make a search query to channel items (LSChannel objects) in Littlstar service. The search will go through all the fields in channel items for finding a string match.
 * The result array of users is delivered through -(void)lsContentManagerDidSearchChannelsByString delegate function.
 *
 * NOTE: If returned array is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param string A string to be used for searching channels.
 * @param page The page index to the item page to be loaded from service.
 *
 */
-(void)searchChannelsByString:(NSString*)string page:(NSUInteger)page;

/**
 * Function to asynchronously make a search query to all items (videos, photos, users and channels) in Littlstar service. The search will go through all the fields in items for finding a string match.
 * The result array of users is delivered through -(void)lsContentManagerDidSearchAllByString delegate function.
 *
 * NOTE: If returned array is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param string A string to be used for searching all items.
 * @param page The page index to the item page to be loaded from service.
 *
 */
-(void)searchAllByString:(NSString*)string page:(NSUInteger)page;

/**
 * Function to refresh the video properties of a single LSVideoItem. The data can be used for updating UI,
 * e.g. with view, star and downvote counts, defined in LSVideoItem.h.
 * The result of the request, i.e. the updated LSVideoItem is returned through -(void)lsContentManagerDidRefreshVideoItem delegate function.
 *
 * NOTE: If returned LSVideoItem is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param videoItem of the video to be updated.
 *
 * @see LSVideoItem.h
 */
-(void)refreshVideoItem:(LSVideoItem*)videoItem;

/**
 * Function to refresh the photo properties of a single LSPhotoItem. The data can be used for updating UI,
 * e.g. with view, star and downvote counts, defined in LSPhotoItem.h.
 * The result of the request, i.e. the updated LSVideoItem is returned through -(void)lsContentManagerDidRefreshPhotoItem delegate function.
 *
 * NOTE: If returned LSPhotoItem is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param photoItem of the photo to be updated.
 *
 * @see LSPhotoItem.h
 */
-(void)refreshPhotoItem:(LSPhotoItem*)photoItem;

/**
 * Function to _both_ star or unstar the specific video, only inverts the current value.
 * Updated LSVideoItem will be delivered through -(void)lsContentManagerDidRefreshVideoItem delegate call.
 *
 * NOTE: If returned LSVideoItem is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param videoItem The video item of the selected video, defined in LSVideoItem.h.
 *
 * @see LSVideoItem.h
 */
-(void)starVideoItem:(LSVideoItem*)videoItem;

/**
 * Function to _both_ downvote or undownvote the specific video, only inverts the current value.
 * Updated LSVideoItem will be delivered through -(void)lsContentManagerDidRefreshVideoItem delegate call.
 *
 * NOTE: If returned LSVideoItem is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param videoItem The video item of the selected video, defined in LSVideoItem.h.
 *
 * @see LSVideoItem.h
 */
-(void)downvoteVideoItem:(LSVideoItem*)videoItem;

/**
 * Function to _both_ star or unstar the specific photo, only inverts the current value.
 * Updated LSPhotoItem will be delivered through -(void)lsContentManagerDidRefreshPhotoItem delegate call.
 *
 * NOTE: If returned LSPhotoItem is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param photoItem The photo item of the selected video, defined in LSPhotoItem.h.
 *
 * @see LSPhotoItem.h
 */
-(void)starPhotoItem:(LSPhotoItem*)photoItem;

/**
 * Function to _both_ downvote or undownvote the specific photo, only inverts the current value.
 * Updated LSPhotoItem will be delivered through -(void)lsContentManagerDidRefreshPhotoItem delegate call.
 *
 * NOTE: If returned LSPhotoItem is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param photoItem The video item of the selected video, defined in LSPhotoItem.h.
 *
 * @see LSPhotoItem.h
 */
-(void)downvotePhotoItem:(LSPhotoItem*)photoItem;

/**
 * Function to download the selected video to local disk _if_ the video is downloadable. 
 * The video provider can disable the video downloading and has set a specific flag for it.
 * In that case the function raises a delegate error message in -(void)lsContentManagerDidFailDownloading call
 * if not able to download (the state can be checked also from LSVideoItem.download property)
 * Successfull downloading is notified by -(void)lsContentManagerDidFinishDownloading
 *
 * NOTE: Downloaded videos are stored locally and are used automatically if available in local disk.
 *
 * @param videoItem The video item of the selected video, defined in LSVideoItem.h.
 *
 * @see LSVideoItem.h
 */
-(void)downloadVideoByVideoItem:(LSVideoItem*)videoItem;

/**
 * Function to cancel ongoing download of the selected video.
 * Cancelled LSVideoItem will be delivered through -(void)lsContentManagerDidCancelDownloading call.
 *
 * @param videoItem The video item of the selected video, defined in LSVideoItem.h.
 *
 * @see LSVideoItem.h
 */
-(void)cancelVideoDownloadByVideoItem:(LSVideoItem*)videoItem;

/**
 * Function to cancel all ongoing downloads
 * Cancelled LSVideoItems will be delivered through -(void)lsContentManagerDidCancelDownloading calls.
 */
-(void)cancelAllVideoDownloads;

/**
 * Function to delete a locally cached single video file
 *
 * @param videoItem The video item of the selected video, defined in LSVideoItem.h.
 *
 * @see LSVideoItem.h
 */
-(void)deleteDownloadedVideoByVideoItem:(LSVideoItem*)videoItem;

/**
 * Function to delete all locally cached video files and possible temporary files.
 *
 * @param videoItems Array of the video items to be deleted.
 *
 * @see LSVideoItem.h
 */
-(void)deleteDownloadedVideosByVideoItems:(NSArray*)videoItems;

/**
 * Function to fetch the list of video categories.
 * Delegate call -(void)lsContentManagerDidGetCategories returns an array of video categories (wrapped in LSCategory objects).
 *
 * @param page The page index to the item page to be loaded from service.
 *
 * @see LSCategory.h
 */
-(void)getCategories:(NSUInteger)page;

/**
 * Function to get channel by category ID. User needs to be logged in.
 * Delegate call -(void)lsContentManagerDidGetGategories returns a channel in array (LSCategory).
 *
 * @param categoryId The ID of the category searched.
 *
 * @see LSCategory.h
 */
-(void)getCategoryById:(NSUInteger)categoryId;

/**
 * Function to fetch videos per category.
 * Delegate call -(void)lsContentManagerDidGetVideosByCategory returns an array of videos (wrapped in LSVideoItem objects).
 *
 * @param category  The category of which videos are going to be requested.
 * @param page The page index to the item page to be loaded from service.
 *
 * @see LSVideoItem.h
 * @see LSCategory.h
 */
-(void)getVideosByCategory:(LSCategory*)category page:(NSUInteger)page;

/**
 * Function to fetch videos per category.
 * Delegate call -(void)lsContentManagerDidGetPhotosByCategory returns an array of videos (wrapped in LSPhotoItem objects).
 *
 * @param category  The category of which photos are going to be requested.
 * @param page The page index to the item page to be loaded from service.
 *
 * @see LSPhotoItem.h
 * @see LSCategory.h
 */
-(void)getPhotosByCategory:(LSCategory*)category page:(NSUInteger)page;

/**
 * Function to fetch user feed videos per user.
 * Delegate call -(void)lsContentManagerDidGetFeedByUser returns an array of videos (wrapped in LSVideoItem objects).
 *
 * @param lsUser LSUser (defined in LSUser.h) whose videos are going to be requested.
 * @param page The page index to the item page to be loaded from service.
 *
 * @see LSUser.h
 * @see LSVideoItem.h
 */
-(void)getFeedByUser:(LSUser*)lsUser page:(NSUInteger)page;

/**
 * Function to fetch channels per user.
 * Delegate call -(void)lsContentManagerDidGetChannelsByUser returns an array of channels (wrapped in LSChannel objects).
 *
 * @param lsUser LSUser (defined in LSUser.h) whose videos are going to be requested.
 * @param page The page index to the item page to be loaded from service.
 *
 * @see LSUser.h
 * @see LSChannel.h
 */
-(void)getChannelsByUser:(LSUser*)lsUser page:(NSUInteger)page;

/**
 * Function to fetch followers (LSUsers) for the lsUser.
 * Delegate call -(void)lsContentManagerDidGetFollowersByUser returns an array of followers (wrapped in LSUser objects).
 *
 * @param lsUser LSUser (defined in LSUser.h) whose followers are about to be requested.
 * @param page The page index to the item page to be loaded from service.
 *
 * @see LSUser.h
 */
-(void)getFollowersByUser:(LSUser*)lsUser page:(NSUInteger)page;

/**
 * Function to fetch the users (LSUsers) that the lsUser is following.
 * Delegate call -(void)lsContentManagerDidGetFollowingsByUser returns an array of users (wrapped in LSUser objects).
 *
 * @param lsUser LSUser (defined in LSUser.h) whose list of interested users is about to be requested.
 * @param page The page index to the item page to be loaded from service.
 *
 * @see LSUser.h
 */
-(void)getFollowingByUser:(LSUser*)lsUser page:(NSUInteger)page;

/**
 * Function to follow/unfollow a specific user (lsUser).
 * Delegate call -(void)lsContentManagerDidFollowUser returns an updated user (wrapped in LSUser object).
 *
 * @param lsUser LSUser (defined in LSUser.h) who is requested to be followed/unfollowed.
 *
 * @see LSUser.h
 */
-(void)followUser:(LSUser*)lsUser;

/**
 * Function to get user notifications. User needs to be logged in.
 * Delegate call -(void)lsContentManagerDidGetNotifications returns an array of notifications (LSNotification).
 *
 * @param page The page index to the item page to be loaded from service.
 *
 * @see LSNotification.h
 */
-(void)getNotifications:(NSUInteger)page;

/**
 * Function to get channels. User needs to be logged in.
 * Delegate call -(void)lsContentManagerDidGetChannels returns an array of channels (LSChannel).
 *
 * @param page The page index to the item page to be loaded from service.
 *
 * @see LSChannel.h
 */
-(void)getChannels:(NSUInteger)page;

/**
 * Function to get channel by channel ID. User needs to be logged in.
 * Delegate call -(void)lsContentManagerDidGetChannels returns a channel in array (LSChannel).
 *
 * @param channelId The ID of the channel searched.
 *
 * @see LSChannel.h
 */
-(void)getChannelById:(NSUInteger)channelId;

/**
 * Function to get videos by channel ID. User needs to be logged in.
 * Delegate call -(void)lsContentManagerDidGetVideosByChannel returns an array of videos (LSVideo).
 *
 * @param channel The channel of the videos.
 * @param page The page index to the item page to be loaded from service.
 *
 * @see LSChannel.h
 * @see LSVideoItem.h
 */
-(void)getVideosByChannel:(LSChannel*)channel page:(NSUInteger)page;

/**
 * Function to get videos by channel ID. User needs to be logged in.
 * Delegate call -(void)lsContentManagerDidGetPhotosByChannel returns an array of photos (LSPhoto).
 *
 * @param channel The channel of the photos.
 * @param page The page index to the item page to be loaded from service.
 *
 *
 * @see LSChannel.h
 * @see LSPhotoItem.h
 */
-(void)getPhotosByChannel:(LSChannel*)channel page:(NSUInteger)page;

/**
 * Function to get discovery content.
 * Delegate call -(void)lsContentManagerDidGetDiscovery returns an dictionary of discovery content, i.e. popular, featured, sponsored videos and available cateogries, the names are the keys in dictionary.
 *
 * @see LSVideoItem.h
 * @see LSCategory.h
 */
-(void)getDiscovery;

@end


/**
 *  LSContentManagerDelegate protocol defines the mandatory methods implemented by
 *  delegates of the LSContentManager class.
 */
@protocol LSContentManagerDelegate
@optional

/**
 *  Delegate function to notify the caller that login was successfull. If there is an error, the user parameter is nil and error message shows the reason.
 *
 *  @param manager Content manager used to login
 *  @param user    User logged in
 *  @param error   Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSUser.h
 */
-(void)lsContentManagerDidFinishLoginUser:(LSContentManager*)manager user:(LSUser*)user error:(NSString*)error;

/**
 *  Delegate function to notify the caller that login with facebook token was successfull. If there is an error, the user parameter is nil and error message shows the reason.
 *
 *  @param manager Content manager used to login
 *  @param user    User logged in
 *  @param error   Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSUser.h
 */
-(void)lsContentManagerDidFinishLoginFBUser:(LSContentManager*)manager user:(LSUser*)user error:(NSString*)error;

/**
 *  Delegate function to notify the caller that registration was successfull. If there is an error, the user parameter is nil and error message shows the reason.
 *
 *  NOTE: The user needs to log in after regitering in order to use e.g. starForVideo or downvoteForVideo methods.
 *
 *  @param manager Content manager used to register
 *  @param user    Registered user
 *  @param error   Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSUser.h
 */
-(void)lsContentManagerDidFinishRegisterUser:(LSContentManager*)manager user:(LSUser*)user error:(NSString*)error;

/**
 *  Delegate function to notify that Littlstar user was found. If there is an error, the user parameter is nil and error message shows the reason.
 *
 *  @param manager          Content manager used to fetch the Littlstar user
 *  @param user             The full info of requested Littlstar user, wrapped in LSUser object
 *  @param error            Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSUser.h
 */
-(void)lsContentManagerDidGetUser:(LSContentManager*)manager user:(LSUser*)user error:(NSString*)error;

/**
 *  Delegate function indicating that the requested video item was found. If there is an error, the videoItem parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to update the requested item
 *  @param videoItem    Requested video item
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSVideoItem.h
 */
-(void)lsContentManagerDidGetVideoById:(LSContentManager*)manager videoItem:(LSVideoItem*)videoItem error:(NSString*)error;

/**
 *  Delegate function indicating that the requested photo item was found. If there is an error, the videoItem parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to update the requested item
 *  @param photoItem    Requested photo item
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSVideoItem.h
 */
-(void)lsContentManagerDidGetPhotoById:(LSContentManager*)manager photoItem:(LSPhotoItem*)photoItem error:(NSString*)error;

/**
 *  Delegate function indicating that the requested comments for video id was found. If there is an error, the resultPage parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to update the requested item
 *  @param resultPage   Results of a request, comment items stored in array
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSComment.h
 *  @see LSResultPage.h
 */
-(void)lsContentManagerDidGetVideoCommentsById:(LSContentManager*)manager resultPage:(LSResultPage*)resultPage error:(NSString*)error;

/**
 *  Delegate function indicating that the requested comments for photo id was found. If there is an error, the resultPage parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to update the requested item
 *  @param resultPage   Results of a request, comment items stored in array
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSComment.h
 *  @see LSResultPage.h
 */
-(void)lsContentManagerDidGetPhotoCommentsById:(LSContentManager*)manager resultPage:(LSResultPage*)resultPage error:(NSString*)error;

/**
 *  Delegate function called when the requested user's video items are collected. If there is an error, the resultPage parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to request video items
 *  @param resultPage   Results of a request, items stored in array
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSResultPage.h
 *  @see LSVideoItem.h
 */
-(void)lsContentManagerDidGetVideoItemsByUser:(LSContentManager*)manager resultPage:(LSResultPage*)resultPage error:(NSString*)error;

/**
 *  Delegate function called when the requested user's photo items are collected. If there is an error, the resultPage parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to request photo items
 *  @param resultPage   Results of a request, items stored in array
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSResultPage.h
 *  @see LSPhotoItem.h
 */
-(void)lsContentManagerDidGetPhotoItemsByUser:(LSContentManager*)manager resultPage:(LSResultPage*)resultPage error:(NSString*)error;

/**
 *  Delegate function called when the requested all available video items are collected. If there is an error, the resultPage parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to request video items
 *  @param resultPage   Results of a request, items stored in array
 *  @param error        Error message as string.
 *
 *  NOTE: The Littlstar API document (http://developer.littlstar.com/docs/#all-videos) states that "This endpoint currently returns a select subset of sponsored and featured videos." So the result array of video items is vastly smaller than the overall count of videos in service.
 *
 *  @see LSContentManager.h
 *  @see LSResultPage.h
 *  @see LSVideoItem.h
 */
-(void)lsContentManagerDidGetVideoItems:(LSContentManager*)manager resultPage:(LSResultPage*)resultPage error:(NSString*)error;

/**
 *  Delegate function called when the requested all available photo items are collected. If there is an error, the resultPage parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to request photo items
 *  @param resultPage   Results of a request, items stored in array
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSResultPage.h
 *  @see LSPhotoItem.h
 */
-(void)lsContentManagerDidGetPhotoItems:(LSContentManager*)manager resultPage:(LSResultPage*)resultPage error:(NSString*)error;

/**
 *  Delegate function called when the videos with matching string (in title, description, etc.) are found. If there is an error, the resultPage parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to request video items
 *  @param resultPage   Results of a request, items stored in array
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSResultPage.h
 *  @see LSVideoItem.h
 */
-(void)lsContentManagerDidSearchVideosByString:(LSContentManager*)manager resultPage:(LSResultPage*)resultPage error:(NSString*)error;

/**
 *  Delegate function called when the photos with matching string (in title, description, etc.) are found. If there is an error, the resultPage parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to request photo items
 *  @param resultPage   Results of a request, items stored in array
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSResultPage.h
 *  @see LSPhotoItem.h
 */
-(void)lsContentManagerDidSearchPhotosByString:(LSContentManager*)manager resultPage:(LSResultPage*)resultPage error:(NSString*)error;

/**
 *  Delegate function called when the users with matching string (in name, etc.) are found. If there is an error, the resultPage parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to request user items
 *  @param resultPage   Results of a request, items stored in array
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSResultPage.h
 *  @see LSUser.h
 */
-(void)lsContentManagerDidSearchUsersByString:(LSContentManager*)manager resultPage:(LSResultPage*)resultPage error:(NSString*)error;

/**
 *  Delegate function called when the channels with matching string (in name, etc.) are found. If there is an error, the resultPage parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to request channel items
 *  @param resultPage   Results of a request, items stored in array
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSResultPage.h
 *  @see LSChannel.h
 */
-(void)lsContentManagerDidSearchChannelsByString:(LSContentManager*)manager resultPage:(LSResultPage*)resultPage error:(NSString*)error;

/**
 *  Delegate function called when the all items with matching string (in name, etc.) are found. If there is an error, the resultPage parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to request all items
 *  @param resultPage   Results of a request, items stored in array
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSResultPage.h
 *  @see LSVideoItem.h
 *  @see LSPhotoItem.h
 *  @see LSUser.h
 *  @see LSChannel.h
 */
-(void)lsContentManagerDidSearchAllByString:(LSContentManager*)manager resultPage:(LSResultPage*)resultPage error:(NSString*)error;

/**
 * Delegate function indicating that the requested video item was updated and UI can be updated as well. If there is an error, the videoItem parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used for refreshing the video item
 *  @param videoItem    Updated video item
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSVideoItem.h
 */
-(void)lsContentManagerDidRefreshVideoItem:(LSContentManager*)manager videoItem:(LSVideoItem*)videoItem error:(NSString*)error;

/**
 * Delegate function indicating that the requested photo item was updated and UI can be updated as well. If there is an error, the photoItem parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used for refreshing the photo item
 *  @param photoItem    Updated photo item
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSPhotoItem.h
 */
-(void)lsContentManagerDidRefreshPhotoItem:(LSContentManager*)manager photoItem:(LSPhotoItem*)photoItem error:(NSString*)error;

/**
 *  Delegate function called when all the categories are collected. If there is an error, the resultPage parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to request video items
 *  @param resultPage   Results of a request, items stored in array
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSResultPage.h
 *  @see LSCategory.h
 */
-(void)lsContentManagerDidGetCategories:(LSContentManager*)manager resultPage:(LSResultPage*)resultPage error:(NSString*)error;

/**
 *  Delegate function called when the requested category ghas received. If there is an error, the category parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to request video items
 *  @param category     A requested category
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSCategory.h
 */
-(void)lsContentManagerDidGetCategoryById:(LSContentManager*)manager category:(LSCategory*)category error:(NSString*)error;

/**
 *  Delegate function called when the requested video items for a selected category are collected. If there is an error, the resultPage parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to request video items
 *  @param resultPage   Results of a request, items stored in array
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSResultPage.h
 *  @see LSVideoItem.h
 */
-(void)lsContentManagerDidGetVideosByCategory:(LSContentManager*)manager resultPage:(LSResultPage*)resultPage error:(NSString*)error;

/**
 *  Delegate function called when the requested photo items for a selected category are collected. If there is an error, the resultPage parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to request photo items
 *  @param resultPage   Results of a request, items stored in array
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSResultPage.h
 *  @see LSPhotoItem.h
 */
-(void)lsContentManagerDidGetPhotosByCategory:(LSContentManager*)manager resultPage:(LSResultPage*)resultPage error:(NSString*)error;

/**
 *  Delegate function called when the requested video items for a selected user's feed are collected. If there is an error, the resultPage parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to request video items
 *  @param resultPage   Results of a request, items stored in array
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSResultPage.h
 *  @see LSVideoItem.h
 */
-(void)lsContentManagerDidGetFeedByUser:(LSContentManager*)manager resultPage:(LSResultPage*)resultPage error:(NSString*)error;

/**
 *  Delegate function called when the requested channels for a selected user are collected. If there is an error, the resultPage parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to request video items
 *  @param resultPage   Results of a request, items stored in array
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSResultPage.h
 *  @see LSChannel.h
 */
-(void)lsContentManagerDidGetChannelsByUser:(LSContentManager*)manager resultPage:(LSResultPage*)resultPage error:(NSString*)error;

/**
 *  Delegate function called when the requested list of followers is finalized. The list of users that follow the user (LSUser) is passed as a parameter. If there is an error, the resultPage parameter is nil and error message shows the reason.
 *
 *  @param manager          Content manager used to request video items
 *  @param resultPage       Results of a request, items stored in array
 *  @param error            Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSResultPage.h
 *  @see LSUser.h
 */
-(void)lsContentManagerDidGetFollowersByUser:(LSContentManager*)manager resultPage:(LSResultPage*)resultPage error:(NSString*)error;

/**
 *  Delegate function called when the requested list of followings is finalized. The list of followed users (by LSUser) is passed as a parameter. If there is an error, the resultPage parameter is nil and error message shows the reason.
 *
 *  @param manager          Content manager used to request video items
 *  @param resultPage       Results of a request, items stored in array
 *  @param error            Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSResultPage.h
 *  @see LSUser.h
 */
-(void)lsContentManagerDidGetFollowingsByUser:(LSContentManager*)manager resultPage:(LSResultPage*)resultPage error:(NSString*)error;

/**
 *  Delegate function called when the requested follow/unfollow finalizes. The updated user is passed as a parameter. If there is an error, the lsUser parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to request video items
 *  @param user       Updated user (lsUser) showing the follow status.
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSUser.h
 */
-(void)lsContentManagerDidFollowUser:(LSContentManager*)manager user:(LSUser*)user error:(NSString*)error;

/**
 *  Delegate function to tell the caller that video downloading has started.
 *
 *  @param downloader   Content manager used to download the video
 *  @param videoItem    LSVideoItem that started to download
 *  @param totalBytes   Video size in bytes
 *
 *  @see LSContentManager.h
 *  @see LSVideoItem.h
 */
-(void)lsContentManagerDidStartDownloading:(LSContentManager*)downloader videoItem:(LSVideoItem*)videoItem totalBytes:(long long)totalBytes;

/**
 *  Delegate function to notify caller if video dowloading fails.
 *
 *  @param downloader       Content manager used to download the video
 *  @param videoItem        LSVideoItem that failed to download
 *  @param failDescription  Failure description
 *
 *  @see LSContentManager.h
 *  @see LSVideoItem.h
 */
-(void)lsContentManagerDidFailDownloading:(LSContentManager*)downloader videoItem:(LSVideoItem*)videoItem failDescription:(NSString*)failDescription;

/**
 *  Delegate function to notify caller that video downloading finished.
 *
 *  @param downloader       Content manager used to download the video
 *  @param videoItem        LSVideoItem that finished the download
 *
 *  @see LSContentManager.h
 *  @see LSVideoItem.h
 */
-(void)lsContentManagerDidFinishDownloading:(LSContentManager*)downloader videoItem:(LSVideoItem*)videoItem;

/**
 *  Delegate function to notify caller about video downloading progress.
 *
 *  @param downloader      Content manager used to download the video
 *  @param videoItem       LSVideoItem that is downloading
 *  @param downloadedBytes Downloaded bytes
 *  @param totalBytes      Total size of the video in bytes
 *
 *  @see LSContentManager.h
 *  @see LSVideoItem.h
 */
-(void)lsContentManagerDidUpdateProgress:(LSContentManager*)downloader videoItem:(LSVideoItem*)videoItem downloadedBytes:(long long)downloadedBytes totalBytes:(long long)totalBytes;

/**
 *  Delegate function to tell the caller that video download was cancelled.
 *
 *  @param downloader   Content manager used to download the video
 *  @param videoItem    LSVideoItem of which download was cancelled
 *
 *  @see LSContentManager.h
 *  @see LSVideoItem.h
 */
-(void)lsContentManagerDidCancelDownloading:(LSContentManager*)downloader videoItem:(LSVideoItem*)videoItem;

/**
 *  Delegate function called when all the notifications are collected. If there is an error, the resultPage parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to request notifications
 *  @param resultPage   Results of a request, items stored in array
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSResultPage.h
 *  @see LSNotification.h
 */
-(void)lsContentManagerDidGetNotifications:(LSContentManager*)manager resultPage:(LSResultPage*)resultPage error:(NSString*)error;

/**
 *  Delegate function called when all the channels are collected. If there is an error, the resultPage parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to request video items
 *  @param resultPage   Results of a request, items stored in array
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSResultPage.h
 *  @see LSChannel.h
 */
-(void)lsContentManagerDidGetChannels:(LSContentManager*)manager resultPage:(LSResultPage*)resultPage error:(NSString*)error;

/**
 *  Delegate function called when the requested channel ghas received. If there is an error, the resultPage is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to request video items
 *  @param channel      A requested channel
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSChannel.h
 */
-(void)lsContentManagerDidGetChannelById:(LSContentManager*)manager channel:(LSChannel*)channel error:(NSString*)error;

/**
 *  Delegate function called when the requested video items for a selected channel are collected. If there is an error, the resultPage parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to request video items
 *  @param resultPage   Results of a request, items stored in array
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSResultPage.h
 *  @see LSVideoItem.h
 */
-(void)lsContentManagerDidGetVideosByChannel:(LSContentManager*)manager resultPage:(LSResultPage*)resultPage error:(NSString*)error;

/**
 *  Delegate function called when the requested photo items for a selected channel are collected. If there is an error, the resultPage parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to request photo items
 *  @param resultPage   Results of a request, items stored in array
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSResultPage.h
 *  @see LSPhotoItem.h
 */
-(void)lsContentManagerDidGetPhotosByChannel:(LSContentManager*)manager resultPage:(LSResultPage*)resultPage error:(NSString*)error;

/**
 *  Delegate function called for the requested discovery. If there is an error, the resultDict parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to request photo items
 *  @param resultDict   Results of a request, items stored in dictionary, keys: sponsored, featured, popular and cateogories
 *  @param error        Error message as string.
 *
 *  @see LSContentManager.h
 *  @see LSPhotoItem.h
 *  @see LSVideoItem.h
 *  @see LSCategory.h
 */
-(void)lsContentManagerDidGetDiscovery:(LSContentManager*)manager resultDict:(NSDictionary*)resultDict error:(NSString*)error;
@end
