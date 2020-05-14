#include "View-LoadImage.h"
#include <iostream>

/**
 * Constructor
 * @param _controller Application controller
 */
ViewLoadImage::ViewLoadImage(Controller& _controller)
	: View("Load Image"), controller(_controller)
{
	controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewLoadImage::notify()
{
	if (controller.getCurrentScreen() == 10)
		display();
}

/**
 * Displays the view
 */
void ViewLoadImage::display()
{
    std::string addressSource;
 
    do
    {
        clear();
        View::display();
        std::cout << "\tVeuillez entrer l'adresse de l'image (ex : C:/mon-image.jpg) : ";

        std::cin.clear();
        std::cin >> addressSource;
        controller.setAddressSource(addressSource);
    } while (!controller.testAddressSource());

    controller.showImageSource(); //Executer cette ligne en multithreading!!!
    controller.setScreen(0);
}