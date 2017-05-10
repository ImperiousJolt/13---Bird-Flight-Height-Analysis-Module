/*==============================================================================
Copyright (C) 2004 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/
#if !defined(AFX_HERMESUTILS_H__9CCE4D98_24B6_4E18_9E87_096BC1CF2F79__INCLUDED_)
#define AFX_HERMESUTILS_H__9CCE4D98_24B6_4E18_9E87_096BC1CF2F79__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HEnums.h"
#include <windows.h>
#include <TCHAR.h>
#include "importexport.h"

HERMES_API LPCTSTR HImageFormatString(eHImageFormat format);

HERMES_API LPCTSTR HImageCompressionString(eHCompression compression);

HERMES_API bool IsFormatMono(eHImageFormat format);

HERMES_API void AbsoluteToRelative(
    long reference, unsigned short referenceMS, unsigned short referenceUS,
    long absolute, unsigned short absoluteMS, unsigned short absoluteUS, 
    unsigned long& relative, unsigned short& relativeMS, unsigned short& relativeUS);

HERMES_API void RelativeToAbsolute(
    long reference, unsigned short referenceMS, unsigned short referenceUS,
    unsigned long relative, unsigned short relativeMS, unsigned short relativeUS,
    long& absolute, unsigned short& absoluteMS, unsigned short& absoluteUS);

HERMES_API bool ComputeTimeDifference(long time1, unsigned short time1MS, unsigned short time1US,
    long time2, unsigned short time2MS, unsigned short time2US,
    long& diffTime, short& diffTimeMS, short& diffTimeUS, bool& time2IsGreater);

HERMES_API int CompareTimestamps(long time1, unsigned short time1MS, unsigned short time1US,
    long time2, unsigned short time2MS, unsigned short time2US);

HERMES_API void AddTimestampOffset(long& time, short& timeMS, short timeUS,
    long offset, short offsetMS, short offsetUS);

HERMES_API void CreateDirectoryRecursive(LPCTSTR filepath);

HERMES_API double ReadAVIFrameRate(LPCTSTR filePath);
HERMES_API void WriteAVIFrameRate(LPCTSTR filePath, double framerate);

HERMES_API bool IsSandyBridgeHardwarePresent();

#endif // !defined(AFX_HERMESUTILS_H__9CCE4D98_24B6_4E18_9E87_096BC1CF2F79__INCLUDED_)
