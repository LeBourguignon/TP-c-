#include "View-5.h"
#include <iostream>

/**
 * Constructor
 * @param _controller Application controller
 */
View5::View5(Controller& _controller)
    : View("Erosion"), controller(_controller)
{
    controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void View5::notify()
{
    if (controller.getCurrentScreen() == 5)
        display();
}

/**
 * Displays the view
 */
std::string typeE(int _i)
{
    switch (_i)
    {
    case 1: return "Erosion : Rectangle";
    case 2: return "Erosion : Croix";
    case 3: return "Erosion : Ellipse";
    default: return "Erosion : Erreur";
    }
}

void View5::display()
{
    int x = 0;
    do
    {
        clear();
        View::display();

        std::cout << "\t1. Rectangle" << std::endl;
        std::cout << "\t2. Croix" << std::endl;
        std::cout << "\t3. Ellipse" << std::endl << std::endl;

        std::cout << "\t-----------------------------------------------------------" << std::endl;
        std::cout << "\t0. Retour" << std::endl;
        std::cout << std::endl;

        std::cin.clear();
        std::cin >> x;

        if (x == 1 || x == 2 || x == 3)
        {
            clear();
            std::cout << typeE(x) << std::endl << std::endl;

            std::cout << "\tDonnez une valeur:" << std::endl;
            std::cout << "\t\tIl est conseille une valeur entre 1 et 10" << std::endl << std::endl;

            std::cout << "\t-----------------------------------------------------------" << std::endl;
            std::cout << "\t0. Retour" << std::endl;
            std::cout << std::endl;

            int z;
            std::cin.clear();
            std::cin >> z;

            if (z != 0)
            {
                controller.erosion(x, z);
                controller.updateGhost(typeE(x));

                clear();
                std::cout << typeE(x) << std::endl << std::endl;

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
                    x = 5;
                }
                controller.setScreen(x);
            }
        }
        else if (x == 0)
        {
            controller.setScreen(x);
        }
    } while (x != 0);
}