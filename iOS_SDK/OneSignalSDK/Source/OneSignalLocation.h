/**
 * Modified MIT License
 *
 * Copyright 2016 OneSignal
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

#ifndef OneSignalLocation_h
#define OneSignalLocation_h

#import <Foundation/Foundation.h>

typedef struct os_location_coordinate {
    double latitude;
    double longitude;
} os_location_coordinate;

typedef struct os_last_location {
    os_location_coordinate cords;
    double verticalAccuracy;
    double horizontalAccuracy;
} os_last_location;

@interface OneSignalLocation : NSObject

+ (OneSignalLocation*) sharedInstance;
+ (bool)started;
+ (void)internalGetLocation:(bool)prompt;
- (void)locationManager:(id)manager didUpdateLocations:(NSArray *)locations;
+ (void)getLocation:(bool)prompt withCompletionHandler:(void (^)(BOOL accepted))completionHandler;
+ (void)sendLocation;
+ (os_last_location*)lastLocation;
+ (void)clearLastLocation;
+ (void)onFocus:(BOOL)isActive;

@end

#endif /* OneSignalLocation_h */
