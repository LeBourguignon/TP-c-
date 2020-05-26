#pragma once
#include "Subject.h"
#include "Image.h"

class Controller : public Subject
{
private:
	//ID of the current screnn to display
	int currentScreen;

	cv::Mat img;
	cv::Mat ghost;

public:
	/**
	 * Constructor
	 */
	Controller();

	/**
	 * Defines the new screen to display
	 * @param value : id of the new screen to display
	 */
	void setScreen(const int& value);

	/**
	 * Returns the id of the current displayed screen
	 */
	int getCurrentScreen();

	//Fonction Image:
	void setAddress(std::string _address);
	
	void ghostToImg();

	int testAddress(std::string _address);

	void updateImage(std::string _namedWindow);
	void updateGhost(std::string _namedWindow);

	void saveImage(std::string _address);

	void filtreGaussian(int _i);

	void filtreMedian(int _i);

	void calGradient();

	void dilatation(int _type, int _taille);

	void erosion(int _type, int _taille);

	void dectContours(int _i);

	void opSeuils(int _type, double _i);

	void segementations();
};