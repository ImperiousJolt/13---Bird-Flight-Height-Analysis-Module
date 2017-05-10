#pragma once

#include <atlbase.h>
#include <TCHAR.h>

#define HERMESCALL __stdcall

extern "C"
{
    typedef void (HERMESCALL *InputSupportCallback)
    (
	    int                 deviceIndex,//The index of the device
        int                 lineID,     //The line on which the event occurs
        eHInputEvent        event,      //The event that just occured
        bool*               continueMonitoring, //set to false to stop receiving events for this line
        ULONG_PTR			userData,   //Caller data
	    void*				userPtr     //Caller data
    );
}

