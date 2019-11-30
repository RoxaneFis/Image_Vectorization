#pragma once

#ifndef ENERGY_H_INCLUDED
#define ENERGY_H_INCLUDED

#include <iostream>
#include <ostream>

#include <igl/opengl/glfw/Viewer.h>
#include <igl/readPLY.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <dlib/global_optimization.h>


#include "RMS.h"
#include "Entities.h"

class Energy {
private:
	const double lambda_angles = (1.0/40.0)*100;
	const double lambda_handles = (1.0/2.0)*100;
public:
	Energy();
	double energy_angles(Bezier B, int point);
	double energy_angles(Bezier B);
	double energy_bezier_handles(Bezier B, int point);
	double energy_bezier_handles(Bezier B);

	double energy_data(VectorizationData vd);


	double energy_tot(VectorizationData vd, int j );
	double energy_to_minimize(VectorizationData vd, int j, dlib::matrix<double,10,1>x );

};



#endif