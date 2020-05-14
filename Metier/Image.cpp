#include "Image.h"

using namespace cv;

Image::Image(std::string _address)
	:	addressSource(_address)
{

}

void Image::setAddress(std::string _address)
{
	address = _address;
}

std::string Image::getAddress()
{
	return address;
}

void Image::showImage(std::string _namedWindow)
{
	Mat img = imread(address);
	namedWindow(_namedWindow, WINDOW_NORMAL);
	imshow(_namedWindow, img);
	waitKey(0);
}