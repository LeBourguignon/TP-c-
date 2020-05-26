#pragma once
#include <opencv2/opencv.hpp>
#include <string>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <opencv2/core.hpp>

using namespace cv;

int testAddressI(Mat _img);

void showImageThread(Mat _img, std::string _namedWindow);
	
Mat imRGBtoGray(Mat _img);

Mat gaussianFilter(Mat _img, int _i);

Mat medianFilter(Mat _img, int _i);

Mat gradient(Mat _img);

Mat Dilater(Mat _img, int _typedilatation, int tailledilatation);

Mat Eroder(Mat _img, int _typeérosion, int _tailleérosion);

Mat Contours(Mat _img, double thresh);

Mat OpSeuil(Mat _img, int _Type, double _i);

Mat segementation(Mat _img);