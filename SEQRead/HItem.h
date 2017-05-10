/*==============================================================================
Copyright (C) 2004 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#ifndef HITEM_H
#define HITEM_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>
#include "ImportExport.h"

class HERMES_API HItem  
{
private:
    int ID;
    LPTSTR Description;

public:    
    HItem();
    virtual ~HItem();
	HItem(const HItem& item);
    const HItem& operator=(const HItem& item);

    void SetItem(int id, LPTSTR desc);

    int GetID();
    LPCTSTR GetDescription();
};

#endif //HITEM_H
