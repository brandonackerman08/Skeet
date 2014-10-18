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
#include "trajectory.h"
#define validatePosition() validatePositionProc(__FILE__ , __LINE__)

class Bird
{
public:
	//Constructors
	Bird();              //Default Constructor 

	void move(); // uses trajectory to "move" the bird

	void draw() const { drawCircle(bird, 10); }      // draw bird

	// so isdead is accessed through point. dx and dy will be accessed through trajectory
	// and the bird's location is also stored in point. we really only need two member 
	// functions plus the constructor and validate yes?

private:
	//Private Member Variables 
	Point bird;               //position of the bird
	Trajectory trajectory; // direction and velosity of bird

	//Private member function
	void validatePositionProc(const char * file, int line); // validate should not need any parameters 
	//because "this" is implied


};