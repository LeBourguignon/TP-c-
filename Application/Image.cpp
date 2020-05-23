#include "Image.h"
#include <thread>

using namespace cv;

int testAddressI(Mat _img)
{
	if (_img.empty())
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void showImage(Mat _img, std::string _namedWindow)
{
	namedWindow(_namedWindow, WINDOW_AUTOSIZE);
	imshow(_namedWindow, _img);
	waitKey(0);
	destroyWindow(_namedWindow);
}

void showImageThread(Mat _img, std::string _namedWindow)
{
	std::thread t(showImage, _img, _namedWindow);
	t.detach();
}

Mat imRGBtoGray(Mat _img)
{
	Mat im_gray;
	cvtColor(_img, im_gray, 7);
	return im_gray;
}

Mat gaussianFilter(Mat _img, int _i)
{
	GaussianBlur(_img, _img, _img.size(), _i);
	return _img;
}

Mat medianFilter(Mat _img, int _i)
{

	medianBlur( _img, _img , _i);
	return _img;
}

Mat gradient(Mat _img, int _dx, int _dy)
{
	// dx : ordre de la dérivée en x
	// dy : ordre de la dérivée en y
	
	Sobel(_img,_img, -1 , 3 ,1 ,0 ); //à tester 

	return _img;
}

Mat Eroder(Mat _img, int _ité)
{
	erode(_img, _img, Mat(), Point(-1, -1), _ité); //à tester

	
	/*  noyau :	élément structurant utilisé pour l'érosion; si element=Mat() , un élément structurant rectangulaire 3 x 3 est utilisé. 
	ancre : position de l'ancre dans l'élément; la valeur par défaut (-1, -1) signifie que l'ancre est au centre de l'élément.
	*/

	return _img;
}

Mat Dilater(Mat _img, int _ité)
{
	dilate(_img, _img, Mat(), Point(-1, -1), _ité);

	return _img;
}




