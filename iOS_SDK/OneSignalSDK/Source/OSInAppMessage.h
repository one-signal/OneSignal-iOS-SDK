/**
 * Modified MIT License
 *
 * Copyright 2017 OneSignal
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * 1. The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * 2. All copies of substantial portions of the Software may only be used in connection
 * with services provided by OneSignal.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#import <Foundation/Foundation.h>
#import "OSInAppMessagingDefines.h"
#import "OSInAppMessageDisplayStats.h"
#import "OSJSONHandling.h"
#import "OneSignal.h"
#import "OSTrigger.h"

NS_ASSUME_NONNULL_BEGIN

@interface OSInAppMessage : NSObject <NSCoding, OSJSONDecodable, OSJSONEncodable>

@property (strong, nonatomic, nonnull) NSString *messageId;
@property (strong, nonatomic, nonnull) NSDictionary<NSString *, NSDictionary <NSString *, NSString *> *> *variants;
@property (strong, nonatomic, nonnull) NSArray<NSArray <OSTrigger *> *> *triggers;

@property (nonatomic) OSInAppMessageDisplayPosition position;
@property (nonatomic) OSInAppMessageDisplayStats *displayStats;
@property (nonatomic) BOOL actionTaken;
@property (nonatomic) BOOL isPreview;
@property (nonatomic) BOOL isDisplayedInSession;
@property (nonatomic) BOOL isTriggerChanged;
@property (nonatomic) NSNumber *height;
@property (nonatomic, nullable) NSDate *endTime;

- (BOOL)isBanner;
- (BOOL)takeActionAsUnique;

- (NSSet<NSString *> *)getClickedClickIds;
- (BOOL)isClickAvailable:(NSString *)clickId;

- (void)clearClickIds;
- (void)addClickId:(NSString *)clickId;

- (BOOL)isFinished;

@end

NS_ASSUME_NONNULL_END
