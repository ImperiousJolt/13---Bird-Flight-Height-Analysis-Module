/*==============================================================================
Copyright (C) 2006 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#pragma once

#include <atlbase.h>
#include <iphlpapi.h>
#include "ImportExport.h"

#ifndef MAKEIPADDRESS
#define MAKEIPADDRESS(b1,b2,b3,b4)  ((LPARAM)(((DWORD)(b1)<<24)+((DWORD)(b2)<<16)+((DWORD)(b3)<<8)+((DWORD)(b4))))
#endif

// Get individual number
#ifndef FIRST_IPADDRESS
#define FIRST_IPADDRESS(x)  (((x) >> 24) & 0xff)
#endif
#ifndef SECOND_IPADDRESS
#define SECOND_IPADDRESS(x) (((x) >> 16) & 0xff)
#endif
#ifndef THIRD_IPADDRESS
#define THIRD_IPADDRESS(x)  (((x) >> 8) & 0xff)
#endif
#ifndef FOURTH_IPADDRESS
#define FOURTH_IPADDRESS(x) ((x) & 0xff)
#endif

//Retreive the number of IP addresses configured on the computer
//Note: A computer may have more than one network adapter. Each adapter may have more than one IP address.
HERMES_API int GetIPAddressCount();

//Retreive the IP address identified by index
HERMES_API bool GetIPAddressByIndex(in_addr* ipAddress, int index = 0);
HERMES_API bool GetIPAddressByIndex(BYTE& ip1, BYTE& ip2, BYTE& ip3, BYTE& ip4, int index = 0);

//Retreive the adapter name by IP address
HERMES_API bool GetAdapterNameByIP(int ipIndex, LPTSTR friendlyName, int& length);
HERMES_API bool GetAdapterNameByIP(LPCTSTR ipAddress, LPTSTR friendlyName, int& length);

//Retreive the adapter link speed (i.e. maximum bandwidth: 10/100/1000 Mbs)
HERMES_API bool GetAdapterLinkSpeed(LPCTSTR adapterName, unsigned long& bps);

//Retreive the computer name
HERMES_API bool GetHostName(LPTSTR hostName, int& length);


/*=============================================================================
Small functions to help packing and unpacking the data sent over the network.
Watch out, as those two functions will also move the data pointer forward.
=============================================================================*/
template <class T>
void PackData(BYTE*& data, T info)
{
    memcpy(data, &info, sizeof(T));
    data += sizeof(T);
};
//-----------------------------------------------------------------------------
template <class T>
void UnpackData(BYTE*& data, T& info)
{
    memcpy(&info, data, sizeof(T));
    data += sizeof(T);
};
//-----------------------------------------------------------------------------
template <class T>
void PackDataMem(BYTE*& data, T* toPack, int len)
{
    memcpy(data, toPack, len);
    data += len;
};
//-----------------------------------------------------------------------------
template <class T>
void UnpackDataMem(BYTE*& data, T* unPacked, int len)
{
    memcpy(unPacked, data, len);
    data += len;
};

