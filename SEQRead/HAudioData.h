/*==============================================================================
Copyright (C) 2010 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/
#pragma once

#include <atlbase.h>
#include <TCHAR.h>
#include "HEnums.h"
#include "HImage.h"

class CHermesAudioData;

class HERMES_API HAudioData
{
private:
	CHermesAudioData* HermesAudioData;

public:
	//Use those two function to create, duplicate and delete HDaqDataSet
	static HAudioData* CreateAudioData();

    static HAudioData* CloneAudioData(HAudioData* srcAudioData);

	static void CloneAudioData(HAudioData* srcAudioData, HAudioData* destAudioData);

	static void DeleteAudioData(HAudioData* audioData);

public:
	//DON'T USE THE FOLLOWING 5 FUNCTIONS
	NORPIX_ONLY HAudioData(CHermesAudioData* audioData);
	
	virtual NORPIX_ONLY ~HAudioData();
	
	NORPIX_ONLY CHermesAudioData* GetAudioData();
	
	NORPIX_ONLY CHermesAudioData* SetAudioData(CHermesAudioData* audioData);

	NORPIX_ONLY void Free();

	int GetSampleCount();
	
	int GetChannelNum();
	
	BYTE* GetAudioDataBuffer();
	
	eHAudioFormat GetFormat();

	int GetAudioBitDepth();

	int GetAudioBitDepthReal();
	
    //WARNING : Don't reallocate an image that you did not create with CreateAudioData()
    bool ReallocateAudio(eHAudioFormat format, int channels, int samples, long audioDepth, long audioDepthReal);

	long GetTimeStamp();
    
	unsigned short GetTimeStampMS();
    
	unsigned short GetTimeStampUS();
    
	void SetTimeStamp(long timeStamp, unsigned short timeStampMS, unsigned short timeStampUS=0);
};


