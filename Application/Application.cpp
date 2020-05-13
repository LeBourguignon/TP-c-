#include "Application.h"

/**
 * Constructor
 */
Application::Application()
    : controller(), viewMenu(controller)
{
}

/**
 * Runs the application
 */
void Application::run()
{
    controller.notify();
}