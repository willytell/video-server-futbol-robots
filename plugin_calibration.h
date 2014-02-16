/*
 * plugin_calibration.h
 *
 *  Created on: 16/01/2014
 *      Author: willytell
 */

#ifndef PLUGIN_CALIBRATION_H_
#define PLUGIN_CALIBRATION_H_

#include "visionplugin.h"

class PluginCalibration: public VisionPlugin {
public:
	PluginCalibration();
	virtual ~PluginCalibration();

	virtual bool process(IplImage *frame, std::vector<sData *> &data);
	virtual std::string getName();

private:
	bool flag;
	int i;
	IplImage *t;
	IplImage *z;
	CvMat *intrinsic;
	CvMat *distortion;
	IplImage* mapx;
	IplImage* mapy;
};

#endif /* PLUGIN_CALIBRATION_H_ */
