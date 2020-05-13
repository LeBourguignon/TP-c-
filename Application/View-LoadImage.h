#pragma once
#include "Observer.h"
#include "View.h"
#include "Controller.h"

class ViewLoadImage: public View
{
private:
	Controller& controller;
public:
	/**
	 * Constructor
	 * @param _controller Application controller
	 */
	ViewLoadImage(Controller& _controller);

	/**
	 * Notification function of the view
	 */
	virtual void notify();

	/**
	 * Displays the view
	 */
	virtual void display();
};

