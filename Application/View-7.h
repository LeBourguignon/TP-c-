#pragma once
#include "View.h"
#include "Controller.h"
#include "Observer.h"

class View7 : public View
{
private:
	// Controller of the application
	Controller& controller;
public:
	/**
	 * Constructor
	 * @param _controller Application controller
	 */
	View7(Controller& _controller);

	/**
	 * Notification function of the view
	 */
	virtual void notify();

	/**
	 * Displays the view
	 */
	virtual void display();
};