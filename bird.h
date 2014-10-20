/***********************************************************************
* Header File:
*    Bird
* Author:
*    Robbie Bise and Brandon Ackerman
* Summary:
*    Declairations for the bird class for our skeet game
************************************************************************/

#include "point.h" // access to point class
#include "uiDraw.h" // draw rectangle
#include "trajectory.h" // so the bird can move
#define validatePosition() validatePositionProc(__FILE__ , __LINE__)

class Bird
{
public:
	//Constructors
	Bird();              //Default Constructor Don't know what this should be yet.

	void move(); // uses trajectory to "move" the bird

	void regenerate();  // reset the birds position and give it a random direction. 

	void draw() const { drawCircle(bird, 10); }      // draw bird

private:
	//Private Member Variables 

	Point bird;               //position of the bird

	Trajectory trajectory; // direction and velosity of bird

	//Private member function
	void validatePositionProc(const char * file, int line); 


};