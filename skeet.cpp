#include "stdafx.h"
#include "skeet.h"
#include <cstdlib>


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
		Trajectory forBird;
		forBird.setX(bird.getX());
		forBird.setY(bird.getY());

		Trajectory forBullet;
		forBullet.setX(bullets[i].getX());
		forBullet.setY(bullets[i].getY());

		if (getDistance(forBird, forBullet) < 10)
		{
			isHit = true;
			killBird();
			killBullet(i);
		}
	}
}

void Skeet::newBird()
{
	int randNum = rand() % 30;

	if (randNum == 0)
		bird.regenerate();
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
		//If 0, bullet isn't moving. Means it hasn't been initiallized. 
		if (bullets[i] == 0)
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
float Skeet::getDistance(const Trajectory & trajectory1, const Trajectory & trajectory2)
{
	float xDif = trajectory1.getX() - trajectory2.getX();
	float yDif = trajectory1.getY() + trajectory2.getY();

	float sumSquares = powf(xDif, 2) + powf(yDif, 2);

	return sqrtf(sumSquares);
}