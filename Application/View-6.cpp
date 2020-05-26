#include "View-6.h"
#include <iostream>

/**
 * Constructor
 * @param _controller Application controller
 */
View6::View6(Controller& _controller)
    : View("Application d'un detecteur de contours \"Canny\""), controller(_controller)
{
    controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void View6::notify()
{
    if (controller.getCurrentScreen() == 6)
        display();
}

/**
 * Displays the view
 */
void View6::display()
{
    int x = 0;
    do
    {
        clear();
        View::display();

        std::cout << "\tDonnez une valeur pour la prescision:" << std::endl;
        std::cout << "\t\tIl est conseille une valeur environ 100" << std::endl << std::endl;

        std::cout << "\t-----------------------------------------------------------" << std::endl;
        std::cout << "\t0. Retour" << std::endl;
        std::cout << std::endl;

        std::cin.clear();
        std::cin >> x;

        if (x != 0)
        {
            controller.dectContours(x);
            controller.updateGhost("Application d'un detecteur de contours \"Canny\"");

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
            else
            {
                x = 6;
            }
            controller.setScreen(x);
        }
        else
        {
            controller.setScreen(x);
        }
    } while (x != 0);
}