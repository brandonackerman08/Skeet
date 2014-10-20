#ifndef SKEET_H
#define SKEET_H

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
	void newBullet(bool isSpace);
	void killBird();       //kills the bird
	void killBullet();     //kills the bullet
	float getDistance(const Point point1, const Point point2);

private:
	int score;
	bool isHit;
	Bullet bullets[5];
	Bird bird;
	Gun gun;
};

#endif //SKEET_H

