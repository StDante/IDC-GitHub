//
//  IDCGCDQueue.m
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 18.04.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#import "IDCGCDQueue.h"

#pragma mark - 
#pragma mark Private Declaration

dispatch_queue_t IDCPrioritySwitch(IDCGCDPriority priority);

#pragma mark -
#pragma mark Public Implementation

void IDCGCDAsyncWithPriority(IDCGCDPriority priority, IDCCompletionHandler handler) {
    dispatch_async(IDCPrioritySwitch(priority), handler);
}


void IDCGCDSyncWithPriority(IDCGCDPriority priority, IDCCompletionHandler handler) {
    if (priority == kIDCMainThreadPriority) {
        IDCGCDAsyncWithPriority(priority, handler);
    } else {
        dispatch_sync(IDCPrioritySwitch(priority), handler);
    }
}


void IDCGCDAsyncInBackground(IDCCompletionHandler handler) {
    IDCGCDAsyncWithPriority(kIDCBackgroundPriority, handler);
}

void IDCGCDSyncInBackground(IDCCompletionHandler handler) {
    IDCGCDSyncWithPriority(kIDCBackgroundPriority, handler);
}


void IDCGCDAsyncOnMainThread(IDCCompletionHandler handler) {
    IDCGCDAsyncWithPriority(kIDCMainThreadPriority, handler);
}

void IDCGCDSyncOnMainThread(IDCCompletionHandler handler) {
    IDCGCDSyncWithPriority(kIDCMainThreadPriority, handler);
}

#pragma mark -
#pragma mark Private Implementation

dispatch_queue_t IDCPrioritySwitch(IDCGCDPriority priority) {
    switch (priority) {
        case kIDCHighPriority:
            return (dispatch_get_global_queue (DISPATCH_QUEUE_PRIORITY_HIGH, 0));
        
        case kIDCLowPriority:
            return (dispatch_get_global_queue (DISPATCH_QUEUE_PRIORITY_LOW, 0));
            
        case kIDCDefaultPriority:
            return (dispatch_get_global_queue (DISPATCH_QUEUE_PRIORITY_DEFAULT, 0));
            
        case kIDCBackgroundPriority:
            return (dispatch_get_global_queue (DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0));
            
        case kIDCMainThreadPriority:
            return (dispatch_get_main_queue());
    }
    
    return (dispatch_get_global_queue (DISPATCH_QUEUE_PRIORITY_DEFAULT, 0));
}