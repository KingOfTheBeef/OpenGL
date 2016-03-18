#include "Drawer.h"
#include "Barrel.h"
#include <SDL.h>

Barrel::Barrel(int pX, int pY)
{
	boundingBox.x = x = pX;
	boundingBox.y = y = pY;
	boundingBox.w = width = 43;
	boundingBox.h = height = 61;
	textureID = "barrel";
	state = stable;
	toDelete = false;
	ID = "BARREL";
}

void Barrel::draw()
{
	// std::cout << "Hello" << std::endl;
	switch (state)
	{
	case (stable):
		Drawer::drawGameObject(boundingBox.x, boundingBox.y, boundingBox.w, boundingBox.h, textureID);
		break;
	case (exploding) :
		Drawer::drawFrame(x, y, 100, 100, "explode", 1, frame);
	}
}

void Barrel::explode()
{
	if (state != exploding && state != deleting)
	{
		state = exploding;
		frame = 1;
		start = SDL_GetTicks();
		current = start;
		std::cout << "Orig X: " << x << "Orig Y: " << y << std::endl;
		y -= ((100 + y - (y + height)) / 2);
		x -= ((100 + x - (x + width)) / 2);
		std::cout << "new X: " << x << "new Y: " << y << std::endl;
	}

}

void Barrel::update()
{
	current += SDL_GetTicks() - current;
	switch (state)
	{
	case (exploding) :
		if (current > start + 40)
		{
			start = current;
			frame += 1;
		}
		break;
	case (deleting) :
		toDelete = true;
		break;
	}
	if (state == exploding && frame > 4)
	{
		state = deleting;
	}

}

void Barrel::onCollision()
{
	explode();
}