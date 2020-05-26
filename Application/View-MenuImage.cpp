#include "View-MenuImage.h"
#include <iostream>

/**
 * Constructor
 * @param _controller Application controller
 */
ViewMenuImage::ViewMenuImage(Controller& _controller)
    : View("Menu des traitements de l'image"), controller(_controller)
{
    controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewMenuImage::notify()
{
    if (controller.getCurrentScreen() == 0)
        display();
}

/**
 * Displays the view
 */
void ViewMenuImage::display()
{
    clear();
    View::display();

    std::cout << "\tFiltrage :" << std::endl;
    std::cout << "\t\t1. Filtre median" << std::endl;
    std::cout << "\t\t2. Filtre gaussien" << std::endl << std::endl;

    std::cout << "\tDerivation :" << std::endl;
    std::cout << "\t\t3. Calcul du gradient dans une image ( Sobel )" << std::endl << std::endl << std::endl;

    std::cout << "\tOperations de morphologie mathematique :" << std::endl;
    std::cout << "\t\t4. Dilatation" << std::endl;
    std::cout << "\t\t5. Erosion" << std::endl << std::endl;

    std::cout << "\tDetection de contours :" << std::endl;
    std::cout << "\t\t6. Application d'un detecteur de contours \"Canny\"" << std::endl << std::endl << std::endl;

    std::cout << "\tSegmentations d'images :" << std::endl;
    std::cout << "\t\t7. Operations de seuillages" << std::endl;
    std::cout << "\t\t8. Segmentation par croissance de region" << std::endl << std::endl;

    std::cout << "\t-----------------------------------------------------------" << std::endl;
    std::cout << "\t 9. Afficher l'image" << std::endl;
    std::cout << "\t10. Changer d'image" << std::endl;
    std::cout << "\t11. Quitter" << std::endl;
    std::cout << std::endl;

    int x;
    std::cin.clear();
    std::cin >> x;

    controller.setScreen(x);
}