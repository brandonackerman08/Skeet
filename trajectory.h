/***************************************************************
* File:
*     Trajectory Header
* Author
*     Brandon Ackerman
* Description:
*     This is the header file for the Trajectory class. The
*     trajectory class stores a point (referencing the Point
*     class) and the change in x and y (known as dx and dy,
*     from calculus- meaning differential. Key word- different.)
***************************************************************/

#ifndef TRAJECTORY_H
#define TRAJECTORY_H

#include <iostream>
#include <string>
#include <cassert>
#include "point.h"

class Trajectory
{
public:

	//Trajectory will set everything to 0 unless specified. 
	//x and y can be specified, or x, y, dx, and dy.
	Trajectory() : dx(0), dy(0)  { }
	Trajectory(float x, float y, int dx = 0, int dy = 0);
	~Trajectory()   { }

	//getters
	float getX()   const            { return point.getX(); }
	float getY()   const            { return point.getY(); }
	int getDX()    const            { return dx; }
	int getDY()    const            { return dx; }

	//setters
	void setX(float x)              { point.setX(x); }
	void setY(float y)              { point.setY(y); }
	void setDX(int dx)              { this->dx = dx; }
	void setDY(int dy)              { this->dy = dy; }

private:
	Point point;
	int dx;
	int dy;
};

#endif