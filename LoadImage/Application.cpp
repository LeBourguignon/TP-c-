#include "Application.h"

/**
 * Constructor
 */
Application::Application()
    : controller(), viewMenu(controller), viewList(controller), viewAdd(controller)
{
}

/**
 * Runs the application
 */
void Application::run()
{
    controller.notify();
}