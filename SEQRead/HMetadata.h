/*==============================================================================
Copyright (C) 2012 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/
#pragma once

#include <wchar.h>
#include <windows.h>
#include "ImportExport.h"
#include "HEnums.h"
#include "MetadataID.h"

class HMetadata
{
protected:
    //The following 3 are stored after each images in the sequence
    unsigned int UID;           //Metadata Unique Identifer
    unsigned int DataSizeBytes; //Metadata size
    BYTE* Data;                 //The metadata

    wchar_t* MetadataString;    //String representation of the metadata (only used at runtime)

    HMetadata()
    {
        Data = NULL;
        MetadataString = NULL;
    }

public:

    HMetadata(unsigned int uID, unsigned int dataSizeBytes, BYTE* data, wchar_t* metadataString)
    {
        UID = uID;
        DataSizeBytes = dataSizeBytes;
        
        Data = new BYTE[dataSizeBytes];
        memcpy(Data, data, DataSizeBytes);
        
        MetadataString = NULL;
        SetMetadataString(metadataString);
    }
    
    HMetadata(const HMetadata& src)
    {
        Data = NULL;
        MetadataString = NULL;
        BuildFrom(src);
    }

    void HMetadata::operator=(const HMetadata& src)
    {
        BuildFrom(src);
    }
    
    HMetadata(BYTE* src)
    {
        memcpy(&UID, src, 4);
        memcpy(&DataSizeBytes, src+4, 4);
        
        Data = new BYTE[DataSizeBytes];
        memcpy(Data, src+8, DataSizeBytes);

        MetadataString = NULL;
    }

    virtual ~HMetadata()
    {
        if(MetadataString)
            delete[] MetadataString;
        
        if(Data)
            delete[] Data;
    }

    void BuildFrom(const HMetadata& src)
    {
        UID = src.UID;
        DataSizeBytes = src.DataSizeBytes;
        
        Data = new BYTE[DataSizeBytes];
        memcpy(Data, src.Data, DataSizeBytes);

        MetadataString = NULL;

        if(src.MetadataString)
            SetMetadataString(src.MetadataString);
    }

    unsigned int GetUID()
    {
        return UID;
    }

    unsigned int GetDataSizeBytes()
    {
        return DataSizeBytes;
    }

    BYTE* GetData()
    {
        return Data;
    }
    
    void SetMetadataString(wchar_t* src)
    {
        if(!src)
            return;

        if(MetadataString)
            delete[] MetadataString;

        size_t charCount = wcslen(src);
        MetadataString = new wchar_t[charCount + 1];
        wcscpy_s(MetadataString, charCount+1, src);
    }

    wchar_t* GetMetadataString()
    {
        if(MetadataString)
            return MetadataString;

        return L"";
    }

    int GetPacketSize()
    {
        return 8 + DataSizeBytes; //UID + size + data
    };

    void WritePacketTo(BYTE* dest)
    {//Stored as : [UID][SIZE][DATA]
        memcpy(dest, &UID, 4);
        memcpy(dest+4, &DataSizeBytes, 4);
        memcpy(dest+8, Data, DataSizeBytes);
    };
};