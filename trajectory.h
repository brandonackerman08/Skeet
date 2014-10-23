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
#include <math.h>

#define deg2rad(value) ((M_PI / 180) * (value))

class Trajectory
{
public:

	//Trajectory will set everything to 0 unless specified. 
	//x and y can be specified, or x, y, dx, and dy.
	Trajectory() : dx(0.0), dy(0.0)  { }
	Trajectory(float x, float y, float dx = 0, float dy = 0);
	~Trajectory()   { }

	//getters
	float getX()       const { return x; }
	float getY()       const { return y; }
	float getDX()      const { return dx; }
	float getDY()      const { return dy; }
	bool  getCheck()   const { return check; }
	bool  isDead()     const { return dead; }
	float getXMin()    const { return xMin; }
	float getXMax()    const { return xMax; }
	float getYMin()    const { return yMin; }
	float getYMax()    const { return yMax; }
	bool  getWrap()    const { return wrap; }

	//setters
	void setX(float x)       { this->x = x; }
	void setY(float y)       { this->y = y; }
	void setDX(float dx)     { this->dx = dx; }
	void setDY(float dy)     { this->dy = dy; }
	void addX(float dx)      { setX(getX() + dx); }
	void addY(float dy)      { setY(getY() + dy); }
	void setCheck(bool f)    { check = f; }
	void setWrap(bool f)     { wrap = f; }
	void kill()              { dead = true; }
	void resurrect()         { dead = false; }

	Trajectory & operator = (const Trajectory & rhs);

private:
	float x;           // horizontal position
	float y;           // vertical position
	float dx;          // horizontal rate
	float dy;          // vertical rate
	bool  check;       // do bounds checking
	bool  dead;        // have we exceed our bounds?
	bool  wrap;        // do we wrap around the edge?
	static float xMin; // minimum extent of the x position
	static float xMax; // maximum extent of the x position
	static float yMin; // minimum extent of the y position
	static float yMax; // maximum extent of the y position
	
};

#endif