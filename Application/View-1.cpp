#include "View-1.h"
#include <iostream>

/**
 * Constructor
 * @param _controller Application controller
 */
View1::View1(Controller& _controller)
    : View("Filtre median"), controller(_controller)
{
    controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void View1::notify()
{
    if (controller.getCurrentScreen() == 1)
        display();
}

/**
 * Displays the view
 */
void View1::display()
{
    int x = 0;
    do
    {
        clear();
        View::display();

        std::cout << "\tDonnez une valeur:" << std::endl;                              //Texte à refaire!!!!!!!
        std::cout << "\t\tIl est conseille une valeur entre 1 et 10" << std::endl << std::endl;

        std::cout << "\t-----------------------------------------------------------" << std::endl;
        std::cout << "\t0. Retour" << std::endl;
        std::cout << std::endl;

        std::cin.clear();
        std::cin >> x;

        if (x == 0)
        {
            controller.setScreen(x);
        }
        else
        {
            controller.filtreMedian(x);
            controller.updateGhost("Filtre median");

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
                x = 1;
            }
        }
    } while (x != 0);
}