#include "stdafx.h"
#include "skeet.h"
#include <algorithm>
#include <cstdlib>
using namespace std;


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
	bird.draw(10);

	gun.draw(5,20);

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
		Trajectory forBird;
		bird.getTrajectory(forBird);

		Trajectory forBullet;
		bullets[i].getTrajectory(forBullet);

		if (getDistance(forBird, forBullet) < 10)
		{
			isHit = true;
			killBird();
			killBullet(i);
		}
	}
}

void Skeet::killBird()
{

}

/**********************************************************
* killBullet will reset the bullet back to an initial 
* position without any direction. Once it is fired, 
* it will be given direction and magnitude, oh yeah.
**********************************************************/
void Skeet::killBullet(const int i)
{
	bullets[i].resetBullet();
	isHit = false;                //resets bullet that hit bird
}

/*************************************************************
* newBullet will put a bullet onto the screen. It does this
* by setting dx and dy in the trajectory of the bullet.
*************************************************************/
void Skeet::newBullet(bool space)
{
	bool isSpace = true;
	for (int i = 0; space; i++)
	{
		Trajectory bulletTrajectory;     //the getTrajectory function needs 
		bullets[i].getTrajectory(bulletTrajectory);//to be passed by reference

		//If 0, bullet isn't moving. Means it hasn't been initiallized. 
		if (bulletTrajectory == 0)
		{
			bullets[i] = deg2rad(gun.getAngle());  //sets trajectory
			isSpace = false;                       //from gun angle
		}
	}
}

/*************************************************************
* getDistance will perfrom the square root sum of squares.
* I know this is not very cohesive, it's coupling. But
* math.h didn't have the function I needed.
*************************************************************/
float Skeet::getDistance(const Trajectory & rhs, const Trajectory & lhs)
{
	float dxdy[4];
	dxdy[0] = rhs.getDX();
	dxdy[1] = rhs.getDY();
	dxdy[2] = lhs.getDX();
	dxdy[3] = lhs.getDY();

	float m = 1 / *max_element(dxdy, dxdy + 4);

	float minDist = 20;   //just a distance greater than what kills a bird

	for (float i = 0; i < 1; i += m)
	{
		float xDif = (rhs.getX() + (rhs.getDX() * i)) - 
			         (lhs.getX() + (lhs.getDX() * i));

		float yDif = (rhs.getY() + (rhs.getDY() * i)) - 
			         (lhs.getY() + (lhs.getDY() * i));

		float dist = sqrtf((xDif * xDif + yDif * yDif));    //root sum squares

		minDist = min(minDist, dist);                       //checks minDist against current distance
	}

	return minDist;
}