#include "View-LoadImage.h"
#include <iostream>
#include <thread>

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
    int w = 0;
 
    do
    {
        clear();
        View::display();
        if (w == 0)
        {
            std::cout << std::endl;
        }
        else
        {
            std::cout << "\tImpossible d'ouvrir ou de trouver l'image!" << std::endl;
        }
        std::cout << "\tVeuillez entrer l'adresse de l'image (ex : C:/mon-image.jpg) : ";

        std::cin.clear();
        std::cin >> addressSource;
        if (!controller.testAddress(addressSource))
        {
            w = 1;
        }
        else
        {
            controller.setAddressSource(addressSource);
            w = 2;
        }
    } while (w != 2);

    controller.showImageSource(); //Executer cette ligne en multithreading!!!
    controller.setScreen(0);
}