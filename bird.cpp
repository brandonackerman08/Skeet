/***********************************************************************
* CPP File:
*    Bird
* Author:
*    Robbie Bise and Brandon Ackerman
* Summary:
*    Definitions for the bird class for our skeet game
************************************************************************/
#include <iostream> //cin cout cerr
#include <cstdlib> // for exit in validate
#include "bird.h"

// set the bounds of the game
float Point::xMin = -128.0; 
float Point::xMax = 128.0;
float Point::yMin = -128.0; // do we only need to do this once in our final
float Point::yMax = 128.0;  // cpp file with main?

/***********************************************************************
* Bird
* Default constructor for the bird class
************************************************************************/
Bird::Bird()
{
	bird.setX(bird.getXMin - 1);
	bird.setY(random(bird.getYMin(), bird.getYMax());
	if (bird.getY() < 0)
		trajectory.setDy() = random(0, 4);
	else
		trajectory.setDx() = random(-4, 0);

	validatePosition();
}

/***********************************************************************
* Move
* Move our bird across the screen. 
************************************************************************/
void Bird::move()
{
	validatePosition(); // make sure bird is in an ok position

	if (bird.isDead())
	{
		// here we are generating a random number between 1 and 30 each time this function is called
		// this way we have a 1 in 30 chance it will be equal to zero. the bird wont regenerate until
		// we happen to generate 0 as a random number. therefore we are going to be makeing it so that
		// the bird will always pause roughly between 0 and 1 second before emerging. 
		if (0 == random(0, 30)); 
		// make the bird class fall out  of scope so we call another?
	}

	else
	{
		bird.addX(trajectory.getDx());
		bird.addY(trajectory.getDy());
	}
	validatePosition(); // check bird position again

}

/***********************************************************************
* validate position
* This will be some sort of error checking for bird. 
************************************************************************/
void Bird::validatePositionProc(const char * file, int line)
{
	char something;

	if ()//something has gone horribly wrong)
	{

		std::cerr << "Error in file: " << file << " at line: " << line << ".\n"
			<< "this thing: " << thing << " is outside valid range\n";
		std::cin >> something;
		exit(1);
	}

}