/*==============================================================================
Copyright (C) 2006 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#ifndef HERRORMANAGER_H
#define HERRORMANAGER_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HEnums.h"
#include <atlbase.h>
#include <TCHAR.h>
#include <stdio.h>
#include "ImportExport.h"

class HERMES_API HErrorManager  
{
public:
    static LPCTSTR GetErrorString(eHErrorCode code)
    {
        switch(code)
        {
            case H_ERROR_SUCCESS :              return _T("Success");
            case H_ERROR_NOAUTHORIZATION :      return _T("Could not find a valid authorization code for this module");
            case H_ERROR_EXPORT_IN_PROGRESS :   return _T("The export has already begun");
            case H_ERROR_INVALID_COMPRESSION :  return _T("Invalid JPEG compression method");
            case H_ERROR_NO_BEGINEXPORT :       return _T("You must call a BeginExport function first");
            case H_ERROR_NO_IMAGE_DATA:         return _T("No image data");
            case H_ERROR_INVALID_DIGIT :        return _T("Digit must be between 0 and 12");
            case H_ERROR_NO_GRABMAN :           return _T("Could not find the grabber manager (Grabman.dll)");
            case H_ERROR_INI_FAIL :             return _T("Grabber Initialization failed.");
            case H_ERROR_CREATE_BUFFER :        return _T("Could not create a buffer");
            case H_ERROR_BUFFER_INTERNAL :      return _T("CreateBuffer function failed");
            case H_ERROR_NO_GRABBER :           return _T("No grabber loaded");
            case H_ERROR_CONVERT_BGR24 :        return _T("Conversion to BGR24 failed");
            case H_ERROR_CONVERT_BGRX :         return _T("Conversion to BGRx failed");
            case H_ERROR_CONVERT_UNSUPPORTED :  return _T("Unsupported conversion");
            case H_ERROR_CONVERT_YUV422 :       return _T("Error conversion Intel YUV422");
		    case H_ERROR_CONVERT_UVY422:		return _T("Error conversion Intel UVY422");
		    case H_ERROR_CONVERT_UVY411:		return _T("Error conversion Intel UVY411");
		    case H_ERROR_CONVERT_UVY444:		return _T("Error conversion Intel UVY444");
            case H_ERROR_CREATE_SYSTEM_ENUM :   return _T("Failed to create system enumerator");
            case H_ERROR_CREATE_CLASS_ENUM :    return _T("Failed to create class enumerator");
            case H_ERROR_MONIKER_NULL :         return _T("Enum moniker null");
            case H_ERROR_LOADING_VIDEO_CODEC :  return _T("Failed to load the desired video codec");
            case H_ERROR_LOADING_AUDIO_SOURCE : return _T("Failed to load the desired audio source");
            case H_ERROR_LOADING_AUDIO_CODEC :  return _T("Failed to load the desired audio codec");
            case H_ERROR_NO_CODEC_SETTINGS :    return _T("No settings for this codec");
            case H_ERROR_CREATE_GRAPH_BUILDER : return _T("Failed to create the graph builder");
            case H_ERROR_CREATE_CAPTURE_BUILDER : return _T("Failed to create the capture graph");
            case H_ERROR_CREATE_FEEDER :        return _T("Could not create the ImageFeeder Filter");
            case H_ERROR_ADD_FEEDER :           return _T("Could not add the image feeder to the graph");
            case H_ERROR_ADD_VCODEC :           return _T("Could not add the video codec to the graph");
            case H_ERROR_ADD_ACODEC :           return _T("Could not add the audio codec to the graph");
            case H_ERROR_ADD_AUDIO_SOURCE :     return _T("Could not add the audio source to the graph");
            case H_ERROR_ADD_MUX_FILE :         return _T("Could not setup MUX and file writer");
            case H_ERROR_CONNECT_VSOURCE_VCODEC : return _T("Failed to connect video source to video compressor");
            case H_ERROR_CONNECT_VCODEC_MUX :   return _T("Failed to connect video compressor to mux");
            case H_ERROR_CONNECT_VSOURCE_MUX :  return _T("Failed to connect video source to mux");
            case H_ERROR_CONNECT_ASOURCE_ACODEC : return _T("Failed to connect audio source to audio compressor");
            case H_ERROR_CONNECT_ACODEC_MUX :   return _T("Failed to connect audio compressor to mux");
            case H_ERROR_CONNECT_ASOURCE_MUX :  return _T("Failed to connect audio source to mux");
            case H_ERROR_CONNECT_SOURCE_SPLITTER:    return _T("Failed to connect the file source to splitter");
            case H_ERROR_CONNECT_SPLITTER_RENDERER:  return _T("Failed to connect the splitter to the renderer");
            case H_ERROR_SYNCH_SOURCE :         return _T("Failed to set the synch source");
            case H_ERROR_INTERLEAVE_MODE :      return _T("Failed to set the interleave mode");
            case H_ERROR_INTERLEAVE_TIME :      return _T("Failed to set the interleave time");
            case H_ERROR_SEQ_CANTCREATEFILE :   return _T("Invalid file handle when trying to open for writing");
            case H_ERROR_NOSEQ :                return _T("No sequence to write to or invalid image");
            case H_ERROR_WRITE_SEQ :            return _T("Could not write the image to the sequence.  (Disk full ?)");
            case H_ERROR_SEQ_INVALIDMAGICNUMBER : return _T("Invalid Magic Number");
            case H_ERROR_SEQ_WRONGHEADERSIZE :  return _T("Invalid Sequence Header Size");
            case H_ERROR_SEQ_INVALIDLENGTH :    return _T("Invalid Sequence Number of Frames Allocated");
            case H_ERROR_SEQ_INVALIDFRAMERATE : return _T("Invalid Sequence Frame Rate");
            case H_ERROR_SEQ_INVALIDDATA :      return _T("Invalid Sequence Data length");
            case H_ERROR_SEQ_INVALIDWIDTH :     return _T("Invalid Sequence Width");
            case H_ERROR_SEQ_INVALIDHEIGHT :    return _T("Invalid Sequence Height");
            case H_ERROR_SEQ_INVALIDDEPTH :     return _T("Invalid Sequence Bit Depth");
            case H_ERROR_SEQ_INVALIDIMAGESIZE : return _T("Invalid Sequence Image Size");
            case H_ERROR_SEQ_UNSUPPORTED_FORMAT:return _T("This sequence does not support this image format");
            case H_ERROR_SECTORBYTES_ZERO :     return _T("Bytes per sector is 0");
            case H_ERROR_FILENOTFOUND :         return _T("File not found");
            case H_ERROR_CANTCREATEFILE :       return _T("Could not create/open desired file");
            case H_ERROR_INVALID_INDEX :        return _T("Invalid index");
            case H_ERROR_OUTOFMEMORY :          return _T("Out of memory");
            case H_ERROR_IMAGEFORMATCHANGED :   return _T("The image format is incompatible with the current sequence");
            case H_ERROR_TOOMUCHDATA :          return _T("User data is too large to be written in the sequence");
            case H_ERROR_GDIDRAW :              return _T("GDI draw failed");
            case H_ERROR_SCRIPTRUNNING :        return _T("Stop the script before changing it.");
            case H_ERROR_FAILEDREGISTER :       return _T("Invalid Registration code");
            case H_ERROR_IMAGE_FORMAT :         return _T("Unsupported image format");
            case H_ERROR_SCRIPTER_NOT_RUNNING : return _T("The Scripter module is not running.");
            case H_ERROR_STOP_PLAYBACK:         return _T("Must not be in playback mode");
            case H_ERROR_STREAMING:             return _T("This action can't be done if grabber is streaming");
            case H_ERROR_DONTSUPPORTREWRITE:    return _T("This sequence format doesn't support rewrite");
            case H_ERROR_UNSUPPORTED:           return _T("This feature is unsupported");
            case H_ERROR_UNSUPPORTED_SETTINGS:  return _T("Settings interface not found on driver");
            case H_ERROR_UNSUPPORTED_ADJUSTMENTS: return _T("Adjustments interface not found on driver");
            case H_ERROR_NOCOMPORT:             return _T("No COM PORT found on this grabber.");
            case H_ERROR_EXPORT_FAILED:         return _T("Failed to export image");
            case H_ERROR_INPUTSUPPORT_LOAD:     return _T("Could not load the input support device");
            case H_ERROR_OUTPUTSUPPORT_LOAD :   return _T("Could not load the output support device");
            case H_ERROR_VIDEOOUTPUTSUPPORT_LOAD: return _T("Could not load the video output support device");
            case H_ERROR_UNSUPPORTED_ADVANCEFEATURE: return _T("AdvanceSettings is unsupported");    
            case H_ERROR_NOBITMAP:              return _T("No bitmap file selected");
            case H_ERROR_QUICKTIME_INIFAIL:     return _T("Quicktime could not be initialized");
            case H_ERROR_WRONG_MODE:            return _T("This action can't be done while in the current mode");
            case H_ERROR_QUICKTIME_ERROR:       return _T("A Quicktime function returned an error");
            case H_ERROR_PARAM_NOT_SUPPORTED:   return _T("This parameter is not supported");
		    case H_ERROR_INPUTSUPPORT_DEV_INIT_FAILED: return _T("Input device initialization failed");
		    case H_ERROR_INPUTSUPPORT_DEV_UNINIT_FAILED: return _T("Input device uninitialization failed");
		    case H_ERROR_INPUTSUPPORT_MONITOR:  return _T("Failed to start/stop monitoring input line");
		    case H_ERROR_OUTPUTSUPPORT_DEV_INIT_FAILED: return _T("Output device initialization failed");
		    case H_ERROR_OUTPUTSUPPORT_DEV_UNINIT_FAILED: return _T("Output device uninitialization failed");
            case H_ERROR_ADD_FILEREADER:        return _T("Could not add the File Reader to the graph");
            case H_ERROR_ADD_AVISPLITTER:       return _T("Could not add the AVI Splitter to the graph");
            case H_ERROR_CREATE_RENDER:         return _T("Could not create Image Renderer Filter");
            case H_ERROR_NO_PROCESSING_APPLIED: return _T("No processings were applied on the image");
            case H_ERROR_BAYER_CONVERSION:      return _T("The image could not bayer converted");
            case H_ERROR_COLOR_BALANCING:       return _T("The image could not be color balanced");
            case H_ERROR_DAQSUPPORT_READ_FAILED:return _T("Could not read daq data");
			case H_ERROR_DAQSUPPORT_FORMAT_CHANGED:		return _T("Daq format changed");
			case H_ERROR_AUDIO_FORMAT_CHANGED:	return _T("Audio format changed");
            case H_ERROR_CANT_ADD_FRAME:        return _T("Cannot add more frames to the AVI");
			case H_ERROR_MIRROR_ERROR:			return _T("Image mirror Error");
			case H_ERROR_MERGE_ERROR:			return _T("Image merge Error");
			case H_ERROR_AUDIO_FORMAT:			return _T("Unsupported audio format"); 	
			case H_ERROR_AUDIO_LOAD:			return _T("Failed to load audio drvier"); 	
			case H_ERROR_AUDIO_INPUTSUPPORT_LOAD:	return _T("Failed to load audio input device"); 	
			case H_ERROR_AUDIO_OUTPUTSUPPORT_LOAD:	return _T("Failed to load audio output device"); 	
			case H_ERROR_AUDIO_INPUTSUPPORT:		return _T("Doesn't support audio input device"); 	
			case H_ERROR_AUDIO_OUTPUTSUPPORT:		return _T("Doesn't support audio output device"); 		
			case H_ERROR_UNSUPPORT_FUNCTION:		return _T("Don't support this function"); 			
			case H_ERROR_CREATE_SOCKET:			return _T("Failed to create socket");
			case H_ERROR_BIND_SOCKET:			return _T("Failed to bind socket");
			case H_ERROR_LISTEN_SOCKET:			return _T("Failed to listen socket");
			case H_ERROR_SHUTDOWN_SOCKET:		return _T("Failed to disable sends/receives on socket");
			case H_ERROR_CLOSE_SOCKET:			return _T("Failed to close socket");
			case H_ERROR_INVALID_SOCKET:		return _T("Invalid socket");
			case H_ERROR_SERVER_NOT_RUNNING:	return _T("Server not running");
			case H_ERROR_SERVER_ALREADY_OPEN:	return _T("Server already open");
			case H_ERROR_CLIENT_ALREADY_CONNECTED:	return _T("Client already connected");
			case H_ERROR_CONNECTION_FAILED:			return _T("Connection failed");
			case H_ERROR_SEND:						return _T("Failed to send data");
			case H_ERROR_DAQSUPPORT_CANTCREATEFILE: return _T("Invalid DAQ file handle when trying to open for writing");
			case H_ERROR_DAQSUPPORT_INVALID_INDEX:	return _T("Invalid DAQ index");
			case H_ERROR_DAQSUPPORT_NODAQ:			return _T("No DAQ data to write to or invalid DAQ data");
			case H_ERROR_DAQSUPPORT_WRITE_DAQ:		return _T("Could not write the daq to the file (Disk full ?)");
			case H_ERROR_AUDIO_CANTCREATEFILE:		return _T("Invalid Audio file handle when trying to open for writing");
			case H_ERROR_AUDIO_NOAUD:				return _T("No audio data to write to or invalid audio");
			case H_ERROR_AUDIO_WRITE_AUD:			return _T("Could not write the audio to the DAQ file (Disk full ?)");
			case H_ERROR_AUDIO_INVALID_INDEX:		return _T("Invalid AUD index");
            case H_ERROR_OUT_OF_RANGE:              return _T("Out of range");
            case H_ERROR_NO_FILE:                   return _T("No file");
			case H_ERROR_AUDIO_INVALID_FORMAT:		return _T("Invalid Audio format");
			case H_ERROR_AUDIO_CHANNEL_MASK_MATCH:	return _T("Audio channel npot match with audio channel number");
			case H_ERROR_AUDIO_READ_FAILED:			return _T("Audio data reading failed");	
			case H_ERROR_H264_UNSUPPOT_IMAGE_SIZE:  return _T("Unsupported image size for H.264 encoding,Width should multiple 16 and height multiple 8");	
			case H_ERROR_H264_ENCODING:				return _T("H.264 encoding error.");	
			case H_ERROR_H264_DECODING:				return _T("H.264 decoding error.");	
			case H_ERROR_CREATE_SAMPLE_GRABBER:		return _T("Failed to create sample grabber.");
			case H_ERROR_SAMPLE_GRABBER_CALLBACK:	return _T("Failed to set sample grabber callback.");
			case H_ERROR_ADD_SAMPLE_GRABBER:		return _T("Failed to add sample grabber to the graph.");
			case H_ERROR_CONNECT_ASOURCE_ALEVEL:	return _T("Failed to connect audio source to audio level filter.");
			case H_ERROR_CONNECT_ALEVEL_ACODEC:		return _T("Failed to connect audio level to audio codec.");
			case H_ERROR_CONNECT_ALEVEL_MUX:		return _T("Failed to connect audio level to muxer.");
			case H_ERROR_NO_AUDIO_SOURCE:			return _T("No audio source present.");
			case H_ERROR_NO_RECORDING:				return _T("Currently not in recording mode.");
			case H_ERROR_NO_CAPTURE_GRAPH:			return _T("No capture graph created.");
			case H_ERROR_FAILED_TO_ADD_TAG:			return _T("Failed to add tag.");
			case H_ERROR_FRAME_SKIPPED:				return _T("The key frame not found,the frame skipped.");
			case H_ERROR_AVI_TAG_NOT_FOUND:			return _T("AVI tag not found.");
            case H_ERROR_REGISTRY_READ: 			return _T("An error occured trying to reading from the registry.");
            case H_ERROR_REGISTRY_WRITE: 			return _T("An error occured trying to writing to the registry.");
            case H_ERROR_CREATEC_UNSUPPORT_FORMAT:  return _T("Unsupported format. Createc compression only supports 8 bit mono or mono bayer format.");
            case H_ERROR_INVALID_LUT_FILE:          return _T("Invalid LUT file.");
            default :                           
            {
                TCHAR msg[100];
                _stprintf_s(msg, 100, _T("Hermes:Undocumented error %d"), code);
                OutputDebugString(msg);

                return _T("Sorry, this is an undocumented error, please report this to NorPix");
            }
        }
    }
};

#endif //HERRORMANAGER_H