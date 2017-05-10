/*==============================================================================
Copyright (C) 2006 Norpix Inc.  All Rights Reserved.
Reproduction or disclosure of this file or its contents without the prior
written consent of Norpix Inc. is prohibited.

Administration    : ln@norpix.com
Technical Support : support@norpix.com
==============================================================================*/
#ifndef HENUMS_H 
#define HENUMS_H

//Don't add #include in this file

#define H_CHANNEL_LEFT 1
#define H_CHANNEL_RIGHT (1 << 1)
#define H_CHANNEL_STEREO (H_CHANNEL_LEFT | H_CHANNEL_RIGHT) 

enum eHSupportedModule
{
    //GRABBERS                      VALUE   DLL TO REGISTER             GRABBERS SUPPORTED      
    H_UNKNOWN                       = 0,    //-                         -
	H_ABSOFTWARE_ACTIVE_GIGE        = 120,  //NpxActiveGigE.dll         A&B Software GigE Vision cameras
    H_ACTIVESILICON_PHOENIX         = 86,   //NpxPhoenix.dll            Active Silicon Phoenix
    H_ANDOR_LUCA                    = 92,   //NpxAndor.dll              Andor Luca
    H_ANDOR_NEO                     = 132,  //NpxAndorNeo.dll           Andor Neo
    H_AVT_DCAM                      = 1,    //NpxAVT.dll                AVT DCAM FireGrab
    H_AVT_DCAM_UNI                  = 100,  //NpxAVTUNI.dll             AVT DCAM Uniform API
    H_AVT_UNIVERSAL                 = 112,  //NpxAVTUniversal.dll       AVT Universal API (AVT + Prosilica)
	H_AXIS                          = 124,  //NpxAxis.dll               Axis camera
    H_BASLER_IEEE1394               = 75,   //NpxBasler1394B.DLL        Basler Pylon IEEE1394 cameras
    H_BASLER_GIGE                   = 77,   //NpxBaslerGigE.DLL         Basler Pylon GigE cameras
    H_BASLER_BCAM                   = 2,    //NpxBasler.dll             Basler BCAM cameras (obsolete, use the pylondriver)
    H_BAUMER_FW                     = 90,   //NpxBaumerFW.dll           Baumer Firewire Camera
    H_BITFLOW_CL                    = 3,    //NpxBitFlow.dll            BitFlow (CL-Frame grabber)
    H_BLACK_MAGIC                   = 134,  //NpxBlackMagic.dll         Black Magic Design
    H_CCDDIRECT_MICROPIX            = 4,    //NpxMicroPix.dll           CCD Direct Micropix
    H_CMU_IEEE1394                  = 5,    //NpxIEEE1394.dll           DCAM Camera, Sony IEEE1394 camera
    H_COOKE_PCO                     = 6,    //NpxPco.dll                Cooke PCO
    H_COOKE_PIXELFLY                = 7,    //NpxPixelFly.dll           Cooke PixelFly
    H_COOKE_SENSICAM                = 8,    //NpxSensiCam.dll           Cooke Sensicam
    H_CORECO_BANDIT2CV              = 9,    //NpxBanditIICV.dll         Dalsa Bandit 2 CV
    H_CORECO_BANDIT2MV              = 10,   //NpxBanditIIMV.dll         Dalsa Bandit 2 MV
    H_CORECO_BANDIT2RGB             = 11,   //NpxBanditIIRGB.dll        Dalsa Bandit 2 RGB
    H_CORECO_GIGE                   = 85,   //NpxCorecoGigE.dll         Dalsa GigE Camera
    H_CORECO_VIPERDIG               = 12,   //NpxViperDig.dll           Dalsa Viper Digital
    H_CORECO_PCCAMLINK              = 13,   //NpxPcCamLink.dll          Dalsa PC-CAM link
    H_CORECO_PC2CAMLINK             = 14,   //NpxPc2CamLink.dll         Dalsa PC2-CAM link
    H_CORECO_PC2COMP                = 102,  //NpxPc2Comp.dll            Dalsa PC2-COMP
    H_CORECO_PC2VISION              = 15,   //NpxPC2Vision.dll          Dalsa PC2-Vision
    H_CORECO_X64                    = 16,   //NpxCorecoX64.dll          Dalsa X-64
	H_DATAPATH_VISIONRGB            = 113,  //NpxVisionRGB.dll          DataPath Vision RGB
    H_EMS_PHYNXRGB                  = 17,   //NpxPhynxRGB.dll           EMS Phynx RGB    
	H_EMS_XTREMERGB                 = 93,   //NpxVisionRGB.dll          EMS Xtreme RGB    
	H_EPIPHAN                       = 133,  //NpxEpiphan.dll            Epiphan    
    H_EPIX_D2X                      = 18,   //NpxEpixD2X.dll            Epix Digital family
    H_EPIX_SV5                      = 19,   //NpxEpixSV5.dll            Epix SV5
    H_EURESYS_GRABLINKVALUE         = 22,   //NpxGrabLink.dll           Euresys Grablink Series
    H_EURESYS_IOTA                  = 23,   //NpxIota.dll               Euresys Domino Series
    H_EURESYS_PICOLO                = 24,   //NpxPicolo.dll             Euresys Picolo Series
	H_PICOLO_H264_V16               = 114,  //NpxPicoloV16.dll          Euresys Picolo H264 V16
	H_PICOLO_H264_UX				= 122,  //NpxPicoloUx.dll           Euresys Picolo H264 Ux
    H_FCAV_ARINC818                 = 97,   //NpxFCAV.dll               FCAV ARINC 818 Family
    H_FOCULUS_CAMERA                = 25,   //NpxFOculus.dll            Foculus Firewire Camera
    H_FORESIGHTIMAGING_ACCUSTREAM   = 87,   //NpxAccuStream.dll         Foresight Imaging AccuStream
    H_GEVICAM                       = 99,   //NpxGEViCAM.dll            GEViCAM Camera Family
	H_GIGALINX                      = 115,  //NpxGigaLinx.dll           GigaLinx Camera Family
	H_GIGALINX_SONY                 = 117,  //NpxGigaLinx.dll           Sony GigE Vision
    H_GRT_MATRIX                    = 103,  //NpxGRTMatrix.dll          Great River Matrix Family
    H_GRT_MATRIX_HL2V               = 125,  //NpxGRTMatrixHL2V.dll      Great River Matrix Hotlink Family
    H_HAMAMATSU_DCAM                = 26,   //NpxHamamatsu.dll          Hamamatsu DCAM                            
    H_HASOTEC_FG30                  = 27,   //NpxHaSoTec.dll            Hasotec FG30                              
    H_HITACHI_DCAM                  = 28,   //NpxHitachiDCAM.dll        Hitachi DCAM Family 
    H_HL2V                          = 98,   //NpxHL2v.dll               Hotlink Card
	H_IDS_UEYE                      = 83,   //NpxIDSUEye.dll            IDS U-Eye Family
    H_IMITECH_1394                  = 89,   //NpxIMI1394.dll            Imi Tech 1394 camera
	H_IMITECH_GIGE					= 116,  //NpxIMIGigE.dll			Imi Tech GigE camera
	H_IMPERX_BOBCAT_GIGE            = 138,  //NpxGEViCAM.dll            ImperX Bobcat GigE
    H_IMPERX_FRAMELINK              = 29,   //NpxFrameLink.dll          ImperX Frame Link
	H_IMPERX_FRAMELINK_EXPRESS      = 105,  //NpxImperxLink.dll         ImperX Frame Link Express
	H_IMPERX_VCE_EXPRESS			= 127,  //NpxVCEExpress.dll         ImperX VCE Express
	H_IMPERX_SDI_EXPRESS            = 106,	//NpxSDIExpress.dll         ImperX HD SDI Express	
    H_IMPERX_GIGE                   = 84,   //NpxGigE.dll               ImperX GigE
    H_IMPERX_VCEPRO                 = 30,   //NpxVCEPro.dll             ImperX VCE Pro
    H_INTEGRAL_FLASHBUSDX           = 31,   //NpxFlashBusDX.dll         Integral Technology Flashbus DX Family    
    H_INTEGRAL_FLASHBUSMV           = 32,   //NpxFlashbus.dll           Integral Technology Flashbus MV Family    
    H_INTEGRAL_FLASHBUSMX           = 33,   //NpxFlashBusMX.dll         Integral Technology Flashbus MX Family    
	H_INTEGRAL_SPECTRIM             = 34,   //NpxSpectrim.dll           Integral Technology Spectrim
    H_ISG_1394                      = 21,   //NpxISG1394.dll            Imaging Solutions Group 1394 cameras
    H_JAIGENICAM_GIGE               = 91,   //NpxJAI.dll                Jai GeniCam GigE
   	H_JAIPULNIX_GIGE                = 74,   //NpxGigE.dll               Jai/Pulnix GigE
    H_JENOPTIK_PROGRESC10           = 35,   //NpxProgResC10.dll         Jenoptik ProgRes C10
    H_JENOPTIK_PROGRESCXX           = 36,   //NpxProgResXX.dll          Jenoptik ProgRes C10/C12/C14/M14 Plus
    H_JENOPTIK_PROGRESC14           = 37,   //NpxProgResC14.dll         Jenoptik ProgRes C14
    H_KAPPA_FW                      = 101,  //NpxKappaFW.dll            Kappa Firewire Camera
    H_LEUTRON_PICSIGHT_GIGE         = 78,   //NpxPicSight.dll           Leutron PicSight GigE
	H_LEUTRON_SIMPLON_GIGE          = 128,  //NpxLeutronSimplon.dll     Leutron Simplon GigE
    H_LUMENERA_GIGE                 = 121,  //NpxLumenera.dll           Lumenera (GigE family)
    H_LUMENERA_USB2                 = 38,   //NpxLumenera.dll           Lumenera (USB 2.0 family)
    H_MATRIXVISION_BLUECOUGAR       = 95,   //NpxBlueCOUGAR.dll         Matrix Vision BlueCOUGAR GigE camera
    H_MATRIXVISION_BLUEFOX          = 39,   //NpxBlueFOX.dll            Matrix Vision BlueFOX USB camera
	H_MATRIXVISION_HYPERION         = 107,  //NpxHyperion.dll           Matrix Vision Hyperion (Digital) Frame Grabber
	H_MATRIXVISION_SIGMA            = 108,  //NpxSigma.dll              Matrix Vision Sigma (Analogue) Frame Grabber
	H_MATRIXVISION_TITAN            = 109,  //NpxTitan.dll              Matrix Vision Titan (Analogue) Frame Grabber
    H_MATROX_HELIOS                 = 40,   //NpxHelios.dll             Matrox Helios                             
    H_MATROX_METEOR2_CL             = 41,   //NpxMtxM2CL.dll            Matrox Meteor 2 Camera link               
    H_MATROX_METEOR2_DIG            = 42,   //NpxMtxM2Dig.dll           Matrox Meteor 2 Digital                   
    H_MATROX_METEOR2_MC             = 43,   //NpxMtxM2MC.dll            Matrox Meteor 2 Multi-Channel             
    H_MATROX_METEOR2_STD            = 44,   //NpxMtxM2STD.dll           Matrox Meteor 2 Standard                  
    H_MATROX_MORPHIS                = 20,   //NpxMtxMorphis.dll         Matrox Morphis
    H_MATROX_RADIENT                = 130,  //NpxRadient.dll            Matrox Radient eCL
    H_MATROX_SOLIOS_XCL             = 45,   //NpxSolios.dll             Matrox Solios XCL
    H_MATROX_ODYSSEY                = 46,   //NpxOdyssey.dll            Matrox Odyssey                            
    H_MATROX_ORION                  = 135,  //NpxOrion.dll              Matrox Orion
    H_MATROX_VIO_XCL                = 94,   //NpxVIO.dll                Matrox VIO XCL
    H_MIGHTEX                       = 110,  //NpxMightex.dll            Mightex CMOS buffered camera
	H_MIGHTEX_CCD                   = 126,  //NpxMightexCCD.dll         Mightex CCD area camera
	H_NET_ICUBE                     = 129,  //NpxICube.dll              NET iCube USB cameras
    H_NI_GRABBERS_0                 = 47,   //NpxNI1429.dll             National Instruments Frame Grabbers   
    H_NORPIX_VIRTUAL                = 49,   //NpxVirtual.dll            Norpix Virtual Grabber                    
    H_OLYMPUS_DP70                  = 50,   //NpxDP70.dll               Olympus DP-70
	H_ONVIF							= 131,	//NpxONVIF.DLL				Onvif standard cameras
    H_OPTRONICS_MACROFIRE           = 51,   //NpxMacroFire.dll          Optronics MacroFire                       
    H_OPTRONICS_MAGNAFIRE           = 52,   //NpxMagnafireSP.dll        Optronics Magnafire SP                     
    H_OPTRONICS_MICROFIRE           = 53,   //NpxMicroFire.dll          Optronics Microfire                       
    H_PIXELINK_PLA500               = 54,   //NpxPLA500.dll             Pixelink PL-A544 analog converter         
    H_PIXELINK_PLA600               = 55,   //NpxPLA600.dll             Pixelink PL-A6XX family                   
    H_PIXELINK_PLA700               = 56,   //NpxPLA700.dll             Pixelink PL-A7XX family                   
    H_PIXELINK_TM1020               = 57,   //NpxTM1020.dll             Pixelink TM-1020 camera                   
    H_PIXELINK_VCA1281              = 58,   //NpxVCA1281.dll            Pixelink VCA-1281 camera                  
    H_PIXERA_PENGUIN                = 59,   //NpxPenguin600CL.dll       Pixera Penguin Family                     
    H_PLEORA_PT1000CL               = 60,   //NpxPleora.dll             Pleora PT1000-CL (& other iPORT)         
    H_PLEORA_MASTER                 = 61,
    H_PLEORA_SLAVE                  = 62,                                                         
    H_PRINCETON                     = 111,  //NpxPrinceton.dll          Princeton Instruments Cameras
    H_PROSILICA                     = 63,   //NpxProsilica.dll          Prosilica Firewire camera
    H_PROSILICA_GIGE                = 64,   //NpxProsilicaGigE.dll      Prosilica GigE camera
	H_PTGREY                        = 119,  //NpxPTGrey.dll             Point Grey Research 2.x Firewire	
    H_PTGREY_FLYCAPTURE             = 65,   //NpxDragonFly.dll          Point Grey Research 1.x (firewire)
    H_QIMAGING_MP                   = 66,   //NpxQImagingMP.dll         QImaging MicroPublisher                   
    H_QIMAGING_RETIGA               = 67,   //NpxQImaging.dll           QImaging Retiga, QICAM & Rolera lines                     
    H_REDLAKE_MEGAPLUSII            = 68,   //NpxMegaPlusII1394.dll     RedLake MegaPlus II 1394 camera
    H_ROPER_CASCADE                 = 69,   //NpxCoolSnapCF.dll         Roper Cascade                             
    H_ROPER_COOLSNAPCF              = 70,   //NpxCoolSnapCF.dll         Roper CoolSnap CF                         
    H_SBF_FIREWIRE                  = 71,   //NpxSBFocal.dll            Santa Barbara Focal Plane (any)
    H_SCION_CFW                     = 72,   //NpxScion.dll              Scion CFW 1312C/1310C/1308C/1312M/1310M/1308M
	H_SILICONSOFTWARE_MICROENABLE   = 123,  //NpxMicroEnable.dll        Silicon Software MicroEnable (CL-Frame grabber)
    H_SILLICONIMAGING_GIGE          = 73,   //NpxGigE.dll               Sillicon Imaging GigE	
    H_SPOT                          = 76,   //NpxSpot.dll               SPOT Insight *** to be changed to H_SPOT
    H_SUMIX_12A2                    = 96,   //NpxSumix12A2.dll          Sumix 12A2 GigE Camera
    H_SUMIX_150                     = 79,   //NpxSumix150.dll           Sumix 150 USB Camera
    H_SUMIX_M7X                     = 80,   //NpxSumixM7x.dll           Sumix M7X USB Camera
	H_SUMIX_M8X                     = 88,   //NpxSumixM8x.dll           Sumix M8X USB Camera    
    H_SVS_VISTEK_GIGE               = 104,  //NpxSVSGigE.dll            SVS Vistek GigE camera
    H_TATTILE_DUPLEX                = 118,  //NpxTattileDuplex.dll      Tattile Duplex
    H_WDM_CAMERA                    = 82,   //NpxWDMCamera.dll          DirectShow compatible capture device                          
    H_XCELERA                       = 136,  //NpxXcelera.dll            Dalsa Xcelera/X64
    H_XIMEA                         = 137,  //NpxXimea.dll              XIMEA USB Camera
    H_IP_CAMERA                     = 139,  //NpxIPCamera.dll           IP Web compatible Camera

