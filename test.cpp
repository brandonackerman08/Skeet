/***********************************************************************
* Test File:
*    Gun
* Author:
*    Robbie Bise and Brandon Ackerman
* Summary:
*    Code to test the gun class
************************************************************************/
#include "gun.h" // gun class
#include "bird.h" //bird classs
#include "uiInteract.h" // OpenGL interface
#include <iostream> // cout the angle

// set the bounds of the game
float Point::xMin = -128.0;
float Point::xMax = 128.0;
float Point::yMin = -128.0; // do we only need to do this once in our final
float Point::yMax = 128.0;  // cpp file with main?

/*********************************************
* CALLBACK
* The main interaction loop of the engine.
* This gets called from OpenGL.  It give us our
* interface pointer (where we get our events from)
* as well as a void pointer which we know is our
* game class.
*********************************************/
void callBack(const Interface *pUI, void *p)
{
	// we know the void pointer is our game class so
	// cast it into the game class.


	Bird *pBird = (Bird *)p; // when testing bird
	//Gun *pGun = (Gun *)p; when testing gun

	// for testing gun
	//pGun->move(pUI->isUp(), pUI->isDown());

	// for testing bird
	pBird->move();

	// gun
	//pGun->draw();

	// bird
	pBird->draw();

	// draw it
	pGun->draw();
}


/*********************************
* MAIN
* initialize the drawing window, initialize
* the game,and run it!
*********************************/
int main(int argc, char **argv)
{
	// Start the drawing
	Interface ui(argc, argv, "Gun Class");

	// play the game.  Our function callback will get called periodically
	//Gun gun;
	Bird bird;
	ui.run(callBack, (void *)&bird);
	return 0;
}
