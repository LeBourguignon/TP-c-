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
    clear();
    View::display();

    std::cout << "\tBientot disponible!" << std::endl << std::endl;

    std::cout << "\t-----------------------------------------------------------" << std::endl;
    std::cout << "\t0. Retour" << std::endl;
    std::cout << "\t9. Quitter" << std::endl;
    std::cout << std::endl;

    int x;
    std::cin.clear();
    std::cin >> x;

    controller.setScreen(x);
}