	//VALUE is used for backward compatiblity.  New grabbers are inserted 
    //alphabeticaly in the enum but we want their value to be constant.
    //Next Unused value : 140
};
//-----------------------------------------------------------------------------
enum eHJpegQuality
{
    H_JPEG_DEFAULT,             //Default compression algorythm
    H_JPEG_FAST,                //Fast compression algorythm
    H_JPEG_ACCURATE,            //Accurate compression algorythm
    H_JPEG_QUALITYSUPERB,       //Superb quality, slowest encoding speed
    H_JPEG_QUALITYGOOD,         //Good quality, slower encoding speed
    H_JPEG_QUALITYNORMAL,       //Normal quality
    H_JPEG_QUALITYAVERAGE,      //Average quality, fast encoding speed
    H_JPEG_QUALITYBAD           //Bad quality, fastest encoding speed
};
//-----------------------------------------------------------------------------
enum eHImageFormat
{
    H_IMAGE_UNKNOWN = 0,        //Unknown format
    
    //The following formats are supported by HImage::ReallocateImage()
    H_IMAGE_MONO = 100,         //Monochrome Image (LSB)
    H_IMAGE_MONO_BAYER = 101,   //Raw Bayer Image (treated as H_IMAGE_MONO)
    H_IMAGE_BGR = 200,          //BGR Color Image
    H_IMAGE_PLANAR = 300,       //Planar Color Image
    H_IMAGE_RGB = 400,          //RGB Color Image
    H_IMAGE_BGRx = 500,         //BGRx Color Image
	H_IMAGE_YUV422 = 600,       //YUV422
	H_IMAGE_YUV422_20 = 610,
	H_IMAGE_YUV422_PPACKED_10 = 620,
	H_IMAGE_UVY422 = 700,       //UVY422
	H_IMAGE_UVY411 = 800,       //UVY411
	H_IMAGE_UVY444 = 900,       //UVY444

