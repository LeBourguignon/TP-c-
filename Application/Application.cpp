#include "Application.h"

/**
 * Constructor
 */
Application::Application()
    : controller(), viewLoadImage(controller), viewMenuImage(controller)
{
}

/**
 * Runs the application
 */
void Application::run()
{
    controller.notify();
}