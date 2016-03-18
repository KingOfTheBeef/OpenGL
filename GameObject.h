#include <string>
#include <SDL.h>
#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

class GameObject
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
	virtual bool checkDelete() { return toDelete; }
	virtual void onCollision() {};
	SDL_Rect getBoundingBox() { return boundingBox; }
	std::string getID() { return ID; }
	void updateBoundingBox() { boundingBox.x = x; boundingBox.y = y; }
protected:
	std::string ID;
	double  x, y;
	int width, height, frame, row;
	bool toDelete;
	std::string textureID;
	SDL_Rect boundingBox;
};

#endif