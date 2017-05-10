/*==============================================================================
Copyright (C) 2006 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#pragma once

#include "HEnums.h"
#include "HTcpCallbacks.h"

class CHermesTcpClient;

///////////////////////////////////////////////////////////////////////////////
//	HTcpClient class

class HERMES_API HTcpClient
{
private:
	CHermesTcpClient* HermesTcpClient;

public:
	HTcpClient();
	virtual ~HTcpClient();

	//ERROR MANAGEMENT FUNCTIONS
    void SetErrorOutput(bool debugString, bool visual, bool infoString);
    eHErrorCode GetLastError();

	//Callback function
	void SetCallback(HTcpCallbacks* callback, void* userPtr = NULL);

	//Connect to server
	bool IsConnected() const;
	bool ConnectTo(in_addr ip, unsigned short port);
    bool ConnectTo(BYTE ip1, BYTE ip2, BYTE ip3, BYTE ip4, unsigned short port);

	//Close a connection between a client and a server
    bool Disconnect();

	//Retrieve the socket, if connected
	SOCKET GetSocket() const;

	//Send data over a connection
    bool Send(void* data, int dataSizeBytes);

	//Retreive the address of the peer
	bool GetPeerAddress(in_addr& ipAddress, unsigned short& port);
    bool GetPeerAddress(BYTE& ip1, BYTE& ip2, BYTE& ip3, BYTE& ip4, unsigned short& port);
};
