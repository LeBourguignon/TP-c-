#include "Application.h"

/**
 * Constructor
 */
Application::Application()
    : controller(), viewLoadImage(controller), viewMenuImage(controller), view1(controller), view2(controller), view3(controller), view4(controller), view5(controller), view6(controller), view7(controller), view8(controller)
{
}

/**
 * Runs the application
 */
void Application::run()
{
    controller.notify();
}