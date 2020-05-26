#include "Application.h"

/**
 * Constructor
 */
Application::Application()
    : controller(), viewMenuImage(controller), view1(controller), view2(controller), view3(controller), view4(controller), view5(controller), view6(controller), view7(controller), view8(controller), viewShowImage(controller), viewSaveImage(controller), viewLoadImage(controller)
{
}

/**
 * Runs the application
 */
void Application::run()
{
    controller.notify();
}