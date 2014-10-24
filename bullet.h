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

	//kills the bullet. Sends it back to where it came from
	void resetBullet(float dx = 0.0, float dy = 0.0);

	void getTrajectory(Trajectory & trajectory)
	{
		Trajectory(trajectory);
	}

private:
	Trajectory trajectory;
};

#endif //BULLET_H
