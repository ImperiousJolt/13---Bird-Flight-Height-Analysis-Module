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

class CHermesTcpServer;

///////////////////////////////////////////////////////////////////////////////
//	HTcpServer class

class HERMES_API HTcpServer
{
private:
	CHermesTcpServer* HermesTcpServer;

public:
	HTcpServer();
	virtual ~HTcpServer();

	//ERROR MANAGEMENT FUNCTIONS
    void SetErrorOutput(bool debugString, bool visual, bool infoString);
    eHErrorCode GetLastError();

	//Callback function
	void SetCallback(HTcpCallbacks* callback, void* userPtr = NULL);

	//Open a server accepting client and creating new client connections
    bool OpenServer(in_addr ipAddress, unsigned short port);
	bool OpenServer(BYTE ip1, BYTE ip2, BYTE ip3, BYTE ip4, unsigned short port);

    //Close the server, disconnecting all clients
    bool CloseServer();

    //Check if the server is currently open
    bool IsServerOpen();

	//Close a connection between a client and a server
    bool CloseConnection(SOCKET socket);

	//Close all connections
    void CloseAllConnections();

	//Retrieve total number of connections
	int GetConnectionCount();

	//Retreive server address and port, if open
	bool GetAddress(in_addr& ip, unsigned short& port);
	bool GetAddress(BYTE& ip1, BYTE& ip2, BYTE& ip3, BYTE& ip4, unsigned short& port);

	//Retrieve the socket of the connection identified by its index
	bool GetSocket(int connectionIndex, SOCKET& socket);

	//Get the first socket in the connection list
	SOCKET GetFirstSocket();

	//Get the next socket in the connection list
	SOCKET GetNextSocket();

	//Send data over a connection
    bool Send(SOCKET socket, void* data, int dataSizeBytes);

    //Broadcast data to all clients
    bool Broadcast(void* data, int dataSizeBytes);

    //Retreive the address of the peer of the opposite end of the socket
	bool GetPeerAddress(SOCKET socket, in_addr& ipAddress, unsigned short& port);
    bool GetPeerAddress(SOCKET socket, BYTE& ip1, BYTE& ip2, BYTE& ip3, BYTE& ip4, unsigned short& port);
};
