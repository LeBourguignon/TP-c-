#pragma once
#include "View.h"
#include "Controller.h"
#include "Observer.h"

class View1 : public View
{
private:
	// Controller of the application
	Controller& controller;
public:
	/**
	 * Constructor
	 * @param _controller Application controller
	 */
	View1(Controller& _controller);

	/**
	 * Notification function of the view
	 */
	virtual void notify();

	/**
	 * Displays the view
	 */
	virtual void display();
};