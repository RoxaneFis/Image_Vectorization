#include <iostream>
#include <ostream>


#include <igl/opengl/glfw/Viewer.h>
#include <igl/readPLY.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "bezier.cpp"

void initialisation(){
        bezier();
        std::cout<<"enter initialisation"<<std::endl;
    }
