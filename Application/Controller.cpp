#include "Controller.h"

using namespace cv;

/**
 * Constructor
 */
Controller::Controller()
    : Subject(), currentScreen(10), img(imread(""))
{
    
}

/**
 * Defines the current screen to display
 * @param value : id of the screen to display
 */
void Controller::setScreen(const int& value)
{
    if (value >= 0 && value <= 9)
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

//Fonction Image:
void Controller::setAddress(std::string _address)
{
    img = imread(_address);
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