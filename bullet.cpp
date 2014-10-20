/***************************************************************
* File:
*     Bullet code
* Author
*     Brandon Ackerman
* Description:
*     This is the cpp file for the bullet class. Just some code.
*     nothing too fancy. The bullet has a trajectory, and it
*     can be moved and drawn.
***************************************************************/

#include "stdafx.h"
#include "bullet.h"
#include "glDefines.h"

/*****************************************************************
* I'm pretty sure the destructor would be inherently created,
* but to be sure, I just made it. It doesn't do anything in
* particular. Just makes sure it gets deleted.
*****************************************************************/
Bullet::~Bullet()
{
}


/********************************************************************
* setTrajectory will set the position and rate of change for the
* bullet. Since Trajectory is a class all on its own, there are
* member functions from Trajectory that are called in order to set
* the Trajectory. I like saying Trajectory.
********************************************************************/
void Bullet::setTrajectory(float angle)
{
	trajectory.setDX(10 * (int)acos(angle));
	trajectory.setDY(10 * (int)asin(angle));
}

/********************************************************************
* Basically uninitallizes a bullets. Sends it back into the gun.
* it's in the gun if dx and dy are 0.0
********************************************************************/
void Bullet::setTrajectory(float dx, float dy)
{
	trajectory.setDX(dx);
	trajectory.setDY(dy);
	trajectory.setX(trajectory.getPoint().getXMin());
	trajectory.setY(trajectory.getPoint().getYMin());
}

/***************************************************************
* move will take the bullet and move it. I know it's tough to
* understand. Basically, newX = x + dx and newY = y + dy.
* The point plus change.
****************************************************************/
inline void Bullet::move()
{
	trajectory.setX(trajectory.getX() + trajectory.getDX());
	trajectory.setY(trajectory.getY() + trajectory.getDY());
}


/********************************************************************
* Bullet::draw is actually taken almost exactly from the uiDraw
* library that was given, but it was made to work within the defined
* class. It makes it so only the draw functions that are needed for
* skeet are included.
********************************************************************/
void Bullet::draw()
{
	glBegin(GL_POINTS);

	// Go...
	glVertex2f(trajectory.getX(), trajectory.getY());
	glVertex2f(trajectory.getX() + 1, trajectory.getY());
	glVertex2f(trajectory.getX() + 1, trajectory.getY() + 1);
	glVertex2f(trajectory.getX(), trajectory.getY() + 1);

	// Done!  OK, that was a bit too dramatic
	glEnd();
}