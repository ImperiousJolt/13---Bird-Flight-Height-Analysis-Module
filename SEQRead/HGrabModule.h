/*==============================================================================
Copyright (C) 2006 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#ifndef HGRABMODULE_H
#define HGRABMODULE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>        //basic win32 functions
#include <tchar.h>          //for UNICODE support
#include "HEnums.h"         //list of supported hardware
#include "HGrabCallbacks.h" //callbacks
#include "HIODriver.h"
#include "HVideoOutputDriver.h"
#include "GPSDataStruct.h"

class CHermesGrabModule;

class HERMES_API HGrabModule
{
private:
    CHermesGrabModule* HermesGrabModule;

public:
	HGrabModule();
	virtual ~HGrabModule();

    //ERROR MANAGEMENT FUNCTIONS
    void SetErrorOutput(bool debugString, bool visual, bool infoString);
    eHErrorCode GetLastError();

    //CARD LOADING/UNLOADING FUNCTIONS
    bool Load(eHSupportedModule card, LPCTSTR appName, bool showError=false);
    bool Load(eHSupportedModule card, LPCTSTR appName, bool clearSettings, LPCTSTR xmlFilePath, bool showError);
    
    bool Unload();
    eHSupportedModule GetCurrentGrabber();
    unsigned int GetDriverCount(bool loadableOnly = true);
    LPCTSTR GetDriverInfo(unsigned int index, eHSupportedModule* driverID, bool loadableOnly = true);
    LPCTSTR GetDriverInfo(eHSupportedModule driverID, bool loadableOnly = true);

    //STREAM CONTROL FUNCTIONS
    bool StartStreaming();
    bool StopStreaming();
    bool IsStreaming();

    //CALLBACKS RELATED FUNCTIONS
    bool SetCallbacks(HGrabCallbacks* userCallbacks, unsigned int userData=0, void* userPtr=NULL);

    //OTHERS
    bool ShowProperties(HWND parentWndHandle);
    void SetBufferCount(unsigned int count);
    unsigned int GetBufferCount();
    void QueryGrabber(long paramID, long* value);
    
    //IMAGE SIZE
    bool SetROI(unsigned int offsetX, unsigned int offsetY, unsigned int sizeX, unsigned int sizeY);
    bool GetROI(unsigned int& offsetX, unsigned int& offsetY, unsigned int& sizeX, unsigned int& sizeY);
    bool SetBinning(unsigned int value);
    bool GetBinning(unsigned int& value);

    //GRABBER SETTINGS
    bool GetSettingsCount(long* count);
    bool GetValuesCount(long featureID, long* count);
	bool GetSettingsCaps(long index, LPTSTR name, long* featureID);
	bool GetValuesCaps(long featureID, long index, LPTSTR name, long* valueID);
	bool GetCurrentValues(long featureID, long* value);
	bool SetCurrentValues(long featureID, long value);

    //GRABBER ADJUSTMENTS
    bool GetAdjustmentCount(long* count);
    bool GetAdjustmentCaps(long index, long* featureID, LPTSTR name,
        long* min, long* max, double* dMin, double* dMax, BOOL* integer,
        BOOL* logSlider, BOOL* manual, BOOL* automatic, BOOL* oneShot);
    bool GetIntegerAdjustment(long featureID, long* value);
    bool SetIntegerAdjustment(long featureID, long value);
    bool GetDoubleAdjustment(long featureID, double* value);
    bool SetDoubleAdjustment(long featureID, double value);
    bool GetAutomaticAdjustment(long featureID, BOOL* automatic);
    bool SetAutomaticAdjustment(long featureID, BOOL automatic);
    bool OneShotAdjustment(long featureID);

    //INFORMATION ABOUT THE GRABBED IMAGES
    unsigned int GetImageWidth();
    unsigned int GetImageHeight();
    unsigned int GetImageBitDepth();
    unsigned int GetImageBitDepthReal();
    unsigned int GetImageSizeBytes();
    eHImageFormat GetImageFormat();

    //TimeStamp Source functions
    HTimeSourceSyncStatus GetTimeSourceSyncStatus();
    bool IsGPSSupported();
    bool GetGPSData(CGPSDataStruct* gpsData, bool readNow = false);
    bool StopReadingGPSData();
    
	//COM PORT FUNCTIONS
	bool IsCOMPortAvailable();
	bool Transmit(void* pBuffer, unsigned long* pBufferSize, unsigned long serialTimeout);
	bool Receive(void* pBuffer, unsigned long* pBufferSize, unsigned long serialTimeout);
	bool GetEndChar(long* endChar);
	bool GetTextMode(long* textMode);
	bool GetProgFolder(LPTSTR pathName);
	bool GetSavedProgFolder(LPTSTR pathName);
	bool GetCommunicationType(long* comType);

    //AdvanceSettings Properties Window Funtions
    bool IsSupportAdvanceSettings();
    
    //Create Modal AdvanceSettings Window
    bool DoModalAdvanceSettingsWindow();
    
    //Create AdvanceSettings Windows
    bool CreateAdvanceSettingsWindow(HWND parent);
    bool ReSizeAdvanceSettingsWindow(int x,int y,int width, int height);
    bool ShowAdvanceSettingsWindow(bool show);
    bool CloseAdvanceSettingsWindow();

    //AdvanceSettings features
    bool GetCategoriesCount(long* count);
    bool GetCategoriesCap(long index, long* cat_id, LPTSTR name);
    bool GetFeatureCount(long cat_id, long* count);
    bool GetFeatureCap(long index, long cat_id,long* feature_id,LPTSTR name,
        eAdvanceSettingsFeatureType* type,eAdvanceSettingsLevel* level);
    
    bool Accessible(long cat_id,long feature_id,BOOL* access);
    bool GetEnumFeatureValueCount(long cat_id,long feature_id,long* count);
    bool GetEnumFeatureValueCap(long index, long cat_id,long feature_id,LPTSTR name,long* value);
    bool GetEnumFeatureValue(long cat_id,long feature_id,long* value);
    bool SetEnumFeatureValue(long cat_id,long feature_id,long value);
    bool GetIntegerFeatureCap(long cat_id,long feature_id,long *min,long*max);
    bool GetIntegerFeatureValue(long cat_id,long feature_id,long* value);
    bool SetIntegerFeatureValue(long cat_id,long feature_id,long value);
    bool GetDoubleFeatureCap(long cat_id,long feature_id,double *min,double*max);
    bool GetDoubleFeatureValue(long cat_id,long feature_id,double* value);
    bool SetDoubleFeatureValue(long cat_id,long feature_id,double value);
    bool GetBoolFeatureValue(long cat_id,long feature_id,BOOL* value);
    bool SetBoolFeatureValue(long cat_id,long feature_id,BOOL value);
    bool ExecuteCommandFeature(long cat_id,long feature_id);

    //I/O FUNCTIONS
    HIODriver* GetIODriver();

    //VIDEO OUTPUT FUNCTIONS
    HVideoOutputDriver* GetVideoOutputDriver();

    //BUFFER USAGE
    long GetBufferUsage();
    long GetMaxBufferUsage();
    long GetTotalBufferCount();

    //GRABBER SETTINGS EXPORT (TO XML)
    bool ExportGrabberSettings(LPCTSTR filePath);
};

#endif //HGRABMODULE_H
