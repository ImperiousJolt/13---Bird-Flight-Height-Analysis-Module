/*==============================================================================
Copyright (C) 2004-2005 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/
#ifndef HLOCKER_H
#define HLOCKER_H

#include <windows.h>

class HLocker
{
private:
    /**The critical section object acting as a mutex.*/
    CRITICAL_SECTION CriticalSection;

public:
    //Initialize the critical section.
    HLocker() {InitializeCriticalSection(&CriticalSection);}
    
    //Release resources used by the critical section object.
    ~HLocker() {DeleteCriticalSection(&CriticalSection);}

    //Enter the critical sction (will block if section is already owned)
    void Lock() {EnterCriticalSection(&CriticalSection);}

    bool TryToLock() {return TryEnterCriticalSection(&CriticalSection) != 0;}

    //Release ownership of the critical section.
    void Unlock() {LeaveCriticalSection(&CriticalSection);}
};
//-----------------------------------------------------------------------------
class HAutoLocker
{
private:
    /**The critical section object acting as a mutex.*/
    CRITICAL_SECTION* CriticalSection;

public:
    //Initialize the critical section.
    HAutoLocker(CRITICAL_SECTION* section) 
    {
        CriticalSection = section;
        EnterCriticalSection(CriticalSection);
    }
    
    //Release resources used by the critical section object.
    ~HAutoLocker() 
    {
        LeaveCriticalSection(CriticalSection); 
    }
};



#endif