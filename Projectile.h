#ifndef __PROJECTILE__
#define __PROJECTILE__

#include "GameObject.h"


class Projectile : public GameObject
{
public:
	Projectile(int x, int y, int width, int height, std::string pTextureID);

	virtual void update() {}
	virtual void draw() {}
	virtual void clean() {}
	virtual void deleteCountdown(unsigned int time);

	virtual void stopMoving();
	virtual void markForDelete();
protected:
	unsigned int deathStart, deathCountdown;
	bool isMoving;
};
#endif