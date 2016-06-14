//
//  IDCGCDQueue.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 18.04.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^IDCGCDHandler)(void);

typedef enum {
    kIDCHighPriority,
    kIDCLowPriority,
    kIDCDefaultPriority,
    kIDCBackgroundPriority,
    kIDCMainThreadPriority
} IDCGCDPriority;

extern
void IDCGCDAsyncWithPriority(IDCGCDPriority priority, IDCGCDHandler handler);
extern
void IDCGCDSyncWithPriority(IDCGCDPriority priority, IDCGCDHandler handler);

extern
void IDCGCDAsyncInBackground(IDCGCDHandler handler);
extern
void IDCGCDSyncInBackground(IDCGCDHandler handler);

extern
void IDCGCDAsyncOnMainThread(IDCGCDHandler handler);
extern
void IDCGCDSyncOnMainThread(IDCGCDHandler handler);


