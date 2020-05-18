#include "View-4.h"
#include <iostream>

/**
 * Constructor
 * @param _controller Application controller
 */
View4::View4(Controller& _controller)
    : View("Dilatation"), controller(_controller)
{
    controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void View4::notify()
{
    if (controller.getCurrentScreen() == 4)
        display();
}

/**
 * Displays the view
 */
void View4::display()
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