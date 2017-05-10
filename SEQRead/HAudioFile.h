/*==============================================================================
Copyright (C) 2006 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/
#pragma once

#include "HEnums.h"         
#include "HAudioData.h"

class CAudioTarget;
class HAviFile;
class HERMES_API HAudioFile
{
	friend class HAviFile;
private:
	CAudioTarget* AudioTarget;

public:
	HAudioFile(void);
	~HAudioFile(void);

	//ERROR MANAGEMENT FUNCTIONS
    void SetErrorOutput(bool debugString, bool visual, bool infoString);
    eHErrorCode GetLastError();

	long GetAudioSamplesPerBuffer();
	long GetAudioChannelCount();
	eHAudioFormat GetAudioFormat();
	long GetAudioDepth();
	long GetAudioDepthReal();

	//Audio FILE MANAGEMENT FUNCTIONS
	bool Create(eAudioFileFormat fileType,LPCTSTR audioPath,eAudFileMode audoMode = H_AUD_FILE_AUD_BLOCK);

	bool Open(LPCTSTR audioPath, bool& readOnly); 
    
	bool Close();

	//Audio FILE READING/WRITING FUNCTIONS
	bool Write(HAudioData* audioData);
	
	bool Read(HAudioData* audioData, unsigned __int64 index, unsigned int buffers);

	bool Read(HAudioData* audioData, unsigned int buffers); 
	
	bool Read(HAudioData* audioData, long timeStamp, unsigned short timeStampMS, unsigned short timeStampUS, unsigned int buffers = 1); 
	
	bool SetReadingPosition(unsigned __int64 position);

	unsigned __int64 GetAllocatedAudioDatas();

	unsigned __int64 GetRecordingPosition();

	unsigned __int64 GetReadingPosition();

	int GetSampleRate();
	
	void  SetSampleRate(int rate);

	unsigned __int64 GetPositionByTimeStamp(long timeStamp, unsigned short timeStampMS, unsigned short timeStampUS);

	bool GetTimeStamp(unsigned __int64 index, long& timeStamp, unsigned short& timeStampMS, unsigned short& timeStampUS);

	bool SetStartTimeStamp(long timeStamp,unsigned short timeStampMS,unsigned short timeStampUS);

	bool SetPositionByTimeStamp(long timeStamp,unsigned short timeStampMS,unsigned short timeStampUS);
};
