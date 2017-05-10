/*==============================================================================
Copyright (C) 2006 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#ifndef HBAYERCONVERTER_H
#define HBAYERCONVERTER_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ImportExport.h"
#include "HEnums.h"
#include "HImage.h"

#define OBSOLETE_BAYER __declspec(deprecated("This class is obsolete, consider migrating to the new HImageColorProcessing"))

class CHermesBayerConverter;

class HERMES_API HBayerConverter  
{
private:
    CHermesBayerConverter* HermesBayerConverter;

public:
	OBSOLETE_BAYER HBayerConverter();
	virtual ~HBayerConverter();

    //ERROR MANAGEMENT FUNCTIONS
    void SetErrorOutput(bool debugString, bool visual, bool infoString);
    eHErrorCode GetLastError();

    //CONFIGURATION FUNCTIONS
    eHBayerSampleFactor GetSampleFactor();
    void SetSampleFactor(eHBayerSampleFactor value);

    eHBayerPatternOrigin GetPatternOrigin();
    void SetPatternOrigin(eHBayerPatternOrigin value);
    
    eHBayerCalculationMode GetCalcMode();
    void SetCalcMode(eHBayerCalculationMode value);    

    void GetCorrectionMatrix(double& factorBlueFromBlue, double& factorBlueFromGreen, double& factorBlueFromRed,
                             double& factorGreenFromBlue, double& factorGreenFromGreen, double& factorGreenFromRed,
                             double& factorRedFromBlue, double& factorRedFromGreen, double& factorRedFromRed);
    void SetCorrectionMatrix(double factorBlueFromBlue, double factorBlueFromGreen, double factorBlueFromRed,
                             double factorGreenFromBlue, double factorGreenFromGreen, double factorGreenFromRed,
                             double factorRedFromBlue, double factorRedFromGreen, double factorRedFromRed);

    bool GetColorCorrectionMode();
    void SetColorCorrectionMode(bool colorCorrectionMode);            

    //CONVERSION FUNCTIONS
    bool ConvertToBGR24(HImage* rawImage, HImage* bayerImage);
    bool ConvertToBGR48(HImage* rawImage, HImage* bayerImage);
    bool ConvertToBGRx(HImage* rawImage, HImage* bayerImage);

    //COLOR BALANCE FUNCTIONS    
    void GetColorBalance(int& red, int& green, int& blue);
    void SetColorBalance(int red, int green, int blue);
    
    eHColorBalanceAlgorithm GetColorBalanceAlgorithm();
    void SetColorBalanceAlgorithm(eHColorBalanceAlgorithm value);
    
    bool GetAutoColorBalanceMode();
    void SetAutoColorBalanceMode(bool isAuto);
    
    bool GetAutoColorBalanceApplied();    
    void SetAutoColorBalanceApplied(bool isApplied);                 
};

#endif
