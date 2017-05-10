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

class CHermesUdpServer;

//////////////////////////////////////////////////////////////////////////
//	HUdpServer class

class HERMES_API HUdpServer
{
private:
	CHermesUdpServer* HermesUdpServer;

public:
	HUdpServer();
	virtual ~HUdpServer();

	//ERROR MANAGEMENT FUNCTIONS
    void SetErrorOutput(bool debugString, bool visual, bool infoString);
    eHErrorCode GetLastError();

	//Callback function
	void SetCallback(HUdpCallbacks* callback, void* userPtr = NULL);

	bool IsOpened() const;
	bool Open(in_addr ip, unsigned short port, bool useHeader, int options);
	void Close();

	//send functions
	int SendTo(in_addr address, unsigned short port, const char* buffer, int bufferLen);
	int SendToEx(in_addr address, unsigned short port, const char* buffer, int bufferLen);//uses datagram header
};
