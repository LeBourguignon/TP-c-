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
	Mat _ghost;
	cvtColor(_img, _ghost, 7);
	return _ghost;
}

/*
	1. Filtre M�dian
*/

Mat medianFilter(Mat _img, int _i)
{
	Mat _ghost;
	_i = _i * 2 + 1;
	medianBlur(_img, _ghost, _i);
	return _ghost;
}

/*
	2. Filtre Gaussian
*/

Mat gaussianFilter(Mat _img, int _i)
{
	Mat _ghost;
	GaussianBlur(_img, _ghost, _img.size(), _i);
	return _ghost;
}

/*
	3. Calcul du gradient dans une image ( Sobel )
*/

Mat gradient(Mat _img)
{ 
	int scale = 1;
	int delta = 0;
	int ddepth = -1; //tester avec a la place de -1 si probl�me CV_16S

	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;
	Mat _ghost;


	Sobel(_img, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);	// gradient en X

	
	Sobel(_img, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);// Gradient en Y


	
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, _ghost); //gradient total

	return _ghost;
}

/*
	4. Dilatation
		
*/

Mat dilater(Mat _img, int _type, int _taille)
{
	Mat _ghost;
	_type--;
	Mat �lement = getStructuringElement(_type, Size(2 * _taille + 1, 2 * _taille + 1));
	dilate(_img, _ghost, �lement);
	return _ghost;
}

/*
	5. Erosion
*/

// types d'erosion ou de dilatation : MORPH_ELLIPSE  , MORPH_CROSS , MORPH_RECT 
// si tailleerosion ou tailledilatation = -1 la dilatation ou l'�rotson sera centr� au milieu de l'image

Mat eroder(Mat _img, int _type, int _taille)
{
	Mat _ghost;
	_type--;
	Mat element = getStructuringElement(_type, Size(2* _taille +1 ,2 * _taille));
	erode(_img, _ghost,element); 
	return _ghost;
}

/* 
	6. Application d'un detecteur de contours ( Canny )

ATTENTION pour les contours l'image doit d'abord avoir subit un filtre gaussien  ainsi q'un calcul du gradient avant cette �tape !!!
de plus l'image d'entr�e doit �tre en noir et blanc 
*/

Mat contours(Mat _img, double thresh)
{
	Mat _ghost;
	RNG rng(12345);

	std::vector<std::vector<Point> > contours;
	std::vector<Vec4i> hierarchy;

	// Detect edges using canny
	Canny(_img, _ghost, thresh, thresh * 2, 3);

	findContours(_ghost, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	Mat drawing = Mat::zeros(_ghost.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
	}
	return drawing;
}

/* 
	7. Op�rations de seuillages
		1 : Binaire
		2 : Binaire invers�
		3 : Seuil tronqu�
		4 : Seuil � z�ro
		5 : Seuil � z�ro invers�
*/

Mat opSeuil(Mat _img, int _type, double _i)
{
	Mat _ghost;
	_type--;
	threshold(_img, _ghost, _i, 255, _type); //255 �tant la valeur max de seuil (luminosit� max)
	return  _ghost;
}

/*
	8. Segmentation par croissance de region
*/

Mat segementation(Mat _img)
{
	Mat _ghost;
	return _ghost;
}