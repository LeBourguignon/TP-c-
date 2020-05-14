#pragma once
#include <opencv2/opencv.hpp>
#include <string>

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

	int testAddressSource();
	int testAddressGhost();

	void showImageSource();
};