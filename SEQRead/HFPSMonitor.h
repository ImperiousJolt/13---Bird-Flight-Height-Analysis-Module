/*==============================================================================
Copyright (C) 2006 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#ifndef HFPSMONITOR_H
#define HFPSMONITOR_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>
#include "HEnums.h"
#include "HFPSMonitorCallbacks.h"


class CHermesFPSMonitor;

class HERMES_API HFPSMonitor  
{
private:
    CHermesFPSMonitor* HermesFPSMonitor;
    
public:
	HFPSMonitor();
	virtual ~HFPSMonitor();

    //ERROR MANAGEMENT FUNCTIONS
    void SetErrorOutput(bool debugString, bool visual, bool infoString);
    eHErrorCode GetLastError();

    //FPS FUNCTIONS
    bool StartLiveCheck(unsigned int updateInterval = 1000); //Update FPS at desired interval (in MS)
    bool NewLiveFrame(bool forceUpdate); //tell the monitor a new frame was just received

    //MANUAL BENCH FUNCTION
    bool StartBench();
    bool EndBench(unsigned long frameCount, double& fps);
    bool GetBenchTime(long& seconds, unsigned short& ms);

    //Callback related functions
    bool SetCallbacks(HFPSMonitorCallbacks* userCallbacks, unsigned int userData=0, void* userPtr=NULL);
};

#endif
