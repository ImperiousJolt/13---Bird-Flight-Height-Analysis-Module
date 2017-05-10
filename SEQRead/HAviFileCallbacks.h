/*==============================================================================
Copyright (C) 2009 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#pragma once

#include "HImage.h"
#include "ImportExport.h"
#include "HAudioData.h"

/*=============================================================================
Make a class inheriting from HAviFileCallbacks and override the callback 
functions you want to act on.  Don't call any HAviFile functions from those
because it could cause a deadlock.
=============================================================================*/
class HERMES_API HAviFileCallbacks
{
public:
    HAviFileCallbacks(void);
    virtual ~HAviFileCallbacks(void);

    //This function is called when an image was just read from the AVI
    virtual void OnAviImageRead(HImage* image, unsigned int index, 
                             unsigned int userData=0, void* userPtr=0) {};

    //This function is called after the last image of the AVI is shown
    virtual void OnAviEndPlayback(unsigned int userData=0, void* userPtr=0) {};
};