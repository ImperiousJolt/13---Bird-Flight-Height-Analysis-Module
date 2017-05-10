/*==============================================================================
Copyright (C) 2008 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#pragma once

#include <windows.h>
#include "HEnums.h"
#include "HImage.h"

class CHermesRotation;
/*=============================================================================
This is an utility class that allows to rotate supported image.
=============================================================================*/
class HERMES_API HRotation
{
private:
    CHermesRotation* HermesRotation;
public:
    HRotation(void);
    ~HRotation(void);

    //ERROR MANAGEMENT FUNCTIONS
    void SetErrorOutput(bool debugString, bool visual, bool infoString);
    eHErrorCode GetLastError();

    //DestinationImage Size
    void SetDestinationImageWidth(unsigned int width);
    void SetDestinationImageHeight(unsigned int heigtht);
    unsigned int GetDestinationImageWidth();
    unsigned int GetDestinationImageHeight();

    //Set center coordinates of rotation
    void SetCenterCoordinateX(int value);
    void SetCenterCoordinateY(int value);
    int GetCenterCoordinateX();
    int GetCenterCoordinateY();

    //The angle of rotation in degrees.
    void SetRotateAngle(double angle);
    double GetRotateAngle();
    
    //Mode of interpolation to perform for resampling the image.
    void SetInterpolateMode(eHRotationInterpolationMode mode);
    eHRotationInterpolationMode GetInterpolateMode();

    //Smooth Edge
    void SetSmoothEdge(bool smooth);
    bool GetSmoothEdge();

	bool IsImageFormatSupported(HImage* image);

    //Rotate image
    bool Rotate(HImage* srcImage,HImage* destImage);
};
