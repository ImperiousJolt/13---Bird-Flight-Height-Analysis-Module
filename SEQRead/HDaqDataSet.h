#pragma once

/*==============================================================================
Copyright (C) 2010 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/
#include "HEnums.h"
#include "HImage.h"

class CHermesDaqDataSet;

class HERMES_API HDaqDataSet
{
private:
	CHermesDaqDataSet* HermesDaqDataSet;
public:
	//Use those two function to create, duplicate and delete HDaqDataSet
	static HDaqDataSet* CreateDaqDataSet();

    static HDaqDataSet* CloneDaqDataSet(HDaqDataSet* srcDataSet);

	static void CloneDaqDataSet(HDaqDataSet* srcDataSet, HDaqDataSet* destDataSet);

	static void DeleteDaqDataSet(HDaqDataSet* dataSet);
public:
	//DON'T USE THE FOLLOWING 5 FUNCTIONS
	NORPIX_ONLY HDaqDataSet(CHermesDaqDataSet* dataSet);
	
	virtual NORPIX_ONLY ~HDaqDataSet();
	
	NORPIX_ONLY CHermesDaqDataSet* GetDaqDataSet();
	
	NORPIX_ONLY CHermesDaqDataSet* SetDaqDataSet(CHermesDaqDataSet* dataSet);

	NORPIX_ONLY void Free();

	void SetReferenceFrameIndex(long frameIndex);
	
	int	GetReferenceFrameIndex();
	
	int GetSampleCount();
	
	int GetChannelNum();
	
	float* GetSample(int sampleIndex);
	
	long GetTimeStamp();
    
	unsigned short GetTimeStampMS();
    
	unsigned short GetTimeStampUS();
    
	void SetTimeStamp(long timeStamp, unsigned short timeStampMS, unsigned short timeStampUS=0);
};
