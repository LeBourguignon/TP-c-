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
	1. Filtre Médian
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

Mat gradient(Mat _img, int _dx, int _dy)
{
	Mat _ghost;

	// dx : ordre de la dérivée en x
	// dy : ordre de la dérivée en y
	
	Sobel(_img,_ghost, -1 , 3 ,1 ,0 ); //à tester 

	return _ghost;
}

Mat Eroder(Mat _img, int _ité)
{
	Mat _ghost;

	erode(_img, _ghost, Mat(), Point(-1, -1), _ité); //à tester

	
	/*  noyau :	élément structurant utilisé pour l'érosion; si element=Mat() , un élément structurant rectangulaire 3 x 3 est utilisé. 
	ancre : position de l'ancre dans l'élément; la valeur par défaut (-1, -1) signifie que l'ancre est au centre de l'élément.
	*/

	return _ghost;
}

Mat Dilater(Mat _img, int _ité)
{
	Mat _ghost;

	dilate(_img, _ghost, Mat(), Point(-1, -1), _ité);

	return _ghost;
}
/* ATTENTION pour les contours l'image doit d'abord avoir subit un filtre gaussien  ainsi q'un calcul du gradient avant cette étape !!!
	de plus l'image d'entrée doit être en noir et blanc */
/*
Mat Contours(Mat _img, double threshold1, double threshold2)
{
	
	 Canny(_img, threshold1,threshold2); //PB d fontionnement

	/*  CV_EXPORTS_W void Canny(InputArray image, OutputArray edges,
		  double threshold1, double threshold2,
		  int apertureSize = 3, bool L2gradient = false);
	 //definition open cv

	return _img;

}
*/

/* 
	7. Opérations de seuillages
		1 : Binaire
		2 : Binaire inversé
		3 : Seuil tronqué
		4 : Seuil à zéro
		5 : Seuil à zéro inversé
*/
Mat OpSeuil(Mat _img, int _Type, double _i)
{
	Mat _ghost;
	_Type--;
	threshold(_img, _ghost, _i, 255, _Type); //255 étant la valeur max de seuil (luminosité max)
	return  _ghost;
}