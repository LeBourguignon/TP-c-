#pragma once
#include <opencv2/opencv.hpp>
#include <string>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

int testAddressI(Mat _img);

void showImageThread(Mat _img, std::string _namedWindow);
	
Mat imRGBtoGray(Mat _img);

Mat gaussianFilter(Mat _img, int _i);

Mat medianFilter(Mat _img, int _i);

Mat gradient(Mat _img);

Mat Eroder(Mat _img, int _typeérosion, int _tailleérosion);
Mat Dilater(Mat _img, int _typedilatation, int tailledilatation );

Mat Contours(Mat _img, double threshold1);

Mat OpSeuil(Mat _img, int _Type, double _valseuil);