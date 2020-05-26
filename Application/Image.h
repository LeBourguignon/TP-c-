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

Mat dilater(Mat _img, int _type, int _taille);

Mat eroder(Mat _img, int _type, int _taille);

Mat contours(Mat _img, double thresh);

Mat opSeuil(Mat _img, int _type, double _i);

Mat segementation(Mat _img);