/*==============================================================================
Copyright (C) 2004 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#if !defined(AFX_HIMAGECONVERTER_H__979DC5BD_F14F_467E_8376_4B55D3E4936C__INCLUDED_)
#define AFX_HIMAGECONVERTER_H__979DC5BD_F14F_467E_8376_4B55D3E4936C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <atlbase.h>
#include <TCHAR.h>
#include "HEnums.h"
#include "ImportExport.h"
#include "HImage.h"

class CHermesImageConverter;

class HERMES_API HImageConverter
{
private:
    CHermesImageConverter* HermesImageConverter;

public:
	HImageConverter();
	virtual ~HImageConverter();

    //ERROR MANAGEMENT FUNCTIONS
    void SetErrorOutput(bool debugString, bool visual, bool infoString);
    eHErrorCode GetLastError();

    bool ConvertToBGR(HImage* imageIn, HImage* imageOut, bool flip=false);
    bool ConvertToBGRx(HImage* imageIn, HImage* imageOut);
    bool ConvertToMono8(HImage* imageIn, HImage* imageOut, bool flip=false);
    
    void ValidateAllocation(bool enable);

    void SetColorRemapping(bool  enable);
    bool IsColorRemappingEnabled();
    
    void SetASCColorRemapping(bool  enable);
    bool IsASCColorRemappingEnabled();
    bool GetASCColorRemappingParam(double ascSlope[3],double ascOffset[3], double ascPower[3]);
    bool SetASCColorRemappingParam(double ascSlope[3],double ascOffset[3], double ascPower[3]);
    
    void SetColorClipLevel(int level);
    int  GetColorClipLevel();

    void SetMonoPseudoColorMode(eMonoToPseudoColorLUT mode);
    eMonoToPseudoColorLUT  GetMonoPseudoColorMode(); 

    bool LoadColorRemappingLUT(LPCTSTR fullFileStr);

    //DON'T USE THE FOLLOWING FUNCTIONS
    NORPIX_ONLY bool ConvertToMono16MSB(HImage* imageIn, HImage* imageOut, bool flip=false);
    NORPIX_ONLY bool ConvertToBGR48(HImage* imageIn, HImage* imageOut, bool flip=false);
    NORPIX_ONLY bool ConvertToMono16(HImage* imageIn, HImage* imageOut, bool flip=false);
    NORPIX_ONLY bool SaveColorLUT(LPCTSTR fullFileStr);
    NORPIX_ONLY bool SaveMonoLUT(LPCTSTR fullFileStr);

};

#endif // !defined(AFX_HIMAGECONVERTER_H__979DC5BD_F14F_467E_8376_4B55D3E4936C__INCLUDED_)
