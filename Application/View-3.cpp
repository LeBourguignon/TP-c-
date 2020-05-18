#include "View-3.h"
#include <iostream>

/**
 * Constructor
 * @param _controller Application controller
 */
View3::View3(Controller& _controller)
    : View("Calcul du gradient dans une image (Sobel)"), controller(_controller)
{
    controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void View3::notify()
{
    if (controller.getCurrentScreen() == 3)
        display();
}

/**
 * Displays the view
 */
void View3::display()
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