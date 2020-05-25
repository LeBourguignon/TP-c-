#pragma once
#include <opencv2/opencv.hpp>
#include <string>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
class opésSeuillage
{
private:

public:


	Mat SeuilBin(Mat _img,int _Type, double _valseuil);
	Mat SeuilBinInv(Mat _img, int _Type, double _valseuil);
	Mat Tronquer(Mat _img, int _Type, double _valseuil);
	Mat SeuilaZero(Mat _img, int _Type, double _valseuil);
	Mat SeuilaZeroInv(Mat _img, int _Type, double _valseuil);

};

/* A tester avec velseuil =0 pour voir 

Ne pas oublier d'#include la classe pour la suite
*/

