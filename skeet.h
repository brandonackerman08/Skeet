#ifndef SKEET_H
#define SKEET_H

#include "bird.h"
#include "bullet.h"
#include "gun.h"

class Skeet
{
public:
	Skeet();
	~Skeet();
	void setIsHit();
	void draw();
	void move();
	void interact(int up, int down, int left, int right);
	void newBird();
	void newBullet(bool space);
	void killBird();                //kills the bird
	void killBullet(const int i);   //kills the bullet. Tracks which bullet.
	float getDistance(const Trajectory & trajectory1, const Trajectory & trajectory2);

private:
	int score;
	bool isHit;
	Bullet bullets[5];
	Bird bird;
	Gun gun;
};

#endif //SKEET_H

