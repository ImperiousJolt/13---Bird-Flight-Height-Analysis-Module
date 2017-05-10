/*==============================================================================
Copyright (C) 2006 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#ifndef HFPSMONITORCALLBACKS_H
#define HFPSMONITORCALLBACKS_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ImportExport.h"

class HERMES_API HFPSMonitorCallbacks  
{
public:
	HFPSMonitorCallbacks();
	virtual ~HFPSMonitorCallbacks();

    virtual void OnNewFrameRate(double fps, unsigned int userData=0, void* userPtr=0) {};
};

#endif
