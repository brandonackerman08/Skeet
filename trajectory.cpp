/***************************************************************
* Program:
*     Trajectory
* Author
*     Brandon Ackerman
* Description:
*     This is the cpp file for the trajectory class.
***************************************************************/

#include "stdafx.h"
#include "Trajectory.h"


/***************************************************************
* the only thing that isn't inline is the initiallization
* of the point and dx, dy. This will take input with dx and
* dy having default values. Most won't use the default values,
* but they are there.
***************************************************************/
Trajectory::Trajectory(float x, float y, int dx, int dy)
{
	this->point.setX(x);
	this->point.setY(y);
	this->dx = dx;
	this->dy = dy;
}
