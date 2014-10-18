/***********************************************************************
* CPP File:
*    Gun
* Author:
*    Robbie Bise and Brandon Ackerman
* Summary:
*    Definitions for the gun class for our skeet game
************************************************************************/
#include <iostream> 
#include <cassert>
#include "gun.h"

// set the bounds of the game
float Point::xMin = -128.0;
float Point::xMax = 128.0;
float Point::yMin = -128.0;
float Point::yMax = 128.0;
/***********************************************************************
* Gun
* Default constructor for the gun class
************************************************************************/
Gun::Gun() : angle(45)
{
	gun.setX(gun.getXMax());
	gun.setY(gun.getYMax());
}