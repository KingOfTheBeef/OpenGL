#include <SDL.h>
#include "Projectile.h"
#include <iostream>

Projectile::Projectile(int pX, int pY, int pWidth, int pHeight, std::string pTextureID)
{
	x = boundingBox.x = pX;
	y = boundingBox.y = pY;
	width = boundingBox.w = pWidth;
	height = boundingBox.h = pHeight;
	toDelete = false;
	isMoving = true;
	textureID = pTextureID;
}

void Projectile::deleteCountdown(unsigned int time)
{
	if (!isMoving)
	{
		deathCountdown +=  SDL_GetTicks() - deathCountdown;
		if (deathCountdown >= (deathStart + time))
		{
			markForDelete();
		}
	}
}

void Projectile::stopMoving()
{
	deathCountdown = SDL_GetTicks();
	deathStart = deathCountdown;
	std::cout << "deathCountdown: " << deathCountdown << "\ndeathStart: " << deathStart << std::endl;
	isMoving = false;
	
}

void Projectile::markForDelete()
{
	toDelete = true;
}