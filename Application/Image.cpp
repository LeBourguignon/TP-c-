#include "Image.h"
#include <thread>

using namespace cv;

Image::Image()
	:	addressSource(""), addressGhost("")
{

}

void Image::setAddressSource(std::string _addressSource)
{
	addressSource = _addressSource;
}

void Image::setAddressGhost(std::string _addressGhost)
{
	addressGhost = _addressGhost;
}

std::string Image::getAddressSource()
{
	return addressSource;
}

std::string Image::getAddressGhost()
{
	return addressGhost;
}

int Image::testAddress(std::string _address)
{
	Mat img = imread(_address);
	if (img.empty())
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void showImage(std::string _address, std::string _namedWindow)
{
	Mat img = imread(_address);
	namedWindow(_namedWindow, WINDOW_NORMAL);
	imshow(_namedWindow, img);
	waitKey(0);
	destroyWindow(_namedWindow);
}
	
void Image::showImageSource()
{
	std::thread t(showImage, addressSource, "Image d'origine");
}

void Image::imRGBtoGray(std::string _adresse)
{
	Mat im_rgb = imread(_adresse);
	Mat im_gray;
	cvtColor(im_rgb, im_gray, 7 );
}