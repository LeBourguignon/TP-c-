#pragma once
#include <opencv2/opencv.hpp>
#include <string>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class Image
{
private:
	std::string addressSource;
	std::string addressGhost;


public:
	Image();

	void setAddressSource(std::string _addressSource);
	void setAddressGhost(std::string _addressGhost);
	
	std::string getAddressSource();
	std::string getAddressGhost();

	int testAddress(std::string _address);

	void showImageSource();
	
	void imRGBtoGray(std::string _adresse);

	int filtregauss(cv::InputArray _adresseSrc, cv::OutputArray _adresseDest, int _i);

	int filtremed(cv::InputArray _adresseSrc, cv::OutputArray _adresseDest, int _ksize);
};
