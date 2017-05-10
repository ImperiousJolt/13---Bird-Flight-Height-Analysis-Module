/*==============================================================================
Copyright (C) 2007 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/
#if !defined(AFX_HWHITEBALANCE_H__5650D2B3_44EC_4CC9_91B5_CB08DEA5C52A__INCLUDED_)
#define AFX_HWHITEBALANCE_H__5650D2B3_44EC_4CC9_91B5_CB08DEA5C52A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ImportExport.h"
#include "HEnums.h"
#include "HImage.h"

class CHermesWhiteBalance;

class HERMES_API HWhiteBalance  
{
private:
    CHermesWhiteBalance* HermesWhiteBalance;

public:
	HWhiteBalance();
	virtual ~HWhiteBalance();

    //ERROR MANAGEMENT FUNCTIONS
    void SetErrorOutput(bool debugString, bool visual, bool infoString);
    eHErrorCode GetLastError();

    //CONFIGURATION FUNCTIONS
    void GetColorBalance(int& red, int& green, int& blue);
    void SetColorBalance(int red, int green, int blue);

    eHColorBalanceAlgorithm GetAlgorithm();
    void SetAlgorithm(eHColorBalanceAlgorithm value);

    bool GetAutoColorBalanceMode();
    void SetAutoColorBalanceMode(bool isAuto);    
    
    //PROCESSING FUNCTIONS
    bool ComputeColorBalance(HImage* image);
    bool ComputeColorBalance(int red, int green, int blue);
    bool ApplyColorBalance(HImage* image);
    bool ApplyColorBalance(HImage* inputImage, HImage* outputImage);
    bool ApplyColorBalance(HImage* inputImage, HImage* outputImage, int red, int green, int blue);

    //Non bayer format
    bool GetColorBalanceApplied();
    void SetColorBalanceApplied(bool isColorBalanceApplied);       
};

#endif // !defined(AFX_HWHITEBALANCE_H__5650D2B3_44EC_4CC9_91B5_CB08DEA5C52A__INCLUDED_)
