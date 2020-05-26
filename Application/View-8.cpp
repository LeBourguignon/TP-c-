#include "View-8.h"
#include <iostream>

/**
 * Constructor
 * @param _controller Application controller
 */
View8::View8(Controller& _controller)
    : View("Segmentation par croissance de region"), controller(_controller)
{
    controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void View8::notify()
{
    if (controller.getCurrentScreen() == 8)
        display();
}

/**
 * Displays the view
 */
void View8::display()
{
    controller.segementations();
    controller.updateGhost("Segmentation par croissance de region");

    clear();
    View::display();

    std::cout << "\tVoulez vous garder la modification ?" << std::endl;
    std::cout << "\t\t1. Oui" << std::endl;
    std::cout << "\t\t0. Non" << std::endl << std::endl;

    int y;
    std::cin.clear();
    std::cin >> y;

    if (y == 1)
    {
        controller.ghostToImg();
    }

    controller.setScreen(0);
}