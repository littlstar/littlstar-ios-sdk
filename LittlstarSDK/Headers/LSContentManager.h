//
//  LSContentManager.h
//  LittlstarSDK
//
//  Created by Hannu Limma on 13.04.2015.
//  Copyright (c) 2015 Finwe Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <LittlstarSDK/LSVideoItem.h>
#import <LittlstarSDK/LSUser.h>

@protocol LSContentManagerDelegate;

/**
 *  Class LSContentManager, provides access to available Littlstar 360 video resources.
 */
@interface LSContentManager : NSObject

/**
 * LSContentManager Delegate
 */
@property (nonatomic, weak) id <LSContentManagerDelegate> delegate;

/**
 * Mandatory, url to license file, the name of the file needs to match the application bundle name in order to enable the SDK 360 video features, e.g. com.littlstar.example-app.key.lic
 *
 * NOTE: Also the content of the license file needs to match the platform ("iOS"), application version (version=LSOrion) and the bundle ID of the application (e.g. com.littlstar.example-app).
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
 */
@property (nonatomic, readonly) LSUser *loggedUser;

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
 * Function to logout from Littlstar service. Sets the loggedUser property to nil.
 */
-(void)logout;

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
 * The result videos are delivered in array in -(void)lsContentManagerDidGetUserVideoItems delegate function.
 * Video array then contains video items (1...n) (LSVideoItem objects) defined in LSVideoItem.h.
 *
 * NOTE: If returned array of LSVideoItems is nil or video count is 0, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param lsUser LSUser (defined in LSUser.h) whose videos are going to be requested.
 */
-(void)getUserVideoItems:(LSUser*)lsUser;

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
 * Function to refresh the video properties of a single LSVideoItem. The data can be used for updating UI,
 * e.g. with view, star and downvote counts, defined in LSVideoItem.h.
 * The result of the request, i.e. the updated LSVideoItem is returned through -(void)lsContentManagerDidRefreshVideoItem delegate function.
 *
 * NOTE: If returned LSVideoItem is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param videoItem of the video to be updated.
 */
-(void)refreshVideoItem:(LSVideoItem*)videoItem;

/**
 * Function to _both_ star or unstar the specific video, only inverts the current value.
 * Updated LSVideoItem will be delivered through -(void)lsContentManagerDidRefreshVideoItem delegate call.
 *
 * NOTE: If returned LSVideoItem is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param videoItem The video item of the selected video, defined in LSVideoItem.h.
 */
-(void)starVideoItem:(LSVideoItem*)videoItem;

/**
 * Function to _both_ downvote or undownvote the specific video, only inverts the current value.
 * Updated LSVideoItem will be delivered through -(void)lsContentManagerDidRefreshVideoItem delegate call.
 *
 * NOTE: If returned LSVideoItem is nil, an error message in other parameter (NSString) of delegate call shows the reason. Otherwise the error parameter is nil.
 *
 * @param videoItem The video item of the selected video, defined in LSVideoItem.h.
 */
-(void)downvoteVideoItem:(LSVideoItem*)videoItem;

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
 */
-(void)downloadVideoByVideoItem:(LSVideoItem*)videoItem;

/**
 * Function to cancel ongoing download of the selected video.
 * Cancelled LSVideoItem will be delivered through -(void)lsContentManagerDidCancelDownloading call.
 *
 * @param videoItem The video item of the selected video, defined in LSVideoItem.h.
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
 */
-(void)deleteDownloadedVideoByVideoItem:(LSVideoItem*)videoItem;

/**
 * Function to delete all locally cached video files and possible temporary files.
 */
-(void)deleteAllDownloadedVideos;

@end


/**
 *  LSContentManagerDelegate protocol defines the mandatory methods implemented by
 *  delegates of the LSContentManager class.
 */
@protocol LSContentManagerDelegate

/**
 *  Delegate function to notify the caller that login was successfull. If there is an error, the user parameter is nil and error message shows the reason.
 *
 *  @param manager Content manager used to login
 *  @param user    User logged in
 *  @param error   Error message as string.
*/
-(void)lsContentManagerDidFinishLoginUser:(LSContentManager*)manager user:(LSUser*)user error:(NSString*)error;

