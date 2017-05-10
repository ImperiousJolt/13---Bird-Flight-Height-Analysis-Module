/*==============================================================================
Copyright (C) 2004 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#ifndef HIMAGE_H
#define HIMAGE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef NORPIX_ONLY_FUNCTIONS
    #define NORPIX_ONLY
#elif _MSC_VER >= 1400  //VS2005
    #define NORPIX_ONLY __declspec(deprecated("** You should not use this function **"))
#elif _MSC_VER >= 1300  //VS2003
    #define NORPIX_ONLY __declspec(deprecated)
#else //everything else (thanks Jens :)
    #define NORPIX_ONLY
#endif

#include <time.h>
#include "ImportExport.h"
#include "HEnums.h"
#include "HMetadata.h"

class HImage;
class CHermesImage;

/*=============================================================================
COMPRESSED CHANNEL EXPLANATION

ImageData.CompressedChannel = [SIZE][COMPRESSED IMAGE DATA][TIMESTAMP]
Size :                        [4 b.][X bytes              ][8 bytes  ]
Example :                     [1004][image data=1000 bytes][timestamp]

GetCompressedChannel() returns a pointer to the begining of [SIZE]
GetCompressedImage() returns a pointer to the begining of [COMPRESSED IMAGE DATA]
GetCompressedChannelSizeBytes() returns the size of [SIZE]+[COMPRESSED IMAGE DATA] (ex : 1004)
GetCompressedImageSizeBytes() returns the size of [COMPRESSED IMAGE DATA] (ex : 1000)
===============================================================================*/

class HERMES_API HImage
{
private:
    CHermesImage* HermesImage;
    
public:
    //Use those two function to create, duplicate and delete HImages
    static HImage* CreateHImage();
    static HImage* CloneHImage(HImage* srcImage);
    static void CloneHImage(HImage* srcImage, HImage* destImage);
    static void DeleteHImage(HImage* image);

public:
    //DON'T USE THE FOLLOWING 5 FUNCTIONS
    NORPIX_ONLY HImage(CHermesImage* hermesImage);
	virtual NORPIX_ONLY ~HImage();
    NORPIX_ONLY CHermesImage* GetImage();
    NORPIX_ONLY void AttachImage(CHermesImage* hermesImage);
    NORPIX_ONLY void Free();

    //WARNING : Don't reallocate an image that you did not create with CreateHImage()
    void ReallocateImage(unsigned int width, unsigned int height, unsigned int bitDepth, 
        unsigned int bitDepthReal, eHImageFormat imageFormat);

    void ReallocateCompressedImage(eHCompression compression, int compressedImageSizeBytes);

    unsigned int GetImageWidth();
    unsigned int GetImageHeight();
    unsigned int GetImageBitDepth();
    unsigned int GetImageBitDepthReal();
    unsigned int GetImageSizeBytes();
    eHImageFormat GetImageFormat();
    
    //Raw image data
    void* GetRawImageData();
    
    //For planar images
    void* GetRedChannel();
    void* GetGreenChannel();
    void* GetBlueChannel();
    
    //The compressed channel holds the compressed image and some more stuff
    eHCompression GetCompressionFormat();
    int GetCompressedChannelSizeBytes();
    void* GetCompressedChannel();

    int GetCompressedImageSizeBytes();
    void* GetCompressedImage();

    long GetTimestamp();
    unsigned short GetTimestampMS();
    unsigned short GetTimestampUS();
    void SetTimestamp(long timeStamp, unsigned short timeStampMS, unsigned short timeStampUS=0);

    //Metadata
    int GetMetadataCount();
    HMetadata* GetMetadata(int index);
    int GetSpecificMetadataCount(unsigned int uID);
    HMetadata* GetSpecificMetadata(unsigned int uID, int index);
    void AddMetadata(const HMetadata& metadata);
    void RemoveAllMetadata();
};

#endif //HIMAGE_H