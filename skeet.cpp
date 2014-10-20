#include "stdafx.h"
#include "skeet.h"


Skeet::Skeet()
{
}


Skeet::~Skeet()
{
}

void Skeet::move()
{
	//move the bird
	bird.move();

	//move the bullet
	for (int i = 0; i < 5; i++)
		bullets[i].move();
}

void Skeet::draw()
{
	bird.draw();

	gun.draw();

	for (int i = 0; i < 5; i++)
		bullets[i].draw();
}

void Skeet::interact(int up, int down, int left, int right)
{
	gun.move(up, down, left, right);
}

void Skeet::setIsHit()
{
	for (int i = 0; i < 5; i++)
	{
		if (getDistance(bullets[i].getTrajectory().getPoint(),
			bird.getTrajectory().getPoint()) < 20)
		{
			isHit = true;
			killBird();
			killBullet();
		}
	}
}

void Skeet::newBird()
{
	bird.Bird();
}

void Skeet::killBird()
{
	bird.~Bird();
}

void Skeet::killBullet()
{
	for (int i = 0; isHit; i++)
	{
		if (getDistance(bullets[i].getTrajectory().getPoint(),
			bird.getTrajectory().getPoint()) < 20)
		{
			bullets[i].setTrajectory();
			isHit = false;
		}
	}
}

/*************************************************************
* newBullet will put a bullet onto the screen. It does this
* by setting dx and dy in the trajectory of the bullet.
*************************************************************/
void Skeet::newBullet(bool isSpace)
{
	bool isSpace = true;
	for (int i = 0; isSpace; i++)
	{
		//checks to see if dx is zero. If bullet isn't moving, that 
		//means it has not been initiallized.
		if (bullets[i].getTrajectory().getDX == 0)
		{
			bullets[i].setTrajectory(gun.getAngle());  //might need to be changed once I see the gun class. 
			isSpace = false;
		}
	}
}

/*************************************************************
* getDistance will perfrom the square root sum of squares.
* I know this is not very cohesive, it's coupling. But
* math.h didn't have the function I needed.
*************************************************************/
float Skeet::getDistance(const Point point1, const Point point2)
{
	float xDif = point1.getX() + point2.getX();
	float yDif = point1.getY() + point2.getY();

	float sumSquares = powf(xDif, 2) + powf(yDif, 2);

	return sqrtf(sumSquares);
}