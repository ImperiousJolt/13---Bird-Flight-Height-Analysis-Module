/*==============================================================================
Copyright (C) 2012 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/
#pragma once

//Maximum number of chars allowed for each string of HMetadataInfo
#define METADATA_INFO_NAME_LENGHT 256
#define METADATA_INFO_DESC_LENGHT 512
#define METADATA_INFO_FORMAT_LENGHT 256

class HMetadataInfo
{
private:
    wchar_t* CopyString(wchar_t* source)
    {
        size_t charCount = wcslen(source);
        wchar_t* dest = new wchar_t[charCount + 1];
        wcscpy_s(dest, charCount+1, source);
        return dest;
    }

public:
    unsigned int UID;           //Metadata unique identifer
    wchar_t* Name;              //Metadata name
    wchar_t* Description;       //Metadata full name
    eHMetadataFormat Format;    //Metadata format
    unsigned int MetadataSize;  //Metadata size in bytes
    wchar_t* FormatString;      //Metadata format string (printf format)

    unsigned int InfoSize;

    HMetadataInfo(unsigned int uID, wchar_t* name, wchar_t* description, 
        eHMetadataFormat format, unsigned int size, wchar_t* formatString)
    {
        UID = uID;
        Name = CopyString(name);
        Description = CopyString(description);
        Format = format;
        MetadataSize = size;
        FormatString = CopyString(formatString);
        InfoSize = 0;
    }

    HMetadataInfo(const HMetadataInfo& info)
    {
        HMetadataInfo(info.UID, info.Name, info.Description, info.Format, info.MetadataSize, info.FormatString);
        InfoSize = 0;
    }

    HMetadataInfo(BYTE* src)
    {
        InfoSize = 0;
        
        memcpy(&InfoSize, src, 4); //read the metadata info size
        src += 4;

        memcpy(&UID, src, 4); //read the uid
        src += 4;

        memcpy(&Format, src, 4); //read the format
        src += 4;

        memcpy(&MetadataSize, src, 4); //read the metadata size
        src += 4;
        
        Name = CopyString((wchar_t*) src); //read the name
        src += (wcslen(Name) + 1) * 2;

        Description = CopyString((wchar_t*) src); //read the description
        src += (wcslen(Description) + 1) * 2;

        FormatString = CopyString((wchar_t*) src); //read the format string
        src += (wcslen(FormatString) + 1) * 2;
    }

    ~HMetadataInfo()
    {
        delete[] Name;
        delete[] Description;
        delete[] FormatString;
    }

    int GetPacketSize()
    {
        if(InfoSize == 0)
        {//First time we're asked, compute the size
            InfoSize = 4; //need 4 to store the length of the info

            InfoSize += sizeof(UID) + sizeof(Format) + sizeof(MetadataSize);
        
            //+3 for the 3 end-of-string (\0)
            //*2 because unicode char take 2 bytes.
            InfoSize += (int)(wcslen(Name) + wcslen(Description) + wcslen(FormatString) + 3) * 2;
        }

        return InfoSize;
    }

    void WritePacketTo(BYTE* dest)
    {//Stored as : [UID][SIZE][DATA]
        BYTE* target = dest;
        
        //save the size of the info
        int length = GetPacketSize();
        memcpy(target, &length, 4);
        target += 4;

        //save the UID
        memcpy(target, &UID, 4);
        target += 4;
        
        //save the format
        memcpy(target, &Format, 4);
        target += 4;
        
        //save the metadata size
        memcpy(target, &MetadataSize, 4);
        target += 4;

        //save the name
        length = (int)(wcslen(Name) + 1) * 2;
        memcpy(target, Name, length);
        target += length;

        //save the description
        length = (int)(wcslen(Description) + 1) * 2; 
        memcpy(target, Description, length);
        target += length;

        //save the formatstring
        length = (int)(wcslen(FormatString) + 1) * 2;
        memcpy(target, FormatString, length);
        target += length;
    }
};