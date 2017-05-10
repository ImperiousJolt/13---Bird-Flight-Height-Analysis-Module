/*==============================================================================
Copyright (C) 2009 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/
#pragma once

#pragma warning(disable : 4995)

#include "ImportExport.h"
#include <windows.h>

//enum VideoFormat
//{
//    FEEDER_MONO = 0,
//    FEEDER_BGR24,
//    FEEDER_UVY411,
//    FEEDER_UVY422,
//    FEEDER_YUV422,
//    FEEDER_ISGJPEG,
//    FEEDER_EURESYS,
//    FEEDER_BYR4,
//    FEEDER_BYR1,
//	FEEDER_Y16,
//	FEEDER_RG30,
//	FEEDER_RG48,
//};

enum CineFormCurve
{
    H_CURVE_GAMMA22 = 0,
	H_CURVE_GAMMA18,
	H_CURVE_LOG90,
    H_CURVE_GAMMA_CUSTOM,
	H_CURVE_LOG_CUSTOM,
	H_CURVE_LINE_CUSTOM,
};
//-----------------------------------------------------------------------------
struct HERMES_API CCineFormParam
{
    int EncoderQuality; 
    float ColorMetrx[3][4];
    float Whitebalance [4]; 
    DWORD Buffer;
	CineFormCurve  CurveType;
    int Numerator;
    int Denominator;
    char LookFile[MAX_PATH];
    
    CCineFormParam()
    {
         CurveType = H_CURVE_GAMMA22;
         Numerator = 1;
         Denominator = 1; 
         Buffer = 2;
         EncoderQuality = 1;
         memset(LookFile,0,MAX_PATH);
    }
};
//-----------------------------------------------------------------------------
struct HERMES_API CCineFormRawParam : public CCineFormParam
{
	DWORD BayerPattern;

    CCineFormRawParam() : CCineFormParam()
	{
		BayerPattern = 0;
	};
};
//-----------------------------------------------------------------------------
struct HERMES_API CCineFormHDParam : public CCineFormParam
{
	bool ForceTo444;

    CCineFormHDParam() : CCineFormParam()
	{
		ForceTo444 = false;
	};
};	