	H_IMAGE_BGR555_PACKED			= 905,	// PhynxRGB
	H_IMAGE_BGR565_PACKED           = 906,

    H_IMAGE_MONO_MSB		        = 112,   // Only for > 8 bit per pixel, MSB align litle endian 10 bit: JIHGFEDC BA000000 
    H_IMAGE_MONO_BAYER_MSB	        = 113,   // Only for > 8 bit per pixel, MSB align
    H_IMAGE_MONO_MSB_SWAP        	= 114,   // Only for > 8 bit per pixel, MSB align big endian 10 bit: BA000000 JIHGFEDC
    H_IMAGE_MONO_BAYER_MSB_SWAP    	= 115,	 // Only for > 8 bit per pixel, MSB align

    H_IMAGE_BGR10_PPACKED           = 123,   // Only for  10 bit per pixel, LSB align
    H_IMAGE_BGR10_PPACKED_PHOENIX 	= 124,   // Only for  10 bit per pixel, LSB align, RRRRRRRR RR00GGGG GGGGGGBB BBBBBBBB
    H_IMAGE_RGB10_PPACKED_PHOENIX 	= 125,   // Only for  10 bit per pixel, LSB align, BBBBBBBB BB00GGGG GGGGGGRR RRRRRRRR

    H_IMAGE_MONO_PPACKED	        = 131,   // Only for > 8 bit per pixel, MSB align
    H_IMAGE_MONO_BAYER_PPACKED      = 132,   // Only for > 8 bit per pixel, MSB align

