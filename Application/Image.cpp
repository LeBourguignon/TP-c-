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
	
*/

// types d'erosion ou de dilatation : MORPH_ELLIPSE  , MORPH_CROSS , MORPH_RECT 
// si tailleerosion ou tailledilatation = -1 la dilatation ou l'�rotson sera centr� au milieu de l'image

Mat Eroder(Mat _img,int _type�rosion, int _taille�rosion) 
{
	Mat _ghost;
	Mat element = getStructuringElement(_type�rosion, Size(2* _taille�rosion +1 ,2 * _taille�rosion),Point(_taille�rosion,_taille�rosion));
	erode(_img, _img,element); 
	return _ghost;
}

/*

*/

Mat Dilater(Mat _img, int _typedilatation, int _tailledilatation)
{
	Mat _ghost;
	 Mat �lement = getStructuringElement(_typedilatation, Size(2 * _tailledilatation + 1, 2 * _tailledilatation + 1), Point(_tailledilatation, _tailledilatation));
	dilate(_img, _ghost, �lement );
	return _ghost;
}

/* 
ATTENTION pour les contours l'image doit d'abord avoir subit un filtre gaussien  ainsi q'un calcul du gradient avant cette �tape !!!
de plus l'image d'entr�e doit �tre en noir et blanc 
*/

Mat Contours(Mat _img, double threshold1)
{	
	 Canny(_img,_img , threshold1, threshold1*2, 3); 

	/*  CV_EXPORTS_W void Canny(InputArray image, OutputArray edges,
		  double threshold1, double threshold2,
		  int apertureSize = 3, bool L2gradient = false); */
	 //definition open cv
	
	return _img;
}

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