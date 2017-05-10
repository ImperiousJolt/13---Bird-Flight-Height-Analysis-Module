/*==============================================================================
Copyright (C) 2006 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#pragma once

#include "HEnums.h"
#include "HUdpCallbacks.h"

class CHermesUdpClient;

//////////////////////////////////////////////////////////////////////////
//	HUdpClient class

class HERMES_API HUdpClient
{
private:
	CHermesUdpClient* HermesUdpClient;

public:
	HUdpClient();
	virtual ~HUdpClient();

	//ERROR MANAGEMENT FUNCTIONS
    void SetErrorOutput(bool debugString, bool visual, bool infoString);
    eHErrorCode GetLastError();

	//Callback function
	void SetCallback(HUdpCallbacks* callback, void* userPtr = NULL);

	bool IsConnected() const;
	bool Connect(bool useHeader, bool sendOnly, int options);
	void Disconnect();

	//send functions
	int SendTo(in_addr address, unsigned short port, const char* buffer, int bufferLen);
	int SendToEx(in_addr address, unsigned short port, const char* buffer, int bufferLen);//uses datagram header
};