	H_IMAGE_MONO_PPACKED_8448	    = 133,   // Only for > 8 bit per pixel, MSB align
    H_IMAGE_MONO_BAYER_PPACKED_8448 = 134,   // Only for > 8 bit per pixel, MSB align

    H_IMAGE_GVSP_BGR10V1_PACKED       =135,	//Only for  10 bit per pixel(From Gige Vision)BBBBBBBB GGGGGGGG RRRRRRRR 00BBGGRR
	H_IMAGE_GVSP_BGR10V2_PACKED       =136,  //Only for  10 bit per pixel(From Gige Vision)00BBBBBB BBGGGGGG GGGGRRRR RRRRRRRR 

    H_IMAGE_BASLER_VENDOR_SPECIFIC	= 1000,
	H_IMAGE_EURESYS_JPEG			= 1001,
    H_IMAGE_ISG_JPEG                = 1002,
    H_IMAGE_PHOTON_FOCUS_DR         = 1003, //Photon Focus GigE double rate format
    H_IMAGE_MONO_PPACKED_PCO 	    =910,
    H_IMAGE_MONO_PPACKED_PCO_BAYER 	=920,
};
//-----------------------------------------------------------------------------
enum eHCompression
{//IMPORTANT : Keep in synch with eCOMPRESSION in ImageFormat.h (ImageLib)
    H_COMPRESSION_NONE=0,
    H_COMPRESSION_JPEG=1,             //JPEG compressed images
    H_COMPRESSION_RLE=2,              //RLE compressed images (stp3 algo)
    H_COMPRESSION_HUFFMAN=3,          //HUFFMAN compressed images (stp3 algo)
    H_COMPRESSION_LZ=4,               //LZ compressed images (stp3 algo)
    H_COMPRESSION_RLE_FAST=5,         //RLE Fast compressed images (ippwrapper)
    H_COMPRESSION_HUFFMAN_FAST=6,     //HUFFMAN  Fast compressed images (ippwrapper)
    H_COMPRESSION_LZ_FAST=7,          //LZ Fast compressed images (ippwrapper)
	H_COMPRESSION_H264=8,             //H264 compressed images
    H_COMPRESSION_WAVELET=9,          //Wavelet compressed images
    H_COMPRESSION_CREATEC_FLAT_1D = 10,                 //Flat model predictor using 1 sample  for Createc Bayer compressed images.
    H_COMPRESSION_CREATEC_FLAT_2D = 11,                 //Flat model predictor using 2 samples for Createc Bayer compressed images
    H_COMPRESSION_CREATEC_FLAT_BLUE_VECTOR_1D = 12,     //Gradient predictor using the blue channel for Createc Bayer compressed images
    H_COMPRESSION_CREATEC_GREEN_AVERAGE = 13,           //Gradient predictor using the green channel average for Createc Bayer compressed images
    H_COMPRESSION_CREATEC_2D_LOSSY = 14,                 //Flat_2D but with a reduced symbol set, Lossy codec with a maximum error of 1 for Createc Bayer compressed images
    H_COMPRESSION_CREATEC_FLAT_2D_SSE  = 15             //SSE2 implementation of Flat_2D for Createc Bayer compressed images
};
//-----------------------------------------------------------------------------
enum eHDescriptionFormat
{
    H_UNICODE_FORMAT = 0,
    H_MBCS_FORMAT = 1,
    H_BYTE_FORMAT = 2
};
//-----------------------------------------------------------------------------
enum eHProtectionStatus
{
    H_PROTECTION_NONE = 0,
    H_PROTECTION_VALID,
    H_PROTECTION_INVALID
};
//-----------------------------------------------------------------------------
enum HTimeSourceSyncStatus
{
	H_SYNC_STATUS_UNSUPPORTED = 0,
	H_SYNC_STATUS_UNKOWN,
    H_SYNC_STATUS_FREERUN,
    H_SYNC_STATUS_SYNCHRONIZED,
	H_SYNC_STATUS_HOLDOVER
};
//-----------------------------------------------------------------------------
enum eHBayerSampleFactor
{
    H_BAYER_SAMPLEFACTOR_1 = 1,
    H_BAYER_SAMPLEFACTOR_2 = 2,
    H_BAYER_SAMPLEFACTOR_4 = 4,
    H_BAYER_SAMPLEFACTOR_8 = 8
};
//-----------------------------------------------------------------------------
enum eHBayerPatternOrigin
{
	H_BAYER_PATTERNORIGIN_GB = 0,
	H_BAYER_PATTERNORIGIN_GR,
	H_BAYER_PATTERNORIGIN_B,
	H_BAYER_PATTERNORIGIN_R
};
//-----------------------------------------------------------------------------
enum eHBayerCalculationMode
{
    H_BAYER_CALCMODE_FAST = 0,
    H_BAYER_CALCMODE_ACCURATE,
    H_BAYER_CALCMODE_LAPLACIAN1,
    H_BAYER_CALCMODE_LAPLACIAN2,
    H_BAYER_CALCMODE_IPP
};
//-----------------------------------------------------------------------------
enum eHColorBalanceAlgorithm
{
    H_COLBALALGO_MEAN_EQUALIZATION = 0,
    H_COLBALALGO_GRAY_WORLD,
    H_COLBALALGO_STANDARD_DEVIATION,
    H_COLBALALGO_MEAN_AND_STANDARD_DEVIATION,
	H_COLBALALGO_IRIDAS_1D,
	H_COLBALALGO_IRIDAS_3D_FAST,
    H_COLBALALGO_IRIDAS_3D_NORMAL,
	H_COLBALALGO_PRE_DEFINED
};
//-----------------------------------------------------------------------------
enum eHInputEvent
{
    H_INPUT_EVENT_FALLING_EDGE = 0,
    H_INPUT_EVENT_RISING_EDGE
};
//-----------------------------------------------------------------------------
enum eHInputLevel
{
    H_INPUT_LEVEL_LOW = 0,
    H_INPUT_LEVEL_HIGH,
    H_INPUT_LEVEL_UNDEFINED
};
//-----------------------------------------------------------------------------
enum eHOutputLevel
{
    H_OUTPUT_LEVEL_LOW = 0,
    H_OUTPUT_LEVEL_HIGH,
    H_OUTPUT_LEVEL_UNDEFINED
};
//-----------------------------------------------------------------------------
enum eHVideoCodec
{
    H_CODEC_UNKNOWN = 0,
    H_CODEC_CINEFORM_RAW,
	H_CODEC_CINEFORM_HD,
	H_CODEC_H264,
	H_CODEC_NPXJ,
	H_CODEC_NPXH
};
//-----------------------------------------------------------------------------
enum eHSpecialCopyFormat
{
    H_SPECIAL_COPY_NONE = 0,
    H_SPECIAL_COPY_ISGJPEG,
    H_SPECIAL_COPY_YUV422,
	H_SPECIAL_COPY_UVY422,
	H_SPECIAL_COPY_YUV411,
	H_SPECIAL_COPY_YUV444,
	H_SPECIAL_COPY_RG30,
    H_SPECIAL_COPY_RG48,
    H_SPECIAL_COPY_BYR1,
	H_SPECIAL_COPY_BYR2,
    H_SPECIAL_COPY_BYR4,
    H_SPECIAL_COPY_Y16,
	H_SPECIAL_COPY_Y8,
	H_SPECIAL_COPY_BGR555,
	H_SPECIAL_COPY_BGR565,
	H_SPECIAL_COPY_BGRA,
	H_SPECIAL_COPY_H264
};
//-----------------------------------------------------------------------------
enum eAdvanceSettingsLevel
{
    H_ADVANCE_LEVEL_BEGINNER = 0,
    H_ADVANCE_LEVEL_EXPERT = 1,
    H_ADVANCE_LEVEL_GURU = 2
};
//-----------------------------------------------------------------------------
enum eAdvanceSettingsFeatureType
{
    H_ADVANCE_ENUMERATION = 0, 
    H_ADVANCE_INTEGER_VALUE,
    H_ADVANCE_DOUBLE_VALUE,
    H_ADVANCE_BOOL_VALUE,
    H_ADVANCE_COMMAND,
    H_ADVANCE_OTHERS = 100
};
//-----------------------------------------------------------------------------
enum eFastColorCorrectionMode
{
	H_FAST_CORRECTION_NONE = 0,
	H_FAST_CORRECTION_MANUAL,
	H_FAST_CORRECTION_AUTO
};
//-----------------------------------------------------------------------------
enum eHMovieMode
{
    H_MOVIE_UNDEFINED = 0,
    H_MOVIE_RECORDING,
    H_MOVIE_PLAYBACK
};
//-----------------------------------------------------------------------------
enum eHAviPlaybackFormat
{
    H_AVI_PLAYBACK_NATIVE = 0,
    H_AVI_PLAYBACK_BGR,
    H_AVI_PLAYBACK_BGRX
};
//-----------------------------------------------------------------------------
enum eHRotationInterpolationMode
{
    H_ROTATION_INTER_NN = 0,
    H_ROTATION_INTER_LINEAR,
    H_ROTATION_INTER_CUBIC
};
//-----------------------------------------------------------------------------
enum eHResizeInterpolationMode
{
    H_RESIZE_INTER_NN = 0,
    H_RESIZE_INTER_LINEAR,
    H_RESIZE_INTER_CUBIC,
	H_RESIZE_INTER_LANCZOS,
	H_RESIZE_INTER_SUPER
};
//-----------------------------------------------------------------------------
enum eHMotionDetectionMode
{
    H_MOTION_DETECTION_MEAN = 0,
    H_MOTION_DETECTION_ABS_DIFF,
    H_MOTION_DETECTION_EDGE,
    H_MOTION_DETECTION_EDGE_ADAPTIVE
};
//-----------------------------------------------------------------------------
enum eHSolbelMode
{
    H_SOLBEL_VERTICAL = 0,
    H_SOLBEL_HORIZONTAL,
    H_SOLBEL_BOTH
};
//-----------------------------------------------------------------------------
enum eMonoToPseudoColorLUT
{
	H_MONO_TO_PSEUDO_COLOR_DISABLED = -1,
	H_MONO_TO_PSEUDO_COLOR_LUT_RAINBOW,
	H_MONO_TO_PSEUDO_COLOR_LUT_INVERTED_RAINBOW,
	H_MONO_TO_PSEUDO_COLOR_LUT_HOT,
	H_MONO_TO_PSEUDO_COLOR_LUT_COLD,
	H_MONO_TO_PSEUDO_COLOR_LUT_NEGATIVE
};
//-----------------------------------------------------------------------------
enum eHGRABBER_NOTIFICATION
{
    H_GRABBER_NOTIFICATION_CONNECTION_LOST = 0,
	H_GRABBER_NOTIFICATION_INVALID_SIGNAL,
	H_GRABBER_NOTIFICATION_SIGNAL_PRESENT,
	H_GRABBER_NOTIFICATION_CONNECTED,
	H_GRABBER_NOTIFICATION_DISCONNECTED,
    H_GRABBER_NOTIFICATION_CAPTURE_ERROR,
    H_GRABBER_NOTIFICATION_HARDWARESETTING_MISSING
};
//-----------------------------------------------------------------------------
enum eHMirror_Mode
{
	H_MIRROR_HORZ = 0,
    H_MIRROR_VERT,
    H_MIRROR_BOTH
};
//-----------------------------------------------------------------------------
enum eHMerge_Mode
{
	H_MERGE_HORZ = 0,
    H_MERGE_VERT
};
//-----------------------------------------------------------------------------
enum eHSUGGESTED_ACTION
{
    H_SUGGESTED_ACTION_NONE = 0,
	H_SUGGESTED_ACTION_RELOAD_GRABBER,
	H_SUGGESTED_ACTION_UNLOAD_GRABBER,
    H_SUGGESTED_ACTION_PAUSE_STREAM,
	H_SUGGESTED_ACTION_RESUME_STREAM,
	H_SUGGESTED_ACTION_RESTART_STREAM,
    H_SUGGESTED_ACTION_OPEN_HARDWARESETTINGDLG
};
//-----------------------------------------------------------------------------
enum eAudioFileFormat
{
	H_AUDIO_FILE_AUD_PCM = 0,
	H_AUDIO_FILE_BWAVE_PCM
};
//-----------------------------------------------------------------------------
enum eAudFileMode
{
	H_AUD_FILE_AUD_BLOCK = 0,
	H_AUD_FILE_BWAVE_CONTINOUS
};
//-----------------------------------------------------------------------------
enum eHAudioFormat
{
	H_AUDIO_UNKNOWN = 0,
	H_AUDIO_INT_MSB_PLANER_PCM = 100,
	H_AUDIO_INT_PLANER_PCM = 110,
	H_AUDIO_FLOAT_MSB_PLANER_PCM = 120,
	H_AUDIO_FLOAT_PLANER_PCM = 130,
	H_AUDIO_INT_PACKED_PCM = 140,
	H_AUDIO_UINT_PACKED_PCM = 150,
	H_AUDIO_FLOAT_PACKED_PCM = 160
};
//-----------------------------------------------------------------------------
enum eHAudioPlayEventCode
{
	H_AUDIO_READ_FAILED = 0,
	H_AUDIO_UNSUPPORTED_FORMAT,
	H_AUDIO_SAMPLE_BUFFER_CHANGED
};
//-----------------------------------------------------------------------------
enum eHExportFormat
{
    H_EXPORT_BMP = 0,
    H_EXPORT_JPG,
    H_EXPORT_TIFF,
    H_EXPORT_PNG,
    H_EXPORT_FIT,
    H_EXPORT_JP2,
    H_EXPORT_DPX,
    H_EXPORT_AVI,
    H_EXPORT_SEQ,
    H_EXPORT_MOV
};
//-----------------------------------------------------------------------------
enum eHMetadataFormat
{
    H_METADATA_UNKNOWN = 0,
    H_METADATA_BOOL,    //bool (1 byte)
    H_METADATA_BYTE,    //byte (1 byte)
    H_METADATA_SHORT,   //short (2 bytes)
    H_METADATA_USHORT,  //unsigned short (2 bytes)
    H_METADATA_INT,     //int (4 bytes)
    H_METADATA_UINT,    //unsigned int (4 bytes)
    H_METADATA_DOUBLE,  //double (8 bytes)
    H_METADATA_STRING,  //wchar_t[] (variable)
    H_METADATA_BINARY   //BYTE[] (variable)
};
//-----------------------------------------------------------------------------
enum eHErrorCode
{
    H_ERROR_SUCCESS = 0,
    H_ERROR_NOAUTHORIZATION,
    H_ERROR_FAILEDREGISTER,
    H_ERROR_EXPORT_IN_PROGRESS,
    H_ERROR_INVALID_COMPRESSION,
    H_ERROR_NO_BEGINEXPORT,
    H_ERROR_NO_IMAGE_DATA,
    H_ERROR_INVALID_DIGIT,
    H_ERROR_NO_GRABMAN,
    H_ERROR_INI_FAIL,
    H_ERROR_CREATE_BUFFER,
    H_ERROR_BUFFER_INTERNAL,
    H_ERROR_NO_GRABBER,
    H_ERROR_CONVERT_BGR24,
    H_ERROR_CONVERT_BGRX,
    H_ERROR_CONVERT_UNSUPPORTED,
    H_ERROR_CONVERT_YUV422,
	H_ERROR_CONVERT_UVY422,
	H_ERROR_CONVERT_UVY411,
	H_ERROR_CONVERT_UVY444,
	H_ERROR_CREATE_SYSTEM_ENUM,
    H_ERROR_CREATE_CLASS_ENUM,
    H_ERROR_MONIKER_NULL, 
    H_ERROR_LOADING_VIDEO_CODEC,
    H_ERROR_LOADING_AUDIO_SOURCE,
    H_ERROR_LOADING_AUDIO_CODEC,
    H_ERROR_NO_CODEC_SETTINGS,
    H_ERROR_CREATE_GRAPH_BUILDER,
    H_ERROR_CREATE_CAPTURE_BUILDER,
    H_ERROR_CREATE_FEEDER,
    H_ERROR_ADD_FEEDER,
    H_ERROR_ADD_VCODEC,
    H_ERROR_ADD_ACODEC,
    H_ERROR_ADD_AUDIO_SOURCE,
    H_ERROR_ADD_MUX_FILE,
    H_ERROR_CONNECT_VSOURCE_VCODEC,
    H_ERROR_CONNECT_VCODEC_MUX,
    H_ERROR_CONNECT_VSOURCE_MUX,
    H_ERROR_CONNECT_ASOURCE_ACODEC,
    H_ERROR_CONNECT_ACODEC_MUX,
    H_ERROR_CONNECT_ASOURCE_MUX,
    H_ERROR_CONNECT_SOURCE_SPLITTER,
    H_ERROR_CONNECT_SPLITTER_RENDERER,
    H_ERROR_SYNCH_SOURCE,
    H_ERROR_INTERLEAVE_MODE,
    H_ERROR_INTERLEAVE_TIME,
    H_ERROR_SEQ_CANTCREATEFILE,
    H_ERROR_NOSEQ,
    H_ERROR_WRITE_SEQ,
    H_ERROR_SEQ_INVALIDMAGICNUMBER,
    H_ERROR_SEQ_WRONGHEADERSIZE,
    H_ERROR_SEQ_INVALIDLENGTH,
    H_ERROR_SEQ_INVALIDFRAMERATE,
    H_ERROR_SEQ_INVALIDDATA,
    H_ERROR_SEQ_INVALIDWIDTH,
    H_ERROR_SEQ_INVALIDHEIGHT,
    H_ERROR_SEQ_INVALIDDEPTH,
    H_ERROR_SEQ_INVALIDIMAGESIZE,
    H_ERROR_SEQ_UNSUPPORTED_FORMAT,
    H_ERROR_SECTORBYTES_ZERO, 
    H_ERROR_FILENOTFOUND,
    H_ERROR_CANTCREATEFILE,
    H_ERROR_INVALID_INDEX,
    H_ERROR_OUTOFMEMORY,
    H_ERROR_IMAGEFORMATCHANGED,
    H_ERROR_TOOMUCHDATA,
    H_ERROR_GDIDRAW,
    H_ERROR_SCRIPTRUNNING,
    H_ERROR_IMAGE_FORMAT,
    H_ERROR_SCRIPTER_NOT_RUNNING,
    H_ERROR_STOP_PLAYBACK,
    H_ERROR_STREAMING,
    H_ERROR_DONTSUPPORTREWRITE,
    H_ERROR_UNSUPPORTED,
    H_ERROR_UNSUPPORTED_SETTINGS,
    H_ERROR_UNSUPPORTED_ADJUSTMENTS,
    H_ERROR_NOCOMPORT,
    H_ERROR_EXPORT_FAILED,
    H_ERROR_INPUTSUPPORT_LOAD,
    H_ERROR_OUTPUTSUPPORT_LOAD,
    H_ERROR_VIDEOOUTPUTSUPPORT_LOAD,
    H_ERROR_H264_ENCODE,
    H_ERROR_H264_DECODE,
    H_ERROR_UNSUPPORTED_ADVANCEFEATURE,
    H_ERROR_NOBITMAP,
    H_ERROR_QUICKTIME_INIFAIL,
    H_ERROR_WRONG_MODE,
    H_ERROR_QUICKTIME_ERROR,
    H_ERROR_ROTATION_ERROR,
	H_ERROR_MIRROR_ERROR,
	H_ERROR_RESIZE_ERROR,
    H_ERROR_MOTION_ERROR,
	H_ERROR_MERGE_ERROR,
    H_ERROR_PARAM_NOT_SUPPORTED,
	H_ERROR_INPUTSUPPORT_DEV_INIT_FAILED,
	H_ERROR_INPUTSUPPORT_DEV_UNINIT_FAILED,
	H_ERROR_INPUTSUPPORT_MONITOR,
	H_ERROR_OUTPUTSUPPORT_DEV_INIT_FAILED,
	H_ERROR_OUTPUTSUPPORT_DEV_UNINIT_FAILED,
    H_ERROR_ADD_FILEREADER,
    H_ERROR_ADD_AVISPLITTER,
    H_ERROR_CREATE_RENDER,
	H_ERROR_PULSEGENSUPPORT_LOAD,
	H_ERROR_PULSEGENSUPPORT_DEV_INIT_FAILED,
	H_ERROR_PULSEGENSUPPORT_DEV_UNINIT_FAILED,
	H_ERROR_PULSEGENSUPPORT_START_FAILED,
	H_ERROR_PULSEGENSUPPORT_STOP_FAILED,
    H_ERROR_NO_PROCESSING_APPLIED,
    H_ERROR_COLOR_BALANCING,
    H_ERROR_BAYER_CONVERSION,
	H_ERROR_DAQSUPPORT_LOAD,
	H_ERROR_DAQSUPPORT_INIT_FAILED,
	H_ERROR_DAQSUPPORT_UNINIT_FAILED,
	H_ERROR_DAQSUPPORT_READ_FAILED,
	H_ERROR_DAQSUPPORT_SEEK_FAILED,
	H_ERROR_DAQSUPPORT_CANTCREATEFILE,
	H_ERROR_DAQSUPPORT_INVALID_INDEX,
	H_ERROR_DAQSUPPORT_NODAQ,
	H_ERROR_DAQSUPPORT_WRITE_DAQ,
	H_ERROR_DAQSUPPORT_FORMAT_CHANGED,
	H_ERROR_AUDIO_FORMAT,
	H_ERROR_AUDIO_LOAD,
	H_ERROR_AUDIO_INPUTSUPPORT_LOAD,
	H_ERROR_AUDIO_OUTPUTSUPPORT_LOAD,
	H_ERROR_AUDIO_INPUTSUPPORT,
	H_ERROR_AUDIO_OUTPUTSUPPORT,
	H_ERROR_AUDIO_CANTCREATEFILE, 
	H_ERROR_AUDIO_NOAUD,
	H_ERROR_AUDIO_WRITE_AUD,
	H_ERROR_AUDIO_FORMAT_CHANGED,
	H_ERROR_AUDIO_INVALID_INDEX,
	H_ERROR_AUDIO_INVALID_FORMAT,
	H_ERROR_AUDIO_CHANNEL_MASK_MATCH,
	H_ERROR_AUDIO_READ_FAILED,
    H_ERROR_CANT_ADD_FRAME,
	H_ERROR_UNSUPPORT_FUNCTION,
	H_ERROR_CREATE_SOCKET,
	H_ERROR_BIND_SOCKET,
	H_ERROR_LISTEN_SOCKET,
	H_ERROR_SHUTDOWN_SOCKET,
	H_ERROR_CLOSE_SOCKET,
	H_ERROR_INVALID_SOCKET,
	H_ERROR_SERVER_NOT_RUNNING,
	H_ERROR_SERVER_ALREADY_OPEN,
	H_ERROR_CLIENT_ALREADY_CONNECTED,
	H_ERROR_CONNECTION_FAILED,
	H_ERROR_SEND,
    H_ERROR_OUT_OF_RANGE,
    H_ERROR_NO_FILE,
	H_ERROR_H264_UNSUPPOT_IMAGE_SIZE,
	H_ERROR_H264_ENCODING,
	H_ERROR_H264_DECODING,
	H_ERROR_CREATE_SAMPLE_GRABBER,
	H_ERROR_SAMPLE_GRABBER_CALLBACK,
	H_ERROR_ADD_SAMPLE_GRABBER,
	H_ERROR_CONNECT_ASOURCE_ALEVEL,
	H_ERROR_CONNECT_ALEVEL_ACODEC,
	H_ERROR_CONNECT_ALEVEL_MUX,
	H_ERROR_NO_AUDIO_SOURCE,
	H_ERROR_NO_RECORDING,
	H_ERROR_NO_CAPTURE_GRAPH,
	H_ERROR_FAILED_TO_ADD_TAG,
    H_ERROR_FRAME_SKIPPED,
	H_ERROR_AVI_TAG_NOT_FOUND,
    H_ERROR_REGISTRY_READ,
    H_ERROR_REGISTRY_WRITE,
    H_ERROR_CREATEC_UNSUPPORT_FORMAT,
    H_ERROR_INVALID_LUT_FILE
};
//-----------------------------------------------------------------------------
//Sequence optional bit flags
#define H_SEQBITFLAG_NULL			0x00
#define H_SEQBITFLAG_HASMARKERS		0x01
#define H_SEQBITFLAG_REFERENCE_TIME 0x02
#define H_SEQBITFLAG_LTC			0x04

#endif