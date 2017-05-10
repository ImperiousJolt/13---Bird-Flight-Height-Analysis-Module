/*==============================================================================
Copyright (C) 2004 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#ifndef HVIEWER_H
#define HVIEWER_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>
#include "HImage.h"
#include "HEnums.h"
#include "ImportExport.h"

class CHermesViewer;

class HERMES_API HViewer  
{
private:
    CHermesViewer* HermesViewer;

public:
	HViewer();
	virtual ~HViewer();

    //ERROR MANAGEMENT FUNCTIONS
    void SetErrorOutput(bool debugString, bool visual, bool infoString);
    eHErrorCode GetLastError();
    
    //DISPLAY FUNCTIONS
    
    //Display the full size image at the given offset (if provided)
    bool ShowImage(HDC deviceContext, HImage* image, int offsetX=0, int offsetY=0);
    
    //Zoom used in the ShowImage function
    void SetZoom(int zoomX, int zoomY);
    void GetZoom(int* zoomX, int* zoomY);

    //Display the full image scaled to fit in the area provided
    bool ShowScaledImage(HDC deviceContext, HImage* image, 
        int top, int left, unsigned int width, unsigned int height);

    //All-in-one display function
    bool ShowImageOnDC(
        HDC deviceContext,          //The DC to draw on
        HImage* image,              //The image to draw
        RECT srcRect,               //The part of the source image to display
        RECT destRect,              //Where the drawing take place on the DC
        int zoomX = 100,            //Zoom percentage in X (overriden by autoScaleUp/Down)
        int zoomY = 100,            //Zoom percentage in Y (overriden by autoScaleUp/Down)
        bool autoScaleUp = false,   //Scale to fit destRect (if destRect > srcRect)
        bool autoScaleDown = false, //Scale to fit destRect (if destRect < srcRect)
        bool keepAspectRatio = true,//Keep image aspect ratio when scaling (ignore zoomY)
		RECT* resultRect = NULL);	//The result image rectangle
};

#endif
