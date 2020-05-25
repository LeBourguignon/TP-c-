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

Mat gradient(Mat _img)
{
	int scale = 1;
	int delta = 0;
	int ddepth = -1; //tester avec a la place de -1 si problème CV_16S

	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;

	// Gradient en X
	Sobel(_img, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);

	// Gradient en Y
	Sobel(_img, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);

	
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, _img);


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
/* ATTENTION pour les contours l'image doit d'abord avoir subit un filtre gaussien  ainsi q'un calcul du gradient avant cette étape !!!
	de plus l'image d'entrée doit être en noir et blanc */


Mat Contours(Mat _img, double threshold1)
{
	
	 Canny(_img,_img , threshold1, threshold1*2, 3); 

	

	return _img;

}




