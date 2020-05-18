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