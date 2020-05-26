#include "Image.h"
#include <thread>

using namespace cv;

int testAddressI(Mat _img)
{
	if (_img.empty())
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void showImage(Mat _img, std::string _namedWindow)
{
	namedWindow(_namedWindow, WINDOW_AUTOSIZE);
	imshow(_namedWindow, _img);
	waitKey(0);
	destroyWindow(_namedWindow);
}

void showImageThread(Mat _img, std::string _namedWindow)
{
	std::thread t(showImage, _img, _namedWindow);
	t.detach();
}

void save(Mat _img, std::string _address)
{
	imwrite(_address, _img);
}

Mat imRGBtoGray(Mat _img)
{
	Mat _ghost;
	cvtColor(_img, _ghost, 7);
	return _ghost;
}

/*
	1. Filtre Médian
*/

Mat medianFilter(Mat _img, int _i)
{
	Mat _ghost;
	_i = _i * 2 + 1;
	medianBlur(_img, _ghost, _i);
	return _ghost;
}

/*
	2. Filtre Gaussian
*/

Mat gaussianFilter(Mat _img, int _i)
{
	Mat _ghost;
	GaussianBlur(_img, _ghost, _img.size(), _i);
	return _ghost;
}

/*
	3. Calcul du gradient dans une image ( Sobel )
*/

Mat gradient(Mat _img)
{ 
	int scale = 1;
	int delta = 0;
	int ddepth = -1; //tester avec a la place de -1 si problème CV_16S

	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;
	Mat _ghost;


	Sobel(_img, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);	// gradient en X

	
	Sobel(_img, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);// Gradient en Y


	
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, _ghost); //gradient total

	return _ghost;
}

/*
	4. Dilatation
		1 : Rectagle
		2 : Croix
		3 : Ellipse	
*/

Mat dilater(Mat _img, int _type, int _taille)
{
	Mat _ghost;
	_type--;
	Mat élement = getStructuringElement(_type, Size(2 * _taille + 1, 2 * _taille + 1));
	dilate(_img, _ghost, élement);
	return _ghost;
}

/*
	5. Erosion
		1 : Rectagle
		2 : Croix
		3 : Ellipse
*/

Mat eroder(Mat _img, int _type, int _taille)
{
	Mat _ghost;
	_type--;
	Mat element = getStructuringElement(_type, Size(2* _taille +1 ,2 * _taille));
	erode(_img, _ghost,element); 
	return _ghost;
}

/* 
	6. Application d'un detecteur de contours ( Canny )

		l'image d'entrée doit être en noir et blanc 
*/

Mat contours(Mat _img, double thresh)
{
	
	RNG rng(12345);
	Mat _ghost;
	std::vector<std::vector<Point> > contours;
	std::vector<Vec4i> hierarchy;

	
	Canny(_img, _ghost, thresh, thresh * 2, 3);

	findContours(_ghost, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	Mat drawing = Mat::zeros(_ghost.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
	}
	return _ghost;
}

/* 
	7. Opérations de seuillages
		1 : Binaire
		2 : Binaire inversé
		3 : Seuil tronqué
		4 : Seuil à zéro
		5 : Seuil à zéro inversé
*/

Mat opSeuil(Mat _img, int _type, double _i)
{
	Mat _ghost;
	_type--;
	threshold(_img, _ghost, _i, 255, _type); //255 étant la valeur max de seuil (luminosité max)
	return  _ghost;
}

/*
	8. Segmentation par croissance de region
*/

//img en couleur ss changements

Mat segementation(Mat _img,bool _colors)
{
	Mat src = _img;
	// Créer un noyau que nous utiliserons pour affiner notre image
	Mat kernel = (Mat_<float>(3, 3) <<
		1, 1, 1,
		1, -8, 1,
		1, 1, 1);
	Mat imgLaplacian;
	filter2D(src, imgLaplacian, CV_32F, kernel);
	Mat sharp;
	src.convertTo(sharp, CV_32F);
	Mat imgResult = sharp - imgLaplacian;
	// reconvertit en échelle de gris 8 bits
	imgResult.convertTo(imgResult, CV_8UC3);
	imgLaplacian.convertTo(imgLaplacian, CV_8UC3);
	
	Mat bw;
	cvtColor(imgResult, bw, COLOR_BGR2GRAY);
	threshold(bw, bw, 40, 255, THRESH_BINARY | THRESH_OTSU);
	// Effectue l'algorithme de transformation de distance
	Mat dist;
	distanceTransform(bw, dist, DIST_L2, 3);
	
	normalize(dist, dist, 0, 1.0, NORM_MINMAX);
	//Seuil pour obtenir les pics
	threshold(dist, dist, 0.4, 1.0, THRESH_BINARY);
	// Dilate un peu l'image
	Mat kernel1 = Mat::ones(3, 3, CV_8U);
	dilate(dist, dist, kernel1);
	// Créer la version CV_8U de l'image de distance nécessaire pour findContours ()
	Mat dist_8u;
	dist.convertTo(dist_8u, CV_8U);
	// Trouver les marqueurs totaux 
	std::vector<std::vector<Point> > contours;
	findContours(dist_8u, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	// Créer l'image de marqueur pour l'algorithme  "watershed" 
	Mat markers = Mat::zeros(dist.size(), CV_32S);
	// Dessine les marqueurs de premier plan
	for (size_t i = 0; i < contours.size(); i++)
	{
		drawContours(markers, contours, static_cast<int>(i), Scalar(static_cast<int>(i) + 1), -1);
	}
	// Dessine le marqueur de fond 
	circle(markers, Point(5, 5), 3, Scalar(255), -1);
	// Effectue l'algorithme "watershed"
	watershed(imgResult, markers);
	Mat mark;
	markers.convertTo(mark, CV_8U);
	bitwise_not(mark, mark);

	Mat dst = Mat::zeros(markers.size(), CV_8UC3);
	
	std::vector<Vec3b> colors;
	for (size_t i = 0; i < contours.size(); i++)
	{

		int b, g, r;
		if (_colors) {
			// Génère des couleurs aléatoires
			b = theRNG().uniform(0, 256);
			g = theRNG().uniform(0, 256);
			r = theRNG().uniform(0, 256);
		}
		else {
			//laisse le fond en blanc
			b = 255;
			g = 255;
			r = 255;
		}
		colors.push_back(Vec3b((uchar)b, (uchar)g, (uchar)r));
	}
	
	for (int i = 0; i < markers.rows; i++)
	{
		for (int j = 0; j < markers.cols; j++)
		{
			int index = markers.at<int>(i, j);
			if (index > 0 && index <= static_cast<int>(contours.size()))
			{
				dst.at<Vec3b>(i, j) = colors[index - 1];
			}
		}
	}


	return dst;
}