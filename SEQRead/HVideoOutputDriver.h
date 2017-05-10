/*==============================================================================
Copyright (C) 2008 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#pragma once

#include <atlbase.h>
#include <TCHAR.h>
#include "ImportExport.h"
#include "HEnums.h"
#include "HImage.h"

class CHermesVideoOutputDriver;

/*=============================================================================
Use to control video output port.
=============================================================================*/
class HERMES_API HVideoOutputDriver
{
private:
    CHermesVideoOutputDriver* HermesVideoOutputDriver;

public:
    HVideoOutputDriver();
    HVideoOutputDriver(LPCTSTR filePath);
    virtual ~HVideoOutputDriver();

    void SetHermesVideoOutputDriver(CHermesVideoOutputDriver* driver);

    //Return true if video output device can be used
    bool VideoOutputDevicePresent();

    //Return the name of the device managing the Video Output 
    bool GetVideoOutputDeviceName(LPTSTR name);

    //Return the number of devices managed by this driver
    int GetVideoOutputDeviceCount();

    //Return the number of video output ports on the device
    int GetVideoOutputCount(int deviceIndex);
    
    //Check if a specific video outup port can be used
    bool IsVideoOutputAvailable(int deviceIndex, int outputIndex);
    
    //Initialize the video output (SetVideoOutputFormat is called before that)
    bool EnableVideoOutput(int deviceIndex, int outputIndex);

    //Uninitialize the video output
    bool DisableVideoOutput(int deviceIndex, int outputIndex);

    bool ShowImageOnVideoOutput(int deviceIndex, int outputIndex, HImage* image);
};

