#include "View-3.h"
#include <iostream>

/**
 * Constructor
 * @param _controller Application controller
 */
View3::View3(Controller& _controller)
    : View("Calcul du gradient dans une image (Sobel)"), controller(_controller)
{
    controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void View3::notify()
{
    if (controller.getCurrentScreen() == 3)
        display();
}

/**
 * Displays the view
 */
void View3::display()
{
    controller.calGradient();
    controller.updateGhost("Calcul du gradient dans une image (Sobel)");

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