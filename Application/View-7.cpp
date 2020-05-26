#include "View-7.h"
#include <iostream>

/**
 * Constructor
 * @param _controller Application controller
 */
View7::View7(Controller& _controller)
    : View("Operations de seuillages"), controller(_controller)
{
    controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void View7::notify()
{
    if (controller.getCurrentScreen() == 7)
        display();
}

/**
 * Displays the view
 */
std::string typeS(int _i)
{
    switch (_i)
    {
    case 1: return "Operations de seuillages : Binaire";
    case 2: return "Operations de seuillages : Binaire inverse";
    case 3: return "Operations de seuillages : Seuil tronque";
    case 4: return "Operations de seuillages : Seuil a zero";
    case 5: return "Operations de seuillages : Seuil a zero inverse";
    default: return "Operations de seuillages : Erreur";
    }
}

void View7::display()
{
    int x = 0;
    do
    {
        clear();
        View::display();

        std::cout << "\t1. Binaire" << std::endl;
        std::cout << "\t2. Binaire inverse" << std::endl;
        std::cout << "\t3. Seuil tronque" << std::endl;
        std::cout << "\t4. Seuil a zero" << std::endl;
        std::cout << "\t5. Seuil a zero inverse" << std::endl << std::endl;

        std::cout << "\t-----------------------------------------------------------" << std::endl;
        std::cout << "\t0. Retour" << std::endl;
        std::cout << std::endl;

        std::cin.clear();
        std::cin >> x;

        if (x == 0)
        {
            controller.setScreen(x);
        }
        else if (x == 1 || x == 2 || x == 3 || x == 4 || x == 5)
        {
            clear();
            std::cout << typeS(x) << std::endl << std::endl;

            std::cout << "\tDonnez une valeur:" << std::endl;
            std::cout << "\t\tIl est conseille une valeur entre 1 et 255" << std::endl << std::endl;

            std::cout << "\t-----------------------------------------------------------" << std::endl;
            std::cout << "\t0. Retour" << std::endl;
            std::cout << std::endl;

            int z;
            std::cin.clear();
            std::cin >> z;

            if (z != 0)
            {
                controller.opSeuils(x, z);
                controller.updateGhost(typeS(x));

                clear();
                std::cout << typeS(x) << std::endl << std::endl;

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
                    x = 7;
                }
                controller.setScreen(x);
            }
        }
    } while (x != 0);
}