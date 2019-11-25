#include "Initialisation.h"

using namespace cv;
using namespace std;
using namespace Eigen;

VectorizationData initialisation(Image<cv::Vec3b> I) {
	std::cout << "Enter initialisation : Make sur you enter 3*n points" << std::endl;
	
	VectorPoints data;
	data.image = I;
	vector<Point> *vector_points = new vector<Point>;

	data.vector_points = vector_points;
	
	namedWindow(WINDOW_NAME, 1);
	setMouseCallback(WINDOW_NAME, onMouse, &data);
	imshow(WINDOW_NAME, data.image);
	waitKey(0);
	std::cout << vector_points->size()<<" points ont été rentré" << std::endl;

	Bezier* Binit = new Bezier(*vector_points);
  	Binit->plot_curve(I);

	std::array<std::vector<double>,2> tange = Binit->get_tangents(1);
	Color* Cinit = new Color(10);
	VectorizationData initData(Binit, Cinit, I);

	return initData;
};

void onMouse(int event, int x, int y, int flags, void* p){

	VectorPoints* data = (VectorPoints*)p;

	if (event == EVENT_LBUTTONDOWN)
	{
		cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;

		Point m1(x, y);
		cout << m1 << endl;
		data->vector_points->push_back(m1);
		circle(data->image, m1, 2, Scalar(255, 0, 0), 2);
		imshow(WINDOW_NAME, data->image);
	}
}
