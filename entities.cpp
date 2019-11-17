
#include <iostream>
#include <ostream>

#include <igl/opengl/glfw/Viewer.h>
#include <igl/readPLY.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;
using namespace Eigen;


class Bezier{

public:
    int Nb_bezigons;
    MatrixXd *Bx;
    MatrixXd *By;

	Bezier(int N){
        Nb_bezigons = N;
		By = new MatrixXd(N, 3);
		Bx = new MatrixXd(N, 3);
        By->setZero();
        Bx->setZero();
	}

    Bezier(const MatrixXd &B_x, const MatrixXd &B_y){
        Nb_bezigons = B_x.rows();
        By = new MatrixXd(Nb_bezigons, 3);
		Bx = new MatrixXd(Nb_bezigons, 3);
        *Bx=B_x;
        *By=B_y;

    }
    float arclength(){
        //Returns the arclegth of the Bezigon
        return 0.0;
    }
    MatrixXd intersection(){
        //Returns points that intersect // Maybe directly in Energy?
        MatrixXd inter;
        return inter ;
    }
    void set_point_x(int i, int j, int coord_x){
        Bx->row(i)[j]=coord_x;
    }
    void set_point_y(int i, int j, int coord_y){
        By->row(i)[j]=coord_y;
    }

};


class Color{
public:
    Color(){
        C = new MatrixXd(6, 3);
        C->setZero();
    }

    int getColorImage(int x, int y){
        return 0;
    }

    void setColor(int index,int RGB, int color){
        C->row(index)[RGB]=color;
    }

private:
    MatrixXd *C; //Co a C5


};

struct Parameters
{
    Bezier *B;
    Color *C;
    Parameters(Bezier *_B,Color *_C){
        B=_B;
        C=_C;
    }
};



