#include "View-MenuImage.h"
#include <iostream>

/**
 * Constructor
 * @param _controller Application controller
 */
ViewMenuImage::ViewMenuImage(Controller& _controller)
    : View("Menu Image"), controller(_controller)
{
    controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewMenuImage::notify()
{
    if (controller.getCurrentScreen() == 0)
        display();
}

/**
 * Displays the view
 */
void ViewMenuImage::display()
{
    clear();
    View::display();
    std::cout << "\tOption de filtre: bientot disponible..." << std::endl;
    std::cout << "\t---------------------------------------" << std::endl;
    std::cout << "\t9. Quitter" << std::endl;
    std::cout << std::endl;

    int res;
    std::cin.clear();
    std::cin >> res;

    controller.setScreen(res);
}