/*==============================================================================
Copyright (C) 2006 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#ifndef HAVIEXPORTER_H
#define HAVIEXPORTER_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>
#include "HImage.h"
#include "HEnums.h"
#include "HItem.h"
#include "ImportExport.h"

class CHermesAviExporter;

/*===============================================================================
CoInitialize(NULL) must be called on the same thread that will be using this 
object.  Once you have finished with it, call CoUninitialize().
===============================================================================*/
class HERMES_API HAviExporter  
{
private:
    CHermesAviExporter* HermesAviExporter;

public:
	HAviExporter();
	virtual ~HAviExporter();

    //ERROR MANAGEMENT FUNCTIONS
    void SetErrorOutput(bool debugString, bool visual, bool infoString);
    eHErrorCode GetLastError();

    //EXPORT FUNCTIONS
    bool BeginExport(LPCTSTR filename, double framerate);
    bool ExportImage(HImage* image);
    bool EndExport();

    bool IsExporting();

    bool UseSpecialCodec(eHVideoCodec codec,int sizeOfParam,void* codecParam);

    //SETTINGS AND MORE
    bool GetVideoCodecList(int* count, HItem** items);
    bool SetVideoCodec(unsigned int ID);
    bool ShowVideoCodecSettings();

    bool GetAudioSourceList(int* count, HItem** items);
    bool SetAudioSource(unsigned int ID);

    bool GetAudioCodecList(int* count, HItem** items);
    bool SetAudioCodec(unsigned int ID);
    bool ShowAudioCodecSettings();

    bool ForceFrameRate(double framerate);
};

#endif //HAVIEXPORTER_H
