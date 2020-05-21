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


/*
int Image::filtregauss(InputArray _adresseSrc, OutputArray _adresseDest, int _i)
{
	int i = _i;
	for (int i; i < MAX_KERNEL_LENGTH; i = i + 2) {

		GaussianBlur(_adresseSrc, _adresseDest, Size(i, i), 0, 0);

	}
	return 0;
}

int Image::filtremed(InputArray _adresseSrc, OutputArray _adresseDest, int _ksize)
{
	int ksize = _ksize;
	for (int ksize; ksize < MAX_KERNEL_LENGTH; ksize = ksize + 2) {

		medianBlur(_adresseSrc, _adresseDest, ksize);

	}
}
*/