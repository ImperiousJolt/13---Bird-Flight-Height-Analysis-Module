/*==============================================================================
Copyright (C) 2004 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#ifndef HIMAGEEXPORTER_H
#define HIMAGEEXPORTER_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <tchar.h>
#include <windows.h>
#include "HImage.h"
#include "HEnums.h"
#include "ImportExport.h"

class CHermesImageExporter;

class HERMES_API HImageExporter
{
private:
    CHermesImageExporter* HermesImageExporter;

public:
	HImageExporter();
	virtual ~HImageExporter();

    //ERROR MANAGEMENT FUNCTIONS
    void SetErrorOutput(bool debugString, bool visual, bool infoString);
    eHErrorCode GetLastError();

    //EXPORT FUNCTIONS
    bool BeginExportBmp(LPCTSTR filename, int digits=1, unsigned int startIndex=1);
    bool BeginExportJpeg(LPCTSTR filename, int digits=1, unsigned int startIndex=1);
    bool BeginExportTiff(LPCTSTR filename, bool multiTIFF=false, int digits=1, unsigned int startIndex=1);
    bool BeginExportPng(LPCTSTR filename, int digits=1, unsigned int startIndex=1);
	bool BeginExportJpeg2k(LPCTSTR filename, int digits=1, unsigned int startIndex=1);
	bool BeginExportFit(LPCTSTR filename, bool multiFit=false, bool exportColor=false, int digits=1, unsigned int startIndex=1);
    bool BeginExportDpx(LPCTSTR filename, bool force10bitBGR=false, int digits=1, unsigned int startIndex=1);

    bool ExportImage(HImage* image, LPTSTR exportedFileName=NULL);
    bool EndExport();

    bool BeginExportBmpTo();
    bool BeginExportJpegTo();
    bool BeginExportTiffTo();
    bool BeginExportPngTo();
	bool BeginExportJpeg2kTo();
	bool BeginExportFitTo(bool exportColor = false);
    bool BeginExportDpxTo(bool force10bitBGR=false);

    bool ExportImageTo(HImage* image, LPCTSTR fileName);
    bool EndExportTo();

//JPEG related functions
    bool SetJPEGQuality(eHJpegQuality quality);
    eHJpegQuality GetJPEGQuality();

    //useIPP = true for Intel IPP, false for freeImage lib
    bool SetJPEGLib(bool useIPP);

	//EXIF support (when using Intel IPP to export to JPEG only)
	bool AddJPEGMetadata(unsigned short tag, unsigned short type, unsigned long count, const void* data);
};

#endif //HIMAGEEXPORTER_H
