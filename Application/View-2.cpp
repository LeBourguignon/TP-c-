#include "View-2.h"
#include <iostream>

/**
 * Constructor
 * @param _controller Application controller
 */
View2::View2(Controller& _controller)
    : View("Filtre gaussien"), controller(_controller)
{
    controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void View2::notify()
{
    if (controller.getCurrentScreen() == 2)
        display();
}

/**
 * Displays the view
 */
void View2::display()
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