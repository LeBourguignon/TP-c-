#pragma once
#include "Controller.h"
#include "View-LoadImage.h"
#include "View-MenuImage.h"

class Application
{
private:
	Controller controller;
	ViewLoadImage viewLoadImage;
	ViewMenuImage viewMenuImage;
	
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