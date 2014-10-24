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
	trajectory.resurrect(); // revive dead bird

	trajectory.setX(trajectory.getXMin()); // put bird at xMin and at...
	trajectory.setY((float)random(trajectory.getYMin(), trajectory.getYMax())); // random y axis 
	trajectory.setDX((float)random(3, 6)); // speed (dx) random between 3 and 6

	if (trajectory.getY() > 0)
	{
		//std::cout << "greater than 0 and: " << trajectory.getDY() << " \n";
		trajectory.setDY((float)random(-4, 0)); // if bird is on top half send it downward
	}
		
	else
	{
		//std::cout << "less than 0 and: " << trajectory.getDY() << " \n";
		trajectory.setDY((float)random(0, 4)); // else send it upward 
	}
	
}

/***********************************************************************
* Move
* Move our bird across the screen. 
* in the else we are generating a random number between 1 and 30 each time 
* this function is called this way we have a 1 in 30 chance it will be equal 
* to zero. the bird wont regenerate until we happen to generate 0 as a 
* random number. therefore we are going to be makeing it so that
* the bird will always pause roughly between 0 and 1 second before emerging.
************************************************************************/
void Bird::move()
{
	validatePosition(); // find out where bird is.

	if (!trajectory.isDead())
	{
		trajectory.addX(trajectory.getDX());
		trajectory.addY(trajectory.getDY());
		validatePosition();
	}

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
	if (trajectory.getX() > trajectory.getXMax() + 20 || trajectory.getY() > trajectory.getYMax() + 20
		|| trajectory.getX() < trajectory.getXMin() - 20 || trajectory.getY() < trajectory.getYMin() - 20)
	{
		trajectory.kill();
	}

	//std::cerr << "Error in file: " << file << " at line: " << line << ".\n"
	//<< "this thing: " << thing << " is outside valid range\n";
	//std::cin >> something;
	//exit(1);

}

void Bird::draw(const Trajectory & center, int radius) const
{
	assert(radius > 1.0);
	const double increment = 1.0 / (double)radius;

	// begin drawing
	glBegin(GL_LINE_LOOP);

	// go around the circle
	for (double radians = 0; radians < M_PI * 2.0; radians += increment)
		glVertex2f(center.getX() + (radius * cos(radians)),
		center.getY() + (radius * sin(radians)));

	// complete drawing
	glEnd();
}