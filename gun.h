/***********************************************************************
* Header File:
*    Gun
* Author:
*    Robbie Bise and Brandon Ackerman
* Summary:
*    Declairations for the gun class for our skeet game
************************************************************************/

#include "point.h" // access to point class
#include "uiDraw.h" // draw rectangle
#define validatePosition() validatePositionProc(__FILE__ , __LINE__)

class Gun
{
public:
	//Constructors
	Gun();              //Default Constructor *We really don't need any
	                    //other ones right?

	void move(int up, int down); // tilt gun up or down
	                    // (same as set angle?)

	void draw() const { drawRect(gun, 10, 85, angle); }      // draw the gun

	//Setters
	void setGun();      // access to the gun point?
	// i took set angle out because move does that.

	//Getters
	int getAngle() const { return angle; }    // this we will need for bullet
	void getGun();      // access to the point?

private:
	//Private Member Variables 
	Point gun;               //position of the gun. Should this also be const?
	int const MAX_TILT_UP = 90;  //maximum degrees we can rotate
	int const MAX_TILT_DOWN = 0; // minimim degrees we can rotate
	int static angle;                   // current angle of the gun
	// this is static becasue we don't want anything to re-initilize angle. It stays 
	// the same for the whole game. 

	//Private member function
	void validatePositionProc(const char * file, int line); // validate should not need any parameters 
	                         //because "this" is implied


};