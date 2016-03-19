#include "Arrow.h"
#include "Drawer.h"
#include <iostream>

Arrow::Arrow(int pX, int pY, int pWidth, int pHeight, std::string pTextureID, bool pDirection) : Projectile(pX,pY,pWidth,pHeight,pTextureID)
{
	if (pDirection == ARROWLEFT)
		direction = 1;
	else
		direction = -1;
	ID = "ARROW";
	toDelete = false;
}

void Arrow::update()
{
	if ((x + width > 600 || x < 0) && isMoving)
	{
		Projectile::stopMoving();
	}
	if (isMoving)
		x += (8 * direction);
	Projectile::deleteCountdown(5000);
	updateBoundingBox();
}

void Arrow::draw()
{
	Drawer::drawGameObject(x, y, width, height, textureID, (direction > 0) ? false : true);
}

void Arrow::clean()
{

}