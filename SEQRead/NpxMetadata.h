/*==============================================================================
Copyright (C) 2012 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/
#pragma once

#include "HMetadata.h"
#include "HMetadataInfo.h"
#include "ImportExport.h"
#include <tchar.h>

/*=============================================================================
GENERIC TYPES
=============================================================================*/
class HMetadataGenericBool : public HMetadata
{
public:
    HMetadataGenericBool(bool value)
    {
        UID = UID_METADATA_GENERIC_BOOL;
        DataSizeBytes = 1;
        
        Data = new BYTE;
        *Data = value ? 1 : 0;
        
        BuildMetadataString(this);
    }

    HMetadataGenericBool(const HMetadata& src)
        : HMetadata(src)
    {
        BuildMetadataString(this);
    }

    static void RebuildMetadataString(HMetadata* src, wchar_t* format = NULL)
    {
        BuildMetadataString(src, format != NULL ? format : L"true;false" );
    }

    static void BuildMetadataString(HMetadata* src, wchar_t* format = NULL)
    {
        //We have to use a temp string in case the default format is used
        size_t charCount = wcslen(format != NULL ? format : L"true;false");
        wchar_t* temp = new wchar_t[charCount + 1];
        wcscpy_s(temp, charCount+1, format != NULL ? format : L"true;false");

        wchar_t* separator = wcsstr(temp, L";");

        if(!separator)
        {
            delete[] temp;
            return; //no separator found
        }

        if(*src->GetData())
        {//use the string before the ;
            wcsncpy_s(separator, charCount, L"", 1);   //replace the separator by a null-terminated char
            src->SetMetadataString(temp);   //copy the first part of the string
        }
        
        else
        {//use the part of the string after the separator
            src->SetMetadataString(separator+1);
        }

        delete[] temp;
    }
};
//-----------------------------------------------------------------------------
class HMetadataGenericByte : public HMetadata
{
public:
    HMetadataGenericByte(BYTE value)
    {
        UID = UID_METADATA_GENERIC_BYTE;
        DataSizeBytes = 1;
        
        Data = new BYTE;
        *Data = value;

        BuildMetadataString(this);
    }

    HMetadataGenericByte(const HMetadata& src)
        : HMetadata(src)
    {
        BuildMetadataString(this);
    }

    static void RebuildMetadataString(HMetadata* src, wchar_t* format = NULL)
    {
        BuildMetadataString(src, format != NULL ? format : L"%d");
    }

    static void BuildMetadataString(HMetadata* src, wchar_t* format = NULL)
    {
        wchar_t* temp = new wchar_t[METADATA_INFO_FORMAT_LENGHT];
        swprintf_s(temp, METADATA_INFO_FORMAT_LENGHT, format != NULL ? format : L"%d", *src->GetData());
        src->SetMetadataString(temp);
        delete[] temp;
    }
};
//-----------------------------------------------------------------------------
class HMetadataGenericShort : public HMetadata
{
public:
    HMetadataGenericShort(short value)
    {
        UID = UID_METADATA_GENERIC_SHORT;
        DataSizeBytes = sizeof(short);
        
        Data = new BYTE[DataSizeBytes];
        *((short*)Data) = value;

        BuildMetadataString(this);
    }

    HMetadataGenericShort(const HMetadata& src)
        : HMetadata(src)
    {
        BuildMetadataString(this);
    }

    static void RebuildMetadataString(HMetadata* src, wchar_t* format = NULL)
    {
        BuildMetadataString(src,  format != NULL ? format : L"%d");
    }

    static void BuildMetadataString(HMetadata* src, wchar_t* format = NULL)
    {
        wchar_t* temp = new wchar_t[METADATA_INFO_FORMAT_LENGHT];
        swprintf_s(temp, METADATA_INFO_FORMAT_LENGHT, format != NULL ? format : L"%d", *((short*)src->GetData()));
        src->SetMetadataString(temp);
        delete[] temp;
    }
};
//-----------------------------------------------------------------------------
class HMetadataGenericUShort : public HMetadata
{
public:
    HMetadataGenericUShort(unsigned short value)
    {
        UID = UID_METADATA_GENERIC_USHORT;
        DataSizeBytes = sizeof(unsigned short);
        
        Data = new BYTE[DataSizeBytes];
        *((unsigned short*)Data) = value;

        BuildMetadataString(this);
    }

    HMetadataGenericUShort(const HMetadata& src)
        : HMetadata(src)
    {
        BuildMetadataString(this);
    }

    static void RebuildMetadataString(HMetadata* src, wchar_t* format = NULL)
    {
        BuildMetadataString(src, format != NULL ? format : L"%d");
    }

    static void BuildMetadataString(HMetadata* src, wchar_t* format = NULL)
    {
        wchar_t* temp = new wchar_t[METADATA_INFO_FORMAT_LENGHT];
        swprintf_s(temp, METADATA_INFO_FORMAT_LENGHT, format != NULL ? format : L"%d", *((unsigned short*)src->GetData()));
        src->SetMetadataString(temp);
        delete[] temp;
    }
};
//-----------------------------------------------------------------------------
class HMetadataGenericInt : public HMetadata
{
public:
    HMetadataGenericInt(int value)
    {
        UID = UID_METADATA_GENERIC_INT;
        DataSizeBytes = sizeof(int);
        
        Data = new BYTE[DataSizeBytes];
        *((int*)Data) = value;

        BuildMetadataString(this);
    }

    HMetadataGenericInt(const HMetadata& src)
        : HMetadata(src)
    {
        BuildMetadataString(this);
    }

    static void BuildMetadataString(HMetadata* src, wchar_t* format = NULL)
    {
        wchar_t* temp = new wchar_t[METADATA_INFO_FORMAT_LENGHT];
        swprintf_s(temp, METADATA_INFO_FORMAT_LENGHT, format != NULL ? format : L"%d", *((int*)src->GetData()));
        src->SetMetadataString(temp);
        delete[] temp;
    }
};
//-----------------------------------------------------------------------------
class HMetadataGenericUInt : public HMetadata
{
public:
    HMetadataGenericUInt(unsigned int value)
    {
        UID = UID_METADATA_GENERIC_UINT;
        DataSizeBytes = sizeof(unsigned int);
        
        Data = new BYTE[DataSizeBytes];
        *((unsigned int*)Data) = value;

        BuildMetadataString(this);
    }

    HMetadataGenericUInt(const HMetadata& src)
        : HMetadata(src)
    {
        BuildMetadataString(this);
    }

    static void BuildMetadataString(HMetadata* src, wchar_t* format = NULL)
    {
        wchar_t* temp = new wchar_t[METADATA_INFO_FORMAT_LENGHT];
        swprintf_s(temp, METADATA_INFO_FORMAT_LENGHT, format != NULL ? format : L"%u", *((unsigned int*)src->GetData()));
        src->SetMetadataString(temp);
        delete[] temp;
    }
};
//-----------------------------------------------------------------------------
class HMetadataGenericDouble : public HMetadata
{
public:
    HMetadataGenericDouble(double value)
    {
        UID = UID_METADATA_GENERIC_DOUBLE;
        DataSizeBytes = sizeof(double);
        
        Data = new BYTE[DataSizeBytes];
        *((double*)Data) = value;

        BuildMetadataString(this);
    }

    HMetadataGenericDouble(const HMetadata& src)
        : HMetadata(src)
    {
        BuildMetadataString(this);
    }

    static void BuildMetadataString(HMetadata* src, wchar_t* format = NULL)
    {
        wchar_t* temp = new wchar_t[METADATA_INFO_FORMAT_LENGHT];
        swprintf_s(temp, METADATA_INFO_FORMAT_LENGHT, format != NULL ? format : L"%f", *((double*)src->GetData()));
        src->SetMetadataString(temp);
        delete[] temp;
    }
};
//-----------------------------------------------------------------------------
class HMetadataGenericString : public HMetadata
{
public:
    HMetadataGenericString(wchar_t* value)
    {
        UID = UID_METADATA_GENERIC_STRING;
        DataSizeBytes = (unsigned int)(wcslen(value) + 1) * 2;

        Data = new BYTE[DataSizeBytes];
        wcscpy_s((wchar_t*)Data, DataSizeBytes/2, value);
        BuildMetadataString(this);
    }

