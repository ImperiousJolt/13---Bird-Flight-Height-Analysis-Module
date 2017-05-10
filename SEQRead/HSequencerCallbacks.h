/*==============================================================================
Copyright (C) 2004 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#ifndef HSEQUENCERCALLBACKS_H
#define HSEQUENCERCALLBACKS_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HImage.h"
#include "ImportExport.h"

/*=============================================================================
Make a class inheriting from HSequencerCallbacks and override the callback 
functions you want to act on.
=============================================================================*/
class HERMES_API HSequencerCallbacks
{
public:
	HSequencerCallbacks();
	virtual ~HSequencerCallbacks();

    //This function is called when an image was written to a sequence
    virtual void OnImageWrite(unsigned int userData=0, void* userPtr=0) {};

    //This function is called when an image was just read from a sequence
    virtual void OnImageRead(HImage* image, unsigned int userData=0, void* userPtr=0) {};

    //This function is called after the last image of the sequence is shown
    virtual void OnEndOfSequence(bool& loop, unsigned int userData=0, void* userPtr=0) {};

	//This function is called when the beginning/end of playback range is reached
	virtual void OnEndOfPlaybackRange(bool& loop, unsigned int userData=0, void* userPtr=0) {};

    //This function is called the the sequence playback stops
    virtual void OnPlaybackStopped(unsigned int userData=0, void* userPtr=0) {};
};

#endif
