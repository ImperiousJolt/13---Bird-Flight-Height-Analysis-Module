/*==============================================================================
Copyright (C) 2009 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/
#pragma once

#include <atlbase.h>
#include <TCHAR.h>
#include "ImportExport.h"
#include "HEnums.h"
#include "HImage.h"

class CHermesImageColorProcessing;

class HERMES_API HImageColorProcessing
{
private:
    CHermesImageColorProcessing* HermesImageColorProcessing;

public:
    HImageColorProcessing(void);
    virtual ~HImageColorProcessing(void);

//ERROR MANAGEMENT FUNCTIONS
    void SetErrorOutput(bool debugString, bool visual, bool infoString);
    eHErrorCode GetLastError();


//COMMON
    //If "wasDoneInPlace" return value is true, the color processing was done directly on the "src" image.
    //If "wasDoneInPlace" return value is false, the color processing couldn't be done directly on "src". The precessed image is in "dest".
    //Ex : Color processing won't be done in place if bayer conversion is required (image format changes from mono to BGR)
    bool ApplyColorProcessing(HImage* src /*[in/out]*/, HImage* dest /*[in/out]*/, bool* wasDoneInPlace /*[out]*/);
    
    //Apply the color processing without altering the "src" image
    bool ApplyColorProcessing(HImage* src /*[in]*/, HImage* dest /*[in/out]*/);


//BAYER
    bool IsBayerConversionEnabled();
    void EnableBayerConversion(bool enable);

    eHBayerPatternOrigin GetPatternOrigin();
    void SetPatternOrigin(eHBayerPatternOrigin value);

    //Conversion is normally done to BGR, BGRx can be forced
    bool IsBayerConversionToBGRx();
    void EnableBayerConversionToBGRx(bool enable);

    //When the source image is > 8bpp, output can be forced to BGR48 instead of BGR24
    //No effect if converting to BGRx
    bool IsBayerHQConversionEnabled();
    void EnableBayerHQConversion(bool enable);

    //Sample factor is always 1:1 except when the calc mode is H_BAYER_CALCMODE_FAST
    eHBayerSampleFactor GetSampleFactor();
    void SetSampleFactor(eHBayerSampleFactor value);

    eHBayerCalculationMode GetCalcMode();
    void SetCalcMode(eHBayerCalculationMode value);

	bool LoadPredefinedLUT(LPCTSTR fileName);
	bool SaveLUTToFile(LPCTSTR fileName);

    //Color correction is ignored when the calc mode is H_BAYER_CALCMODE_IPP
    bool IsBayerCorrectionEnabled();
    void EnableBayerCorrection(bool enable);

    void GetCorrectionMatrix(double& factorBlueFromBlue, double& factorBlueFromGreen, double& factorBlueFromRed,
                             double& factorGreenFromBlue, double& factorGreenFromGreen, double& factorGreenFromRed,
                             double& factorRedFromBlue, double& factorRedFromGreen, double& factorRedFromRed);

    void SetCorrectionMatrix(double factorBlueFromBlue, double factorBlueFromGreen, double factorBlueFromRed,
                             double factorGreenFromBlue, double factorGreenFromGreen, double factorGreenFromRed,
                             double factorRedFromBlue, double factorRedFromGreen, double factorRedFromRed);


//COLOR BALANCE
    bool IsColorBalanceEnabled();
    void EnableColorBalance(bool enable);

    bool IsAutoColorBalanceEnabled();
    void EnableAutoColorBalance(bool enable); //default = manual

    eHColorBalanceAlgorithm GetAutoColorBalanceAlgorithm();
    void SetAutoColorBalanceAlgorithm(eHColorBalanceAlgorithm value);

    void GetManualColorBalance(int& red, int& green, int& blue);
    void SetManualColorBalance(int red, int green, int blue);

    void RecalcColorBalanceLUT();
	bool LoadIridasLUT(LPCTSTR fileName, bool& support3D, bool& support1D);

    void ReleaseColorBalanceResources();
};
