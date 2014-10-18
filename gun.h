/***********************************************************************
* Header File:
*    Gun
* Author:
*    Robbie Bise and Brandon Ackerman
* Summary:
*    Declairations for the gun class for our skeet game
************************************************************************/



class Gun
{
public:
	//Constructors
	Gun() : angle(45) {} //Default Constructor *We really don't need any
	                     //other ones right?
	move(isUp, isDown);  // tilt gun up or down (same as set angle?)
	draw();              // draw the gun
	//Setters
	setGun();            // access to the gun point?
	setAngle();          // is this necessary? allows move to set angle?
	//Getters
	getAngle();          // this we will need for bullet
	getGun();            // access to the point

private:
	//Private Member Variables 
	Point gun; //position of the gun. Should this also be const?
	int const MAX_TILT_UP = 90; //maximum degrees we can rotate
	int const MAX_TILT_DOWN = 0; // minimim degrees we can rotate
	int angle // current angle of the gun
    
	//Private member function
	void validatePosition() // validate should not need any parameters 
	                        //because "this" is implie


};