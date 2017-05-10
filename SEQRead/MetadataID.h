/*==============================================================================
Copyright (C) 2012 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/
#pragma once

/*=============================================================================
Those are the core metadata IDs.

Unique identifiers 0 to 2147483647 are reserved for generic and NorPix metadatas.
Third party users can create their own metadatas using IDs from 2147483648 to
4294967295.
=============================================================================*/

#define UID_METADATA_GENERIC_FIRST 0x00000000
#define UID_METADATA_GENERIC_LAST  0x00000020
#define UID_METADATA_NORPIX_FIRST  0x00000021
#define UID_METADATA_NORPIX_LAST   0x7FFFFFFF
#define UID_METADATA_USER_FIRST    0x80000000
#define UID_METADATA_USER_LAST     0xFFFFFFFF

//GENERIC TYPES
#define UID_METADATA_GENERIC_BOOL   UID_METADATA_GENERIC_FIRST+0
#define UID_METADATA_GENERIC_BYTE   UID_METADATA_GENERIC_FIRST+1
#define UID_METADATA_GENERIC_SHORT  UID_METADATA_GENERIC_FIRST+2
#define UID_METADATA_GENERIC_USHORT UID_METADATA_GENERIC_FIRST+3
#define UID_METADATA_GENERIC_INT    UID_METADATA_GENERIC_FIRST+4
#define UID_METADATA_GENERIC_UINT   UID_METADATA_GENERIC_FIRST+5
#define UID_METADATA_GENERIC_DOUBLE UID_METADATA_GENERIC_FIRST+6
#define UID_METADATA_GENERIC_STRING UID_METADATA_GENERIC_FIRST+7
#define UID_METADATA_GENERIC_BINARY UID_METADATA_GENERIC_FIRST+8

//NORPIX DEFINED TYPES
#define UID_METADATA_NORPIX_TIME64  UID_METADATA_NORPIX_FIRST+0
#define UID_METADATA_NORPIX_LTC     UID_METADATA_NORPIX_FIRST+1
