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

Mat gradient(Mat _img,  int  _x, int _y);

Mat Eroder(Mat _img, int _ité); // _ité : itération ( nombre de fois que l'on veut éroder)

Mat Dilater(Mat _img, int _ité);