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
	if (controller.getCurrentScreen() == 0)
		display();
}

/**
 * Displays the view
 */
void ViewLoadImage::display()
{
    clear();
    View::display();

    std::cout << "\tVeuillez entrer l'adresse de l'image (ex : C:\mon-image.jpg) : ";

    std::string address;
    do
    {
        std::cin.clear();
        std::cin >> address;

    } while ();
}