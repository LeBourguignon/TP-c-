#include "View-SaveImage.h"
#include <iostream>

/**
 * Constructor
 * @param _controller Application controller
 */
ViewSaveImage::ViewSaveImage(Controller& _controller)
    : View("Save Image"), controller(_controller)
{
    controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewSaveImage::notify()
{
    if (controller.getCurrentScreen() == 10 || controller.getCurrentScreen() == 11)
        display();
}

/**
 * Displays the view
 */
void ViewSaveImage::display()
{
    int x = 0;
    do
    {
        clear();
        View::display();

        if (x == 1)
        {
            std::cout << "\tImpossible de sauvegarder avec cette adresse!" << std::endl;
        }
        else
        {
            std::cout << std::endl;
        }
        std::cout << "\tVeuillez entrer l'adresse ou vous voulez sauvegarder l'image:" << std::endl;
        std::cout << "\t\tex : C:/mon-image.jpg" << std::endl << std::endl;

        std::cout << "\t-----------------------------------------------------------" << std::endl;
        std::cout << "\t1. Retour" << std::endl;
        std::cout << "\t0. Ne pas sauvegarder" << std::endl;
        std::cout << std::endl;

        std::string address;
        std::cin.clear();
        std::cin >> address;

        x = 0;

        if (address == "1")
        {
            controller.setScreen(0);
        }
        else if (address != "0")
        {
            try
            {
                controller.saveImage(address);
            }
            catch (std::exception e)
            {
                x = 1;
            }
            if (x == 0)
            {
                if (controller.getCurrentScreen() == 11)
                    controller.setScreen(13);
                if (controller.getCurrentScreen() == 10)
                    controller.setScreen(12);
            }
        }
        else
        {
            controller.setScreen(13);
        }
    } while (x == 1);
}