#pragma once
#include "Controller.h"
#include "View-menu.h"

class Application
{
private:
	Controller controller;
	ViewMenu viewMenu;

public:
	/**
	 * Constructor
	 */
	Application();

	/**
	 * Runs the application
	 */
	void run();
};