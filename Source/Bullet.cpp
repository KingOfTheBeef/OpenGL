#include "Bullet.h"
#include "Drawer.h"
#include <SDL.h>

Bullet::Bullet(int pX, int pY, int pWidth, int pHeight, std::string pTextureID) : Projectile(pX, pY, pWidth, pHeight, pTextureID)
{
	frame = 1;
	row = 1;
	ID = "BULLET";
}

void Bullet::draw()
{
	Drawer::drawFrame(x, y, width, height, textureID, row, frame);
}

void Bullet::update()
{
	frame = (SDL_GetTicks() / 100) % 4;
	x += 10;
}

void Bullet::clean()
{

}