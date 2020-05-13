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
    if (controller.getCurrentScreen() == 1)
        display();
}

/**
 * Displays the view
 */
void ViewMenuImage::display()
{
    clear();
    View::display();
}