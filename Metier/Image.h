#pragma once
#include <string>
#include <opencv2/opencv.hpp>

class Image
{
private:
	std::string address;

public:
	Image(std::string _address);

	void setAddress(std::string _address);
	std::string getAddress();

	void showImage(std::string _namedWindow);
};