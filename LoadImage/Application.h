#pragma once
#include "Controller.h"
#include "View-menu.h"
#include "View-add.h"
#include "View-list.h"

class Application
{
private:
	Controller controller;
	ViewMenu viewMenu;
	ViewList viewList;
	ViewAdd viewAdd;

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