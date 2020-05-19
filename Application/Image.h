#pragma once
#include <opencv2/opencv.hpp>
#include <string>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int testAddressI(cv::Mat _img);

void showImageThread(cv::Mat _img, std::string _namedWindow);
	
cv::Mat imRGBtoGray(cv::Mat _img);

/*
int filtregauss(cv::InputArray _adresseSrc, cv::OutputArray _adresseDest, int _i);

int filtremed(cv::InputArray _adresseSrc, cv::OutputArray _adresseDest, int _ksize);
*/