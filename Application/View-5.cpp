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
void View5::display()
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