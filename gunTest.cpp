/***********************************************************************
* Test File:
*    Gun
* Author:
*    Robbie Bise and Brandon Ackerman
* Summary:
*    Code to test the gun class
************************************************************************/
#include "gun.h" // gun class
#include "uiInteract.h" // OpenGL interface
#include <iostream> // cout the angle
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
	Gun *pGun = (Gun *)p;

	// check the paddle
	pGun->move(pUI->isUp(), pUI->isDown());

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
	Gun gun;
	ui.run(callBack, (void *)&gun);
	
	return 0;
}
