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
	void newBullet(bool space);
	inline void killBird() { bird.kill(); } //kills the bird
	void killBullet(const int i);   //kills the bullet. Tracks which bullet.

private:
	int score;
	bool isHit;
	Bullet bullets[5];
	Bird bird;
	Gun gun;
	float getDistance(const Trajectory & rhs, const Trajectory & lhs);
};

#endif //SKEET_H

