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

int showImage(std::string _address, std::string _namedWindow)
{
<<<<<<< HEAD
	Mat img = imread(_address);
	namedWindow(_namedWindow, WINDOW_NORMAL);
	imshow(_namedWindow, img);
	waitKey(0);
	destroyWindow(_namedWindow);
	return 0;
=======
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
>>>>>>> 65286d77726d06a4d852d6d2be2f3808b58d8fba
}

void Image::showImageSource()
{
<<<<<<< HEAD
	std::thread t(showImage, addressSource, "Image d'origine");
}
=======
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
>>>>>>> 65286d77726d06a4d852d6d2be2f3808b58d8fba
