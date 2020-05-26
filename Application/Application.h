#pragma once
#include "Controller.h"
#include "View-LoadImage.h"
#include "View-MenuImage.h"
#include "View-ShowImage.h"
#include "View-SaveImage.h"

#include "View-1.h"
#include "View-2.h"
#include "View-3.h"
#include "View-4.h"
#include "View-5.h"
#include "View-6.h"
#include "View-7.h"
#include "View-8.h"

class Application
{
private:
	Controller controller;
	ViewMenuImage viewMenuImage;
	
	View1 view1;
	View2 view2;
	View3 view3;
	View4 view4;
	View5 view5;
	View6 view6;
	View7 view7;
	View8 view8;

	ViewShowImage viewShowImage;
	ViewSaveImage viewSaveImage;
	ViewLoadImage viewLoadImage;
	
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