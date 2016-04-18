//
//  IDCGCDQueue.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 18.04.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^IDCCompletionHandler)(void);

typedef enum {
    kIDCHighPriority,
    kIDCLowPriority,
    kIDCDefaultPriority,
    kIDCBackgroundPriority,
    kIDCMainThreadPriority
} IDCGCDPriority;

extern
void IDCGCDAsyncWithPriority(IDCGCDPriority priority, IDCCompletionHandler handler);
extern
void IDCGCDSyncWithPriority(IDCGCDPriority priority, IDCCompletionHandler handler);

extern
void IDCGCDAsyncInBackground(IDCCompletionHandler handler);
extern
void IDCGCDSyncInBackground(IDCCompletionHandler handler);

extern
void IDCGCDAsyncOnMainThread(IDCCompletionHandler handler);
extern
void IDCGCDSyncOnMainThread(IDCCompletionHandler handler);


