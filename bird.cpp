/***********************************************************************
* CPP File:
*    Bird
* Author:
*    Robbie Bise and Brandon Ackerman
* Summary:
*    Definitions for the bird class for our skeet game
************************************************************************/
#include <iostream> //cin cout cerr
#include <cstdlib> // for exit in validate also random?
#include "bird.h"


/***********************************************************************
* Bird
* Default constructor for the bird class
************************************************************************/
Bird::Bird()
{
	regenerate();
	validatePosition();
}

void Bird::regenerate()
{
	bird.resurrect();

	bird.setX(bird.getXMin());
	bird.setY((float)random(bird.getYMin(), bird.getYMax()));
	trajectory.setDX((float)random(3, 6));

	if (bird.getY() > 0)
	{
		//std::cout << "greater than 0 and: " << trajectory.getDY() << " \n";
		trajectory.setDY((float)random(0, 4));
	}
		
	else
	{
		//std::cout << "less than 0 and: " << trajectory.getDY() << " \n";
		trajectory.setDY((float)random(-4, 4));
	}
	
}

/***********************************************************************
* Move
* Move our bird across the screen. 
************************************************************************/
void Bird::move()
{
	validatePosition(); // find out where bird is.

	if (!bird.isDead())
	{
		bird.addX(trajectory.getDX());
		bird.addY(trajectory.getDY());
		validatePosition();
	}
		// here we are generating a random number between 1 and 30 each time this function is called
		// this way we have a 1 in 30 chance it will be equal to zero. the bird wont regenerate until
		// we happen to generate 0 as a random number. therefore we are going to be makeing it so that
		// the bird will always pause roughly between 0 and 1 second before emerging. 
	else
	{
		if (0 == random(0, 30))
			regenerate();
	}
	validatePosition(); // check bird position again

}

/***********************************************************************
* validate position
* This will check to see if bird is in bounds
* what else should we validate?
************************************************************************/
void Bird::validatePositionProc(const char * file, int line)
{
	//char something;

	// here I have added 20 to the max and subtracted 20 to the min to
	// get the bird to fly off screen. is there a better way we could do this?
	if (bird.getX() > bird.getXMax() + 20 || bird.getY() > bird.getYMax() + 20
		|| bird.getX() < bird.getXMin() - 20 || bird.getY() < bird.getYMin() - 20)
	{
		bird.kill();
	}

	//std::cerr << "Error in file: " << file << " at line: " << line << ".\n"
	//<< "this thing: " << thing << " is outside valid range\n";
	//std::cin >> something;
	//exit(1);

}
