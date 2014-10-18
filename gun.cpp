/***********************************************************************
* CPP File:
*    Gun
* Author:
*    Robbie Bise and Brandon Ackerman
* Summary:
*    Definitions for the gun class for our skeet game
************************************************************************/
#include <iostream> //cin cout cerr
#include <cstdlib> // for exit in validate
#include "gun.h"

// set the bounds of the game
float Point::xMin = -128.0; // These are static
float Point::xMax = 128.0;
float Point::yMin = -128.0;  // This is how you initilize static vars
float Point::yMax = 128.0;
int Gun::angle = 45;

/***********************************************************************
* Gun
* Default constructor for the gun class
************************************************************************/
Gun::Gun() 
{
	gun.setX(gun.getXMax()); // gun will go on the far right side
	gun.setY(gun.getYMin()); // at the bottom of the screen
	validatePosition();
}

/***********************************************************************
* Move
* Take in to account if the up or down arrow is pressed and move gun
* accordingly.
************************************************************************/
void Gun::move(int up, int down)
{
	validatePosition(); // make sure gun is in an ok position

	if (up && angle <= MAX_TILT_UP)
		angle -= (up   + 9) / 5; // if up move up
	if (down && angle >= MAX_TILT_DOWN)
		angle += (down + 9) / 5; // if down move down

	if (angle > MAX_TILT_UP)
		angle = MAX_TILT_UP;
	if (angle < MAX_TILT_DOWN)
		angle = MAX_TILT_DOWN;
	
	validatePosition(); // check gun position again
	
}

// Getters
/***********************************************************************
* getGun
* Give us access to the gun point? not sure we need this
************************************************************************/
void Gun::getGun()
{
 
}

//Setters

/***********************************************************************
* setGun
* Don't know how we will use this either. if we have the point class
* included we can just access what we need through there right?
************************************************************************/
void Gun::setGun()
{

}

void Gun :: validatePositionProc(const char * file, int line)
{
	char something;
                     //90                    //0
	if (angle > MAX_TILT_UP || angle < MAX_TILT_DOWN)
	{
		std::cerr << "Error in file: " << file << " at line: " << line << ".\n"
			<< "gun angle: " << angle <<" is outside valid range\n";
		std::cin >> something;
		exit (1);
	}
	
}