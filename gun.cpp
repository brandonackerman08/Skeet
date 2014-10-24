/***********************************************************************
* CPP File:
*    Gun
* Author:
*    Robbie Bise and Brandon Ackerman
* Summary:
*    Definitions for the gun class for our skeet game
************************************************************************/
#include <iostream> //cin cout cerr
#include <cstdlib> // for exit in validate
#include "gun.h"

int Gun::angle = 45;

/***********************************************************************
* Gun
* Default constructor for the gun class
************************************************************************/
Gun::Gun() 
{
	trajectory.setX(trajectory.getXMax()); // gun will go on the far right side
	trajectory.setY(trajectory.getYMin()); // at the bottom of the screen
	validatePosition();
}

/***********************************************************************
* Move
* Take in to account if the up or down arrow is pressed and move gun
* accordingly.
************************************************************************/
void Gun::move(int up, int down, int left, int right)
{
	validatePosition(); // make sure gun is in an ok position

	if (up && angle <= MAX_TILT_UP)
		angle -= (up   + 9) / 5; // if up move up
	if (down && angle >= MAX_TILT_DOWN)
		angle += (down + 9) / 5; // if down move down

	if (right && angle <= MAX_TILT_UP)
		angle -= (right + 9) / 5; // same as up
	if (left && angle >= MAX_TILT_DOWN)
		angle += (left + 9) / 5; // same as down

	if (angle > MAX_TILT_UP)
		angle = MAX_TILT_UP;
	if (angle < MAX_TILT_DOWN)
		angle = MAX_TILT_DOWN;
	
	validatePosition(); // check gun position again
	
}

//Setters

void Gun :: validatePositionProc(const char * file, int line)
{
	char something;
                     //90                    //0
	if (angle > MAX_TILT_UP || angle < MAX_TILT_DOWN)
	{
		std::cerr << "Error in file: " << file << " at line: " << line << ".\n"
			<< "gun angle: " << angle <<" is outside valid range\n";
		std::cin >> something;
		exit (1);
	}
	
}

void Gun::draw(const Trajectory & center, int width, 
	           int height, int rotation) const
{
	Trajectory tl(false /*check*/); // top left
	Trajectory tr(false /*check*/); // top right 
	Trajectory bl(false /*check*/); // bottom left
	Trajectory br(false /*check*/); // bottom right

	//Top Left point
	tl.setX(center.getX() - (width / 2));
	tl.setY(center.getY() + (height / 2));

	//Top right point
	tr.setX(center.getX() + (width / 2));
	tr.setY(center.getY() + (height / 2));

	//Bottom left point
	bl.setX(center.getX() - (width / 2));
	bl.setY(center.getY() - (height / 2));

	//Bottom right point
	br.setX(center.getX() + (width / 2));
	br.setY(center.getY() - (height / 2));

	//Rotate all points the given degrees
	rotate(tl, center, rotation);
	rotate(tr, center, rotation);
	rotate(bl, center, rotation);
	rotate(br, center, rotation);

	//Finally draw the rectangle
	glBegin(GL_LINE_STRIP);
	glVertex2f(tl.getX(), tl.getY());
	glVertex2f(tr.getX(), tr.getY());
	glVertex2f(br.getX(), br.getY());
	glVertex2f(bl.getX(), bl.getY());
	glVertex2f(tl.getX(), tl.getY());
	glEnd();
}

/************************************************************************
* ROTATE
* Rotate a given point (point) around a given origin (center) by a given
* number of degrees (angle).
*    INPUT  point    The point to be moved
*           center   The center point we will rotate around
*           rotation Rotation in degrees
*    OUTPUT point    The new position
*************************************************************************/
void rotate(Trajectory & point, const Trajectory & origin, int rotation)
{
	// because sine and cosine are expensive, we want to call them only once
	double cosA = cos(deg2rad(rotation));
	double sinA = sin(deg2rad(rotation));

	// remember our original point
	Point tmp(false /*check*/);
	tmp.setX(point.getX() - origin.getX());
	tmp.setY(point.getY() - origin.getY());

	// find the new values
	point.setX((tmp.getX() * cosA -
		tmp.getY() * sinA) +
		origin.getX());
	point.setY((tmp.getX() * sinA +
		tmp.getY() * cosA) +
		origin.getY());
}