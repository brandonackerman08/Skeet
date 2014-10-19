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


/***********************************************************************
* Bird
* Default constructor for the bird class
************************************************************************/
Bird::Bird()
{
	//validatePosition();
}

void Bird::regenerate()
{
	bird.setX(bird.getXMin() - 1);
	bird.setY(random(bird.getYMin(), bird.getYMax()));
	trajectory.setDX(random(3, 6));

	if (bird.getY() < 0)
		trajectory.setDY(random(0, 4));
	else
		trajectory.setDY(random(-4, 0));
	bird.resurrect();
}

/***********************************************************************
* Move
* Move our bird across the screen. 
************************************************************************/
void Bird::move()
{
	validatePosition(); // find out where bird is.

	if (bird.isDead())
	{
		// here we are generating a random number between 1 and 30 each time this function is called
		// this way we have a 1 in 30 chance it will be equal to zero. the bird wont regenerate until
		// we happen to generate 0 as a random number. therefore we are going to be makeing it so that
		// the bird will always pause roughly between 0 and 1 second before emerging. 
		if (0 == random(0, 30)); 
			regenerate();
	}

	else
	{
		bird.addX(trajectory.getDX());
		bird.addY(trajectory.getDY());
	}
	//validatePosition(); // check bird position again

}

/***********************************************************************
* validate position
* This will be some sort of error checking for bird. 
************************************************************************/
void Bird::validatePositionProc(const char * file, int line)
{
	//char something;

	if (bird.getX() > bird.getXMax() || bird.getY() > bird.getYMax()
		|| bird.getX() < bird.getXMin() || bird.getY() < bird.getYMin())
	{
		bird.kill();
	}

	//std::cerr << "Error in file: " << file << " at line: " << line << ".\n"
	//<< "this thing: " << thing << " is outside valid range\n";
	//std::cin >> something;
	//exit(1);

}
