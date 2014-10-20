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

class Bullet
{
public:
	//initializer
	Bullet();

	//destroy them
	~Bullet();

	//the move and draw functions
	//they move and draw the bullet. Revolutionary
	void move(int enter);
	void draw();

	//makes it so you can set the trajectory for your
	//bullet. Only needs the angle of the gun.
	void setTrajectory(float angle);
	void setTrajectory(float dx = 0.0, float dy = 0.0);
	Trajectory getTrajectory()  { return trajectory; }

private:
	Trajectory trajectory;
};

#endif //BULLET_H
