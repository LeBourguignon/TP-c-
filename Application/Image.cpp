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

Mat gradient(Mat _img, int _dx, int _dy)
{
	Mat _ghost;

	// dx : ordre de la d�riv�e en x
	// dy : ordre de la d�riv�e en y
	
	Sobel(_img,_ghost, -1 , 3 ,1 ,0 ); //� tester 

	return _ghost;
}

Mat Eroder(Mat _img, int _it�)
{
	Mat _ghost;

	erode(_img, _ghost, Mat(), Point(-1, -1), _it�); //� tester

	
	/*  noyau :	�l�ment structurant utilis� pour l'�rosion; si element=Mat() , un �l�ment structurant rectangulaire 3 x 3 est utilis�. 
	ancre : position de l'ancre dans l'�l�ment; la valeur par d�faut (-1, -1) signifie que l'ancre est au centre de l'�l�ment.
	*/

	return _ghost;
}

Mat Dilater(Mat _img, int _it�)
{
	Mat _ghost;

	dilate(_img, _ghost, Mat(), Point(-1, -1), _it�);

	return _ghost;
}
/* ATTENTION pour les contours l'image doit d'abord avoir subit un filtre gaussien  ainsi q'un calcul du gradient avant cette �tape !!!
	de plus l'image d'entr�e doit �tre en noir et blanc */
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
	7. Op�rations de seuillages
		1 : Binaire
		2 : Binaire invers�
		3 : Seuil tronqu�
		4 : Seuil � z�ro
		5 : Seuil � z�ro invers�
*/
Mat OpSeuil(Mat _img, int _Type, double _i)
{
	Mat _ghost;
	_Type--;
	threshold(_img, _ghost, _i, 255, _Type); //255 �tant la valeur max de seuil (luminosit� max)
	return  _ghost;
}