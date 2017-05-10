/*==============================================================================
Copyright (C) 2004 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#if !defined(AFX_IMAGEOVERLAY_H__98CDF445_8660_4754_A543_7FAAFCF33465__INCLUDED_)
#define AFX_IMAGEOVERLAY_H__98CDF445_8660_4754_A543_7FAAFCF33465__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>
#include "HEnums.h"
#include "ImportExport.h"
#include "HImage.h"

class CHermesImageOverlay;

/*=============================================================================
This is an utility class that allows to write overlays on any supported image.
i.e. almost everything except YUV
=============================================================================*/
class HERMES_API HImageOverlay
{
private:
    CHermesImageOverlay* HermesImageOverlay;

public:
	HImageOverlay();
	virtual ~HImageOverlay();

    //ERROR MANAGEMENT FUNCTIONS
    void SetErrorOutput(bool debugString, bool visual, bool infoString);
    eHErrorCode GetLastError();

    //If color and background color are the same, background is transparent.
    bool SetOverlayColor(COLORREF color);
    COLORREF GetOverlayColor();

    bool SetTextBackgroundColor(COLORREF color);
    COLORREF GetTextBackgroundColor();

    //Adjust the overlay alpha channel
    bool SetAlpha(int alpha);
    int GetAlpha();
    
    //horizontalAlign   <0 : left aligned   >0 : right aligned      =0 : centered
    //verticalAlign     <0 : top aligned    >0 : bottom aligned     =0 : centered
    bool SetTextOverlayAlign(int horizontalAlign = -1, int verticalAlign = -1);
    
    //Set the font (string is the name of the font)
    bool SetTextOverlayFont(LPCTSTR fontName);

    //For defining the font size (8 <= fontSize <= 72)
    bool SetTextOverlaySize(int fontSize);

    //Define the line thickness of the crosshair
    bool SetCrosshairThickness(unsigned int thickness);

    //Define the line thickness of the line overlays
    bool SetLineThickness(unsigned int thickness);
	
	//Define the line Style of the line overlays
    bool SetLineStyle(unsigned int Style);
    
	//Define the line color of the line overlays
    bool SetLineColor(COLORREF color);

    //Overlay could fail if the image format is not supported
    //All functions return true if the overlay was sucessful
    bool WriteAlignedTextOverlay(LPCTSTR text, HImage* image, RECT* resultRect = NULL);
    bool WriteAlignedMultilinesTextOverlay(LPCTSTR text, HImage* image, RECT* resultRect = NULL);
    bool WriteTextOverlay(LPCTSTR text, POINT dest, HImage* image, RECT* resultRect = NULL);
    bool WriteAlignedTextTwoRowsOverlay(LPCTSTR text1, LPCTSTR text2, HImage* image);
    bool WriteLineOverlay(POINT origin, POINT dest, HImage* image);
    bool WriteFlatEndsLineOverlay(POINT origin, POINT dest, int endsLength, HImage* image);
    bool WriteRoundEndsLineOverlay(POINT origin, POINT dest, int radius, HImage* image);
    bool WriteArrowOverlay(POINT origin, POINT dest, HImage* image);
    bool WriteRectOverlay(RECT rect, HImage* image);
    bool WriteFilledRectOverlay(RECT rect, HImage* image);
    bool WriteEllipseOverlay(RECT rect, HImage* image);
    bool WriteFilledEllipseOverlay(RECT rect, HImage* image);
    bool WriteCircleOverlay(POINT center, int radius, HImage* image);
    bool WritePolyOverlay(POINT pointsArray[], unsigned int pointsCount, HImage* image);
    bool WriteBezierOverlay(POINT pointsArray[], unsigned int pointsCount, HImage* image);
    bool WriteCustomOverlay(POINT pointsArray[], unsigned int pointsCount, HImage* image);
    bool WriteCrosshair(POINT dest, unsigned int sizeX, unsigned int sizeY, HImage* image);
};

#endif // !defined(AFX_IMAGEOVERLAY_H__98CDF445_8660_4754_A543_7FAAFCF33465__INCLUDED_)
