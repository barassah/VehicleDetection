////////

#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"
#include "opencv2\objdetect\objdetect.hpp"
#include "opencv2\videoio\videoio.hpp"
#include "opencv2\imgcodecs\imgcodecs.hpp"
#include "opencv2\core\core.hpp"
#include <vector>
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <time.h>

using namespace cv;
using namespace std;

Mat img;
//VideoCapture cap;

int main(int argc, const char** argv)
{
	//VideoCapture cap(0);			//Streaming Camera feed
	VideoCapture cap("Image3.mp4");			//static video file
	
	for (;;)
	{
		if (!cap.isOpened()) {
			cout << "Video Capture Fail" << endl;
			break;
		}
		else {
			cap >> img;
//			int Preprocess(Mat img);	//Pass parameters to Prepocess File for processing		
			Mat img0 = img;			// Holds the capture image:
			Mat cm_img0;			// Holds the colormap version of the image:
			applyColorMap(img, cm_img0, CV_BGR2GRAY);   // Apply the Binary:
//			imshow("BinaryMap", cm_img0); //threshold(img, cm_img0, 128, 255, THRESH_BINARY);
			applyColorMap(img, cm_img0, COLORMAP_JET); // Apply the colormap:
			imshow("HeatMap", cm_img0);	 // Show the result:
			int key2 = waitKey(20);	//Dispaly the window for some time onscreen
		}

	}
	return 0;
}

