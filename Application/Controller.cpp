#include "Controller.h"

using namespace cv;

/**
 * Constructor
 */
Controller::Controller()
    : Subject(), currentScreen(12), img(imread("")), ghost(imread(""))
{
    
}

/**
 * Defines the current screen to display
 * @param value : id of the screen to display
 */
void Controller::setScreen(const int& value)
{
    if (value >= 0 && value <= 13)
        currentScreen = value;

    notify();
}

/**
 * Returns the id of the current displayed screen
 */
int Controller::getCurrentScreen()
{
    return currentScreen;
}

/*
    Fonction de Image.h
*/
void Controller::setAddress(std::string _address)
{
    img = imread(_address);
}

void Controller::ghostToImg()
{
    img = ghost;
}

int Controller::testAddress(std::string _address)
{
    Mat imgTest = imread(_address);
    return testAddressI(imgTest);
}

void Controller::updateImage(std::string _namedWindow)
{
    showImageThread(img, _namedWindow);
}

void Controller::updateGhost(std::string _namedWindow)
{
    showImageThread(ghost, _namedWindow);
}

void Controller::saveImage(std::string _address)
{
    save(img, _address);
}

void Controller::filtreGaussian(int _i)
{
    ghost = gaussianFilter(img, _i);
}

void Controller::filtreMedian(int _i)
{
    ghost = medianFilter(img, _i);
}

void Controller::calGradient()
{
    ghost = gradient(img);
}

void Controller::dilatation(int _type, int _taille)
{
    ghost = dilater(img, _type, _taille);
}

void Controller::erosion(int _type, int _taille)
{
    ghost = eroder(img, _type, _taille);
}

void Controller::dectContours(int _i)
{
    ghost = gradient(img);
    ghost = contours(ghost, _i);
  //  ghost = gradient(ghost);
  //  ghost = imRGBtoGray(ghost);
}

void Controller::opSeuils(int _Type, double _i)
{
    ghost = imRGBtoGray(ghost);
    ghost = opSeuil(ghost, _Type, _i);
}

void Controller::segementations()
{
    ghost = segementation(img);
}