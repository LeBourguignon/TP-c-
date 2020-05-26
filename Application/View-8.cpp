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
    int x = 0;
    do
    {
        clear();
        View::display();

        std::cout << "\tVoulez vous en noir et blanc ou en couleur ?" << std::endl;
        std::cout << "\t\t1. Noir et blanc" << std::endl;
        std::cout << "\t\t2. Couleur" << std::endl << std::endl;

        std::cout << "\t-----------------------------------------------------------" << std::endl;
        std::cout << "\t0. Retour" << std::endl;
        std::cout << std::endl;

        std::cin.clear();
        std::cin >> x;

        if (x == 1 || x == 2)
        {
            x--;
            controller.segementations(x);
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
                x = 0;
            }        
        }
    } while (x != 0);
    controller.setScreen(x);
}