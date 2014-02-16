/*
 * plugin_calibration.cpp
 *
 *  Created on: 16/01/2014
 *      Author: willytell
 */

#include "plugin_calibration.h"

PluginCalibration::PluginCalibration() {
	// TODO Auto-generated constructor stub
	flag = false;
	i=0;
}

PluginCalibration::~PluginCalibration() {
	// TODO Auto-generated destructor stub
}

bool PluginCalibration::process(IplImage *frame, std::vector<sData *> &data) {
	if (i == 0) {
		intrinsic = (CvMat*)cvLoad("Intrinsics.xml");
		distortion = (CvMat*)cvLoad("Distortion.xml");
		mapx = cvCreateImage( cvGetSize(frame), IPL_DEPTH_32F, 1 );
		mapy = cvCreateImage( cvGetSize(frame), IPL_DEPTH_32F, 1 );
		cvInitUndistortMap( intrinsic, distortion, mapx, mapy );
		//flag=true;
		i++;
	}
	t = cvCloneImage(frame);
	cvRemap( t, frame, mapx, mapy );	// Undistort image
	cvReleaseImage(&t);
	return true;
}

std::string PluginCalibration::getName() {
  return "calibration";
}
