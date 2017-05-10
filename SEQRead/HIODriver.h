/*==============================================================================
Copyright (C) 2007 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#if !defined(AFX_HIODRIVER_H__27292BE7_B841_4A12_80CD_93F54B898BEC__INCLUDED_)
#define AFX_HIODRIVER_H__27292BE7_B841_4A12_80CD_93F54B898BEC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ImportExport.h"
#include "HEnums.h"
#include "HIODriverCallback.h"
#include "HDaqDataSet.h"
#include "HDaqCallbacks.h"

class CHermesIODriver;
class HDaqDataSet;
/*=============================================================================
Use to control a I/O port.
=============================================================================*/
class HERMES_API HIODriver  
{
private:
    CHermesIODriver* HermesIODriver;

public:
	HIODriver();
	HIODriver(LPCTSTR filePath);
	virtual ~HIODriver();

    void SetHermesIODriver(CHermesIODriver* driver);

    //Return true if input can be used
    bool InputDevicePresent();

	//Return the name of the driver managing the IO devices
	bool GetDriverName(LPTSTR name);

	//Return the name of the device identified by its index
	bool GetInputDeviceName(int deviceIndex, LPTSTR name);

	//Retreive the number of input devices managed by this driver
    int GetInputDeviceCount();

    //Initializes and opens the device drivers needed to do IO operations
    bool InitializeDeviceInput(int deviceIndex);

    //Clean up and unloading
    bool UnInitializeDeviceInput(int deviceIndex);

    //Retreive the number of input lines available
    int GetDeviceInputLineCount(int deviceIndex);

    //Retreive the name and ID of each line by index in range [1, GetInputLineCount()-1]
    bool GetDeviceInputLineInfo(int deviceIndex, int lineIndex, int* ID, LPTSTR name);

    //Get the polling delay for a particular line
    int GetPollingDelay(int deviceIndex, int lineID);

    //Retreive the last know level of an input line
    eHInputLevel GetCurrentLevel(int deviceIndex, int lineID);

    //Start monitoring level changes on a specific input line
    //If "callback" is NULL, stop monitoring the line
    //If the device can't monitor more than one line at the time, this
    //will override the older monitoring.
    //If polling delay is 0, we try using the interrupt mode if available.
    bool Monitor(int deviceIndex, int lineID, InputSupportCallback callback, int pollingDelay=100, 
                         ULONG_PTR userData=0, void* userPtr=NULL);

    //Output functions 
    //Return true if Output can be used
	bool OutputDevicePresent();
    
    //Retreive the number of input devices managed by this driver
	int GetOutputDeviceCount();
    
    //Return the name of the device identified by its index
	bool GetOutputDeviceName(int deviceIndex, LPTSTR name);
    
    //Initializes and opens the device drivers needed to do IO operations
	bool InitializeDeviceOutput(int deviceIndex);
    
    //Clean up and unloading
    bool UnInitializeDeviceOutput(int deviceIndex);
    
    //Retreive the number of Output lines available
    int GetDeviceOutputLineCount(int deviceIndex);
    
    //Retreive the name and ID of each line by index in range [1, GetOutputLineCount()-1]
    bool GetDeviceOutputLineInfo(int deviceIndex, int index, int* ID, LPTSTR name);
    
    //Retreive the last know level of an Output line
    eHOutputLevel GetOutputLevel(int deviceIndex, int lineID);

    //Set a level to an Output line
    bool SetOutputLevel(int deviceIndex, int lineID, eHOutputLevel outputLevel);

    //-------------------------
    //Pulse Generator functions
    //-------------------------

    //Return true if Pulse Generator can be used
	bool PulseGeneratorPresent();
    
    //Initializes and opens the device drivers needed to do IO operations
	bool InitializePulseGenerator();
    
    //Clean up and unloading
    bool UnInitializePulseGenerator();
    
    //Start Pulse Generator
    bool StartPulseGenerator(double freq);

    //Stop Pulse Generator
    bool StopPulseGenerator();

	//-------------------------
    //Daq functions 
    //-------------------------

	bool DaqPresent();

	//Return the name of the device identified by its index
	bool GetDaqDeviceName(int deviceIndex, LPTSTR name);

	//Retreive the number of input devices managed by this driver
	int GetDaqDeviceCount();

	//Initializes and opens the device drivers needed to do IO operations
	bool InitializeDaqDevice(int deviceIndex);

	//Clean up and unloading
	bool UnInitializeDaqDevice(int deviceIndex);

	//Retreive the number of input analog lines available
    int GetDaqDeviceLineCount(int deviceIndex);
	
	bool GetDaqDeviceLineInfo(int deviceIndex, int index, int* ID, LPTSTR name);

	//Retreive the number of  Analog Range Settings count
	int GetDaqDeviceLineRangeSettingsCount(int deviceIndex);

	//Retreive the name and ID of each level by index in range [1, GetDaqDeviceLineRangeSettingsCount()-1]
	bool GetDaqDeviceLineRangeSettingsInfo(int deviceIndex,int index,int* ID,LPTSTR name,double* min,double* max);

	//Get Max sample Rate 
	int GetMaxSampleRate(int deviceIndex,int lineCount,int*idMap);

	bool StartCapture(int deviceIndex,int speed,double pollingTime,int lineMapCount,int* lineMap,int range,CDaqSupportCallback* callback);
	
	//Stop Capture DAQ data
	bool StopCapture(int deviceIndex);

	//Retreive analog data
	bool GetSample(int deviceIndex,long timeStamp,unsigned short timeStampMS,unsigned short timeStampUS,HDaqDataSet* daqSet);

};

#endif // !defined(AFX_HIODRIVER_H__27292BE7_B841_4A12_80CD_93F54B898BEC__INCLUDED_)
