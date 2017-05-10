#include "mex.h"
//#include "matrix.h"
#include "Hermes.h"
//#include <fstream>
//#include <string>
using namespace std;

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) 
{
    
    // Takes a sequence file location and frame number
    // returns an image, a timestamp, a millisecond timestamp and a microsecond timestamp.
    
    LPCTSTR fname;
    int fnum;
    double *pFnum;
    HSequence sequence;
    void* rawImage;
    double imwid;
    double imhei;
    int imageSize;
    
    //declare timestamp stuff
    long time;
    unsigned short timeMilli;
    unsigned short timeMicro;
	
	double* pTime;
	double* pTimeMilli;
	double* pTimeMicro;
    
    unsigned char* rawImageChar;
    double* imageMem;
            
    //Declare a HImage to hold the image that will be read.
	HImage* image = HImage::CreateHImage();
        
    /* check for proper number of arguments
    if(nrhs!=2) 
      mexErrMsgTxt("Two inputs required.");
    else if(nlhs > 2) 
      mexErrMsgTxt("Too many output arguments.");
        
    if ( mxIsChar(prhs[0]) != 1)
      mexErrMsgTxt("Input 1 must be a string.");
    
    if ( mxIsNumeric(prhs[1]) != 1)
      mexErrMsgTxt("Input 2 must be an integer.");
     */
    
    fname = mxArrayToString(prhs[0]);
    pFnum = mxGetPr(prhs[1]);
    fnum = (int)*pFnum;
    
    //Open the sequence
    sequence.Open(fname);
    sequence.Read(image, fnum);
    sequence.Close();
    
    //get imageSize in bytes
    imageSize = image->GetImageSizeBytes();
    //width in pixels
    imwid = image->GetImageWidth();
    //height in pixels
    imhei = image->GetImageHeight();
	//absolute time
	time = image->GetTimestamp();
	timeMilli = image->GetTimestampMS();
	timeMicro = image->GetTimestampUS();
	
	//image data
    rawImage = image->GetRedChannel();
    
	//output image data
    plhs[0] = mxCreateNumericMatrix(imwid, imhei, mxUINT8_CLASS, mxREAL);
    imageMem = mxGetPr(plhs[0]);
    memcpy(imageMem,rawImage,imageSize);
		
	//output relative time
    plhs[1] = mxCreateDoubleMatrix(1,1,mxREAL);
	pTime = mxGetPr(plhs[1]);
	double dTime = time;
	*pTime = dTime;
	
	//output relative time milliseconds
	plhs[2] = mxCreateDoubleMatrix(1,1,mxREAL);
	pTimeMilli = mxGetPr(plhs[2]);
	double dTimeMilli = timeMilli;
	*pTimeMilli = dTimeMilli;
    
    image->DeleteHImage(image);

    return;
}