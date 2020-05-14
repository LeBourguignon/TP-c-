#pragma once
#include <string>
#include <opencv2/opencv.hpp>

class Image
{
private:
	std::string addressSource;
	std::string addressGhost;

public:
	Image(std::string _addressSource, std::string _address);

	void setAddress(std::string _address);
	std::string getAddress();

	void showImage(std::string _namedWindow);
};