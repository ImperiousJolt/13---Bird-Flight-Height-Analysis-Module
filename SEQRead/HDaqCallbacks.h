
#pragma once

/*==============================================================================
Copyright (C) 2010 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

class HERMES_API CDaqSupportCallback
{
public:
	virtual bool WantContinuousDataRead(int deviceIndex){return false;};
	virtual	bool OnDataReceived(int deviceIndex,HDaqDataSet* dataSet) {return false;};
	virtual void OnDaqDeviceStatusChanged(int deviceIndex,int speed,double pollingTime,int range) {};
};