#pragma once
#include <opencv2/opencv.hpp>
#include <string>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int testAddressI(Mat _img);

void showImageThread(Mat _img, std::string _namedWindow);
	
Mat imRGBtoGray(Mat _img);

Mat gaussianFilter(Mat _img, int _i);

Mat medianFilter(Mat _img, int _i);


/*
int filtregauss(cv::InputArray _adresseSrc, cv::OutputArray _adresseDest, int _i);

int filtremed(cv::InputArray _adresseSrc, cv::OutputArray _adresseDest, int _ksize);
*/