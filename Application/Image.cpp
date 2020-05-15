#include "Image.h"

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

int Image::testAddressSource()
{
	Mat img = imread(addressSource);
	if (img.empty())
	{
		std::cout << "\tImpossible d'ouvrir ou de trouver l'image!" << std::endl;
		std::cin.get(); //wait for any key press
		return 0;
	}
	else
	{
		return 1;
	}
}

int Image::testAddressGhost()
{
	Mat img = imread(addressGhost);


	if (img.empty())
	{
		std::cout << "\tImpossible d'ouvrir ou de trouver l'image!" << std::endl;
		std::cin.get(); //wait for any key press
		return 0;
	}
	else
	{
		return 1;
	}
}

void Image::showImageSource() 
{
	Mat img = imread(addressSource);
	namedWindow("Image d'origine", WINDOW_NORMAL);
	imshow("Image d'origine", img);
	waitKey(0);
}

void Image::imRGBtoGray(std::string _adresse)
{
	Mat im_rgb = imread(_adresse);
	Mat im_gray;
	cvtColor(im_rgb, im_gray, 7 );
}
