/*==============================================================================
Copyright (C) 2004 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/

#ifndef HERMES_H
#define HERMES_H

#include <atlbase.h>
#include <TCHAR.h>

//All the includes needed to run the hermes API
#include "HImage.h"         //An image in hermes format
#include "HGrabModule.h"    //The module for interfacing with the grabber
#include "HGrabCallbacks.h" //Callbacks used in the Grab Module
#include "HImageExporter.h" //Image file exporter
#include "HAviExporter.h"   //AVI file exporter (obsolete)
#include "HAviFile.h"       //AVI file manager
#include "HAviCodecs.h"
#include "HEnums.h"         //Enumerations and definitions shared between modules
#include "HItem.h"          //An item has an ID and a description
#include "HSequence.h"      //To read and write a sequence file
#include "HViewer.h"        //To display a HImage
#include "HFPSMonitor.h"    //To monitor the frame per second acquisition rate
#include "HErrorManager.h"  //To get the error string associated with an error code
#include "HermesUtils.h"    //Misc functions
#include "HBayerConverter.h"//To apply a bayer conversion on a mono image (obsolete)
#include "HImageConverter.h"//To convert an image to a different format
#include "HImageColorProcessing.h" //For bayer conversion & color balance
#include "HIODriver.h"      //To access an I/O port
#include "HVideoOutputDriver.h" //To access a video output driver
#include "HWhiteBalance.h"  //Compute and apply a white balance on an image
#include "HNetUtils.h"		//Network helper functions
#include "HTcpServer.h"		//Defines a TCP server
#include "HTcpClient.h"		//Defines a TCP client
#include "HUdpServer.h"		//Defines an UDP server
#include "HUdpClient.h"		//Defines an UDP client
#include "MetadataID.h"     //Unique identifiers for metadata
#include "HMetadata.h"      //The metadata class
#include "NpxMetadata.h"    //Native metadata classes
#include "HMetadataInfo.h"  //Metadata information
#include "HMetadataManager.h" //Metadata Manager

#endif