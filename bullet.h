/***************************************************************
* File:
*     Bullet header
* Author
*     Brandon Ackerman
* Description:
*     This is the header file for the bullet class. Not like a
*     header in soccer. Never try to header a bullet. Not a good
*     idea. But this bullet is designed specifically to
*     obliterate pigeons in the game of Skeet.
***************************************************************/

#ifndef BULLET_H
#define BULLET_H

#include <math.h>
#include "trajectory.h"

class Bullet
{
public:
	//initializer
	Bullet() {}

	void move();
	void draw();

	//getters to the trajectory
	float getX()  { return trajectory.getX(); }
	float getY()  { return trajectory.getY(); }

	//kills the bullet. Sends it back to where it came from
	void resetBullet(float dx = 0.0, float dy = 0.0);

	//sets trajectory of the bullet equal to a given angle 
	Bullet & operator = (const float & rhs)
	{
		trajectory.setDX((float) - 10 * acos(rhs));
		trajectory.setDY((float) 10 * asin(rhs));

		return *this;
	}

	//the is equals operator, only compared the dx and dy
	//member variables in trajectory
	bool operator == (const float & rhs)
	{
		return (trajectory.getDX() == rhs || trajectory.getDY() == rhs);
	}

private:
	Trajectory trajectory;
};

#endif //BULLET_H
