#include "Controller.h"

/**
 * Constructor
 */
Controller::Controller()
    : Subject(), currentScreen(10), image(Image())
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
void Controller::setAddressSource(std::string _addressSource)
{
    image.setAddressSource(_addressSource);
}

void Controller::setAddressGhost(std::string _addressGhost)
{
    image.setAddressGhost(_addressGhost);
}

std::string Controller::getAddressSource()
{
    return image.getAddressSource();
}

std::string Controller::getAddressGhost()
{
    return image.getAddressGhost();
}

int Controller::testAddress(std::string _address)
{
    return image.testAddress(_address);
}

void Controller::showImageSource()
{
    image.showImageSource();
}