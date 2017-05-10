/*==============================================================================
Copyright (C) 2006 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#pragma once

#include <winsock2.h>
#include "ImportExport.h"

/*=============================================================================
Make a class inheriting from HUdpCallbacks and override the callback 
functions you want to act on.
=============================================================================*/
class HERMES_API HUdpCallbacks
{
public:
	HUdpCallbacks(){}
	virtual ~HUdpCallbacks(){}

	virtual void OnReceiveData(SOCKET socket, void* data, unsigned int dataSize, const sockaddr_in* sender, void* userPtr) {}
};
