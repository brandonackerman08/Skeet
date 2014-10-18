/***********************************************************************
* Header File:
*    Gun
* Author:
*    Robbie Bise and Brandon Ackerman
* Summary:
*    Declairations for the gun class for our skeet game
************************************************************************/

#include "point.h"

class Gun
{
public:
	//Constructors
	Gun();              //Default Constructor *We really don't need any
	                    //other ones right?
	void move(bool isUp, bool isDown); // tilt gun up or down
	                    // (same as set angle?)
	void draw();        // draw the gun

	//Setters
	void setGun();      // access to the gun point?
	void setAngle();    // is this necessary? allows move to set angle?
	//Getters
	void getAngle();    // this we will need for bullet
	void getGun();      // access to the point

private:
	//Private Member Variables 
	Point gun; //position of the gun. Should this also be const?
	int const MAX_TILT_UP = 90; //maximum degrees we can rotate
	int const MAX_TILT_DOWN = 0; // minimim degrees we can rotate
	int angle; // current angle of the gun

		//Private member function
		void validatePosition(); // validate should not need any parameters 
	                        //because "this" is implie


};