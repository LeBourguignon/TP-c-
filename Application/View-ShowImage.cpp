#include "View-ShowImage.h"
#include <iostream>

/**
 * Constructor
 * @param _controller Application controller
 */
ViewShowImage::ViewShowImage(Controller& _controller)
    : View("Show Image"), controller(_controller)
{
    controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewShowImage::notify()
{
    if (controller.getCurrentScreen() == 9)
        display();
}

/**
 * Displays the view
 */
void ViewShowImage::display()
{
    clear();
    controller.updateImage("Image");
    controller.setScreen(0);
}