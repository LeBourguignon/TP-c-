#include "View-Menu.h"
#include <iostream>

/**
 * Constructor
 * @param _controller Application controller
 */
ViewMenu::ViewMenu(Controller& _controller)
	: View("Menu"), controller(_controller)
{
	controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewMenu::notify()
{
	if (controller.getCurrentScreen() == 0)
		display();
}

/**
 * Displays the view
 */
void ViewMenu::display()
{
	clear();
	View::display();

	std::cout << "\t1. Liste des doleances issues du grand debat" << std::endl;
	std::cout << "\t2. Nouvelle doleance" << std::endl;
	std::cout << "\t--------------------------------------------" << std::endl;
	std::cout << "\t9. Quitter" << std::endl;
	std::cout << std::endl;

	int res;
	std::cin.clear();
	std::cin >> res;

	controller.setScreen(res);
}