/**
 *  Delegate function to notify the caller that registration was successfull. If there is an error, the user parameter is nil and error message shows the reason.
 *
 *  NOTE: The user needs to log in after regitering in order to use e.g. starForVideo or downvoteForVideo methods.
 *
 *  @param manager Content manager used to register
 *  @param user    Registered user
 *  @param error   Error message as string.
 */
-(void)lsContentManagerDidFinishRegisterUser:(LSContentManager*)manager user:(LSUser*)user error:(NSString*)error;

/**
 *  Delegate function to notify that Littlstar user was found. If there is an error, the user parameter is nil and error message shows the reason.
 *
 *  @param manager          Content manager used to fetch the Littlstar user
 *  @param user             The full info of requested Littlstar user, wrapped in LSUser object
 *  @param error            Error message as string.
 */
-(void)lsContentManagerDidGetUser:(LSContentManager*)manager user:(LSUser*)user error:(NSString*)error;

/**
 *  Delegate function indicating that the requested video item was found. If there is an error, the videoItem parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to update the requested item
 *  @param videoItem    Requested video item
 *  @param error        Error message as string.
 */
-(void)lsContentManagerDidGetVideoById:(LSContentManager*)manager videoItem:(LSVideoItem*)videoItem error:(NSString*)error;

/**
 *  Delegate function called when the requested user's video items are collected. If there is an error, the videoItems array parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used to request video items
 *  @param videoItems   Array of requested video items
 *  @param error        Error message as string.
 */
-(void)lsContentManagerDidGetUserVideoItems:(LSContentManager*)manager videoItems:(NSArray*)videoItems error:(NSString*)error;

/**
 * Delegate function indicating that the requested video item was updated and UI can be updated as well. If there is an error, the videoItem parameter is nil and error message shows the reason.
 *
 *  @param manager      Content manager used for refreshing
 *  @param videoItem    Updated video item
 *  @param error        Error message as string.
 */
-(void)lsContentManagerDidRefreshVideoItem:(LSContentManager*)manager videoItem:(LSVideoItem*)videoItem error:(NSString*)error;

/**
 *  Delegate function to tell the caller that video downloading has started.
 *
 *  @param downloader   Content manager used to download the video
 *  @param videoItem    LSVideoItem that started to download
 *  @param totalBytes   Video size in bytes
 */
-(void)lsContentManagerDidStartDownloading:(LSContentManager*)downloader videoItem:(LSVideoItem*)videoItem totalBytes:(long long)totalBytes;

/**
 *  Delegate function to notify caller if video dowloading fails.
 *
 *  @param downloader       Content manager used to download the video
 *  @param videoItem        LSVideoItem that failed to download
 *  @param failDescription  Failure description
 */
-(void)lsContentManagerDidFailDownloading:(LSContentManager*)downloader videoItem:(LSVideoItem*)videoItem failDescription:(NSString*)failDescription;

/**
 *  Delegate function to notify caller that video downloading finished.
 *
 *  @param downloader       Content manager used to download the video
 *  @param videoItem        LSVideoItem that finished the download
 */
-(void)lsContentManagerDidFinishDownloading:(LSContentManager*)downloader videoItem:(LSVideoItem*)videoItem;

/**
 *  Delegate function to notify caller about video downloading progress.
 *
 *  @param downloader      Content manager used to download the video
 *  @param videoItem       LSVideoItem that is downloading
 *  @param downloadedBytes Downloaded bytes
 *  @param totalBytes      Total size of the video in bytes
 */
-(void)lsContentManagerDidUpdateProgress:(LSContentManager*)downloader videoItem:(LSVideoItem*)videoItem downloadedBytes:(long long)downloadedBytes totalBytes:(long long)totalBytes;

/**
 *  Delegate function to tell the caller that video download was cancelled.
 *
 *  @param downloader   Content manager used to download the video
 *  @param videoItem    LSVideoItem of which download was cancelled
 */
-(void)lsContentManagerDidCancelDownloading:(LSContentManager*)downloader videoItem:(LSVideoItem*)videoItem;
@end
