/*==============================================================================
Copyright (C) 2012 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/
#pragma once

#include "ImportExport.h"
#include "HMetadata.h"
#include "HMetadataInfo.h"

class CHermesMetadataManager;

class HERMES_API HMetadataManager
{
private:
    CHermesMetadataManager* HermesMetadataManager;
    
public:
    HMetadataManager(void);
    virtual ~HMetadataManager(void);

    bool SetMetadataMaxSize(int sizeInBytes);
    int GetMetadataMaxSize();

    bool SetMetadataInfoSize(int sizeInBytes);
    int GetMetadataInfoSize();

    bool IsSequenceMetadataDynamic();
    bool SetSequenceMetadataDynamic(bool enable);

    bool RegisterMetadataType(HMetadataInfo* info);

    bool RegisterGenericTypes();

    bool RegisterNorPixTypes();
    
    int GetMetadataTypeCount();

    HMetadataInfo* GetMetadataTypeByIndex(unsigned int index);

    HMetadataInfo* GetMetadataTypeByID(unsigned int id);

    void RebuildMetadataString(HMetadata* metadata);
};