    HMetadataGenericString(const HMetadata& src)
        : HMetadata(src)
    {
        BuildMetadataString(this);
    }

    static void BuildMetadataString(HMetadata* src, wchar_t* format = NULL)
    {
        wchar_t* temp = new wchar_t[METADATA_INFO_FORMAT_LENGHT];
        swprintf_s(temp, METADATA_INFO_FORMAT_LENGHT, format != NULL ? format : L"%s", (wchar_t*)src->GetData());
        src->SetMetadataString(temp);
        delete[] temp;
    }
};
//-----------------------------------------------------------------------------
class HMetadataGenericBinary : public HMetadata
{
public:
    HMetadataGenericBinary(BYTE* data, unsigned int dataSizeBytes)
    {
        UID = UID_METADATA_GENERIC_BINARY;
        DataSizeBytes = dataSizeBytes;

        Data = new BYTE[DataSizeBytes];
        memcpy(Data, data, DataSizeBytes);

        SetMetadataString(L"");
    }

    HMetadataGenericBinary(const HMetadata& src)
        : HMetadata(src)
    {
        SetMetadataString(L"");
    }
};


//=============================================================================
//NORPIX DEFINED TYPES
//=============================================================================
class HMetadataNorPixTime64 : public HMetadata
{
public:
    HMetadataNorPixTime64(__time64_t time, unsigned short ms, unsigned short us)
    {
        UID = UID_METADATA_NORPIX_TIME64;
        DataSizeBytes = 12;
        
        Data = new BYTE[DataSizeBytes];
        memcpy(Data, &time, 8);
        memcpy(Data+8, &ms, 2);
        memcpy(Data+10, &us, 2);

        BuildMetadataString(this);
    }

    HMetadataNorPixTime64(const HMetadata& src)
        : HMetadata(src)
    {
        BuildMetadataString(this);
    }

    static void BuildMetadataString(HMetadata* src)
    {
        __time64_t time64;
        unsigned short ms, us;

        memcpy(&time64, src->GetData(), 8);
        memcpy(&ms, src->GetData()+8, 2);
        memcpy(&us, src->GetData()+10, 2);

        wchar_t* temp = new wchar_t[30];
        wchar_t* formattedString = new wchar_t[40];
        _wctime64_s(temp, 30, &time64); //time to string
        swprintf_s(formattedString, 40, L"%.19s.%.003hu%.003hu", temp, ms, us);
        src->SetMetadataString(formattedString);
        delete[] temp;
        delete[] formattedString;
    }
};
//-----------------------------------------------------------------------------
class HMetadataNorPixLTC : public HMetadata
{
public:
    HMetadataNorPixLTC(unsigned long ltc)
    {
        UID = UID_METADATA_NORPIX_LTC;
        DataSizeBytes = 4;
        
        Data = new BYTE[DataSizeBytes];
        memcpy(Data, &ltc, 4);

        BuildMetadataString(this);
    }

    HMetadataNorPixLTC(const HMetadata& src)
        : HMetadata(src)
    {
        BuildMetadataString(this);
    }

    static void BuildMetadataString(HMetadata* src)
    {
        unsigned long ltc;
        memcpy(&ltc, src->GetData(), 4);

        //Remove embedded bits if any
	    ltc = ltc & 0x3F7F7F3F;

		//Convert to char (0xHHMMSSFF)
		wchar_t ltcStr[10];
		swprintf_s(ltcStr, L"%8.8X", ltc);

		wchar_t timeString[12];
		swprintf_s(timeString, L"%c%c:%c%c:%c%c-%c%c", 
            ltcStr[0], ltcStr[1], ltcStr[2], ltcStr[3], 
            ltcStr[4], ltcStr[5], ltcStr[6], ltcStr[7]);

        src->SetMetadataString(timeString);
    }
};
//-----------------------------------------------------------------------------
