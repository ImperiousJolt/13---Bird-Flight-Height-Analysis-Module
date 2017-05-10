/*==============================================================================
Copyright (C) 2008 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#pragma once

#include "ImportExport.h"
#include "HEnums.h"
#include "HImage.h"
#include "HAviCodecs.h"
#include "HAviFileCallbacks.h"
#include "HAudioFile.h"
#include "HSequence.h"

class CHermesAviFile;

/*=============================================================================
For the recording, the call order is :
-Call CreateAviFile
-Use the recording setup functions if you want to override the default settings
-Call AddFrame for every frame
-Call StopRecording

You can only use the recording functions if CreateAviFile was called.
You can only use the playback functions if the OpenAviFile was called.
=============================================================================*/
class HERMES_API HAviFile
{
private:
    CHermesAviFile* HermesAviFile;

    //Callback info
    HAviFileCallbacks* UserCallbacks;
    unsigned int UserData;
    void* UserPtr;

public:
    HAviFile(void);
    virtual ~HAviFile(void);

    //ERROR MANAGEMENT FUNCTIONS
    void SetErrorOutput(bool debugString, bool visual, bool infoString);
    eHErrorCode GetLastError();

    //CALLBACKS RELATED FUNCTIONS
    bool SetCallbacks(HAviFileCallbacks* userCallbacks, unsigned int userData=0, void* userPtr=NULL);

    //FILE MANAGEMENT FUNCTIONS
    bool CreateAviFile(LPCTSTR filePath, double framerate); //recording mode

    //Export to AVI with audio from an audio files
    bool CreateAviFile(LPCTSTR filePath, double framerate, HAudioFile* audioFile, int leftChannelOut, 
        int rightChannelOut); //recording mode

    bool OpenAviFile(LPCTSTR filePath); //playback mode
    bool AddFrame(HImage* image);
    bool StopRecording();
    bool CloseAviFile(); //automatically calls StopRecording()

    //CODEC FUNCTIONS
    int GetVideoCodecCount();
    LPCTSTR GetVideoCodecName(int index);
    bool SetVideoCodec(int index);
    bool ShowVideoCodecSettings();

    int GetAudioSourceCount();
    LPCTSTR GetAudioSourceName(int index);
    bool SetAudioSource(int index);
	bool ShowVideoSourceSettings();

    int GetAudioCodecCount();
    LPCTSTR GetAudioCodecName(int index);
    bool SetAudioCodec(int index);
    bool ShowAudioCodecSettings();

    //MISC FUNCTIONS
    bool ForceFrameRate(double framerate);
    eHMovieMode GetAviMode();
    unsigned long GetFrameCount();
    unsigned long GetCurrentPosition();
	NORPIX_ONLY bool GetAudioInputLevel(int& leftChannel, int& rightChannel);

    //LIVE RECORDING
    //If using live recording, the 'framerate' value of CreateAVIFile will be recalculated as follow :
    //
    //framerate = (Time of 'StopRecording' - Time of the first 'AddFrame') / Number of frames captured.
    //
    bool IsLiveRecording();
    void SetLiveRecording(bool enable);

    //SPECIAL FUNCTIONS FOR SOME CODECS
    eHVideoCodec DetectVideoCodecType(int index);
    void ResetCodecParams();
    bool SetCineFormCodecRawParams(CCineFormRawParam* params);
    bool SetCineFormCodecHDParams(CCineFormHDParam* params);

    //PLAYBACK FUNCTIONS
    bool Play();
    bool Stop();
    bool Pause();
    bool IsPlaying();
    bool IsPaused();
    bool IsStopped();
    bool ReadImage(HImage* image, unsigned int index);
    
    bool GetIndexAt(long time, unsigned short timeMS, unsigned short timeUS, 
                    unsigned int& index);
    
    void SetLooping(bool enable);
    bool IsLooping();
    double GetPlaybackFrameRate();
    
    eHAviPlaybackFormat GetPlaybackFormat();
    void SetPlaybackFormat(eHAviPlaybackFormat format);

	//METADATA SUPPORT (RIFF INFO Tags)
	bool SetTitle(LPCTSTR title);	//INFO/INAM
	bool GetTitle(LPTSTR title, UINT* length);

	bool SetCopyright(LPCTSTR copyright);	//INFO/ICOP
	bool GetCopyright(LPTSTR copyright, UINT* length);

	bool SetCreationDateTime(LPCTSTR datetime);		//INFO/ICRD
	bool GetCreationDateTime(LPTSTR datetime, UINT* length);

	bool SetDateTimeOriginal(LPCTSTR datetime);	//INFO/IDIT
	bool GetDateTimeOriginal(LPTSTR datetime, UINT* length);

	bool SetAuthor(LPCTSTR author);		//INFO/IART
	bool GetAuthor(LPTSTR author, UINT* length);

	bool SetSoftwareName(LPCTSTR name);	//INFO/ISFT
	bool GetSoftwareName(LPTSTR name, UINT* length);
};
