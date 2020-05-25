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


	Sobel(_img, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);	// gradient en X

	
	Sobel(_img, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);// Gradient en Y


	
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, _img); //gradient total



	return _img;
}


// types d'erosion ou de dilatation : MORPH_ELLIPSE  , MORPH_CROSS , MORPH_RECT

Mat Eroder(Mat _img,int _typeérosion, int _tailleérosion) 
{
	Mat element = getStructuringElement(_typeérosion, Size(2* _tailleérosion +1 ,2 * _tailleérosion),Point(_tailleérosion,_tailleérosion));
	erode(_img, _img,element); 

	
	

	return _img;
}

Mat Dilater(Mat _img, int _typedilatation, int _tailledilatation)
{
	 Mat élement = getStructuringElement(_typedilatation, Size(2 * _tailledilatation + 1, 2 * _tailledilatation + 1), Point(_tailledilatation, _tailledilatation));
	dilate(_img, _img,élement );

	return _img;
}
/* ATTENTION pour les contours l'image doit d'abord avoir subit un filtre gaussien  ainsi q'un calcul du gradient avant cette étape !!!
	de plus l'image d'entrée doit être en noir et blanc */


Mat Contours(Mat _img, double threshold1)
{
	
	 Canny(_img,_img , threshold1, threshold1*2, 3); 

	

	return _img;

}




