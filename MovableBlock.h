#ifndef __MOVABLEOBJECT__
#define __MOVABLEOBJECT__

#include "GameObject.h"

class MovableBlock : public GameObject
{
public:
	MovableBlock(int px, int py, int pwidth, int pheight, std::string pTextureID);

	virtual void draw();
	virtual void update();
	virtual void clean();

	void setX(int pX) { x = pX; }
	double  getX() { return x; }
	void setY(int pY) { y = pY; }
	double  getY() { return y; }

	void setDeltaX(int pX) { deltaX = pX; }
	int getDeltaX() { return deltaX; }
	void setDeltaY(int pY) { deltaY = pY; }
	int getDeltaY() { return deltaY; }

private:
	int deltaX, deltaY;
	std::string textureID;
};
#endif