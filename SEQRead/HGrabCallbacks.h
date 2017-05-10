/*==============================================================================
Copyright (C) 2006 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#ifndef HGRABCALLBACKS_H
#define HGRABCALLBACKS_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HImage.h"
#include "ImportExport.h"

/*=============================================================================
Make a class inheriting from HGrabCallbacks and override the callback 
functions you want to act on.
=============================================================================*/
class HERMES_API HGrabCallbacks
{
public:
	HGrabCallbacks();
	virtual ~HGrabCallbacks();

    //This function is called before the driver starts waiting for a new image
    virtual void OnBeforeImageReceived(unsigned int userData=0, void* userPtr=0) {};
    
    //This function is called when an image was just received from the grabber
    virtual void OnImageReceived(HImage* image, unsigned int userData=0, void* userPtr=0) {};

    //This function is called just after a captured image buffer is released
    virtual void OnImageReleased(unsigned int userData=0, void* userPtr=0) {};

    //This function is called before queuing a buffer for grabbing
    virtual void OnBeforeQueuingGrab(unsigned int userData=0, void* userPtr=0) {};

    //This function is called after a buffer has been succesfully queued for grabbing
    virtual void OnAfterQueuingGrab(unsigned int userData=0, void* userPtr=0) {};

	//This function is called before starting the streaming process
	virtual void OnBeforeStartStreaming(unsigned int userData=0, void* userPtr=0) {};

	//This function is called after the streaming process has been started
	virtual void OnAfterStartStreaming(unsigned int userData=0, void* userPtr=0) {};

	//This function is called before stopping the streaming process
	virtual void OnBeforeStopStreaming(unsigned int userData=0, void* userPtr=0) {};

	//This function is called after the streaming process has been stopped
	virtual void OnAfterStopStreaming(unsigned int userData=0, void* userPtr=0) {};

    //This function is called when the grabber has something to say
    virtual void OnNotification(eHGRABBER_NOTIFICATION notification, 
                                eHSUGGESTED_ACTION suggestedAction) {};
};

#endif //HGRABCALLBACKS_H
