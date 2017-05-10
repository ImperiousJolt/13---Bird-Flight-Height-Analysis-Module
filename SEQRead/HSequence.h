/*==============================================================================
Copyright (C) 2004-2005 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/
#if !defined(AFX_HSEQUENCE_H__4ACE4226_0748_4978_BFCE_4A747A351339__INCLUDED_)
#define AFX_HSEQUENCE_H__4ACE4226_0748_4978_BFCE_4A747A351339__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HSequencerCallbacks.h" //callbacks
#include "HLocker.h"

class HSequencer;
class HAviFile;
class HERMES_API HSequence
{
	friend class HAviFile;
private:
    HSequencer* Sequencer;
    CRITICAL_SECTION SequencerMutex;

	int H264Bitrate;
	int	H264GOP;
    //Callback info
    HSequencerCallbacks* UserCallbacks;
    unsigned int UserData;
    void* UserPtr;

    TCHAR FileName[MAX_PATH];

	bool CompressIndexStreamByFile; 
	bool AutoRecoverIndexStream;

    //Debug Info
    bool DebugString;
    bool Visual;
    bool InfoString;

    eHErrorCode LastError;

	bool Create(LPCTSTR seqPath, eHCompression compression, bool fileIndex,
				 unsigned long fixedSizeInByte, int quality);

    bool Open(LPCTSTR seqPath, bool autoRecoverIndex, bool fileIndex, bool& readOnly);

public:
	HSequence();
	virtual ~HSequence();

    bool IsSequenceOpen();

    bool IsRAMSequence();
    eHCompression GetSequenceCompression();
    bool SupportRewrite();

    //ERROR MANAGEMENT FUNCTIONS
    void SetErrorOutput(bool debugString, bool visual, bool infoString);
    eHErrorCode GetLastError();

    //CALLBACKS RELATED FUNCTIONS
    bool SetCallbacks(HSequencerCallbacks* userCallbacks, unsigned int userData=0, void* userPtr=NULL);
    
    //SEQUENCER READING/WRITING FUNCTIONS
    bool Create(LPCTSTR seqPath=NULL, eHCompression compression = H_COMPRESSION_NONE,
        unsigned long fixedSizeInByte = 0, int quality = 100);

	//Set H264 Sequence bitrate and gop parameter
	bool SetH264SequenceParameter(int bitrate,int gop);
	
    bool Open(LPCTSTR seqPath);
	NORPIX_ONLY bool Open(LPCTSTR seqPath, bool& readOnly);
    bool Read(HImage* image, unsigned int index);
    bool Write(HImage* image);
    bool Close();
    void DumpHeader();
    void Truncate(unsigned int index);

    bool ReadTimestamp(unsigned int index, long& time, unsigned short& timeMS, 
                       unsigned short& timeUS);

    bool GetIndexAt(long time, unsigned short timeMS, unsigned short timeUS, 
                    unsigned int& index);

    bool GetIndexNear(long time, unsigned short timeMS, unsigned short timeUS, 
                    unsigned int& index);

    void SetPlaybackPosition(unsigned int index);
    unsigned int GetPlaybackPosition();
    void SetRecordingPosition(unsigned int index);
    unsigned int GetRecordingPosition();
    
    void SetFrameRate(double framerate);
    double GetFrameRate();

    //For uncompressed RAM sequence only
    bool PreAllocateImages(unsigned int imageSizeBytes, unsigned int count); //add more preallocated images
    unsigned int GetPreAllocatedImages(); //number of pre-allocated images

    void Sort();

    //PLAYBACK FUNCTIONS
    bool Play();
    bool Stop();

    bool PlayFixedRate();
    bool IsPlayFixedRate();

    void SetPlaybackSpeed(double fps);
    double GetPlaybackSpeed();
    void SetPlaybackFrameSkip(unsigned int frameSkip);
    unsigned int GetPlaybackFrameSkip();

    void SetMaxPlaybackInterval(int ms);
    int GetMaxPlaybackInterval();

    bool IsPlaying();
    void SetPlaybackRange(unsigned int start, unsigned int end);
    void GetPlaybackRange(unsigned int& start, unsigned int& end);

    //SYNCHRONISATION FUNCTION
    bool ResynchronizePlayback(long offset, unsigned short offsetMS);
    bool ResynchronizePlayback(unsigned long index);

    bool GetNextPlaybackFrameTime(long& time, unsigned short& timeMS, 
                                  unsigned short& timeUS);

    //SEQUENCE INFO GETTERS
    unsigned int GetImageWidth();
    unsigned int GetImageHeight();
    unsigned int GetImageBitDepth();
    unsigned int GetImageBitDepthReal();
    unsigned int GetImageSizeBytes();
    eHImageFormat GetImageFormat();
    unsigned int GetAllocatedFrames();
    unsigned int GetTrueImageSize();
	bool HasMarkers();
	bool HasLTC();
    
    void SetReferenceFrame(unsigned int index);
    unsigned int GetReferenceFrame();

    void SetTimeOffset(long timeOffsetUS);
    long GetTimeOffset();

	//Compress Sequence index functions
	void SetCompressSeqIndexType(bool bFile);
	bool GetCompressSeqIndexType();
	void SetAutoRecoveryIndexStream(bool bAuto);
	bool GetAutoRecoveryIndexStream();
	virtual bool RecoverIndexStream(LPCTSTR seqPath);

    //OPTIONAL USER DATA (32 bit)
    NORPIX_ONLY unsigned int GetUserData();
    NORPIX_ONLY void SetUserData(unsigned int data);

	//OPTIONAL BIT FLAGS
	NORPIX_ONLY void SetFlags(unsigned long bitFlags);
	NORPIX_ONLY unsigned long GetFlags();

    //DESCRIPTION HANDLING
    bool GetDescription(BYTE* description);
    bool SetDescription(BYTE* description);
    eHDescriptionFormat GetDescriptionFormat();
    void SetDescriptionFormat(eHDescriptionFormat format);

	//BAYER PATTERN - stores Bayer pattern information into the sequence header
    bool IsBayer();
    void SetBayerPattern(eHBayerPatternOrigin pattern);
	bool GetBayerPattern(eHBayerPatternOrigin& pattern);

    //REFERENCE TIME - overrides the reference frame
    bool HasReferenceTime();
    void SetReferenceTime(long time, unsigned short timeMS, unsigned short timeUS);
    bool GetReferenceTime(long& time, unsigned short& timeMS, unsigned short& timeUS);
    void ResetReferenceTime();

    //Createc BYR compression parameters
    static int     GetAvailablePredictorsCount();
    static LPCTSTR GetAvailablePredictor(int index);
  
    static int     GetAvailableCompressorsCount();
    static LPCTSTR GetAvailableCompressor(int index);
    void    SetCompressor(int index);
    int     GetCompressor(); 

    void    SetThreadCount(int thread);
    int     GetThreadCount();

    //Compression Size Info 
    NORPIX_ONLY bool  EnableCompressSizeLog(bool enable);
    NORPIX_ONLY bool  GetMinCompressSize(unsigned int& size);
    NORPIX_ONLY bool  GetMaxCompressSize(unsigned int& size);
};

#endif // !defined(AFX_HSEQUENCE_H__4ACE4226_0748_4978_BFCE_4A747A351339__INCLUDED_)
