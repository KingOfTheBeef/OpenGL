#include "MovableBlock.h"
#include "Drawer.h"
#include "InputHandler.h"
MovableBlock::MovableBlock(int px, int py, int pwidth, int pheight, std::string pTextureID) : textureID(pTextureID), deltaX(0), deltaY(0)
{
	x = boundingBox.x = px;
	y = boundingBox.y = py;
	width = boundingBox.w = pwidth;
	height = boundingBox.h = pheight;
	toDelete = false;
	ID = "MOVABLEBLOCK";
}

void MovableBlock::draw()
{
	Drawer::drawGameObject(x, y, width, height, textureID);
}

void MovableBlock::update()
{
	deltaX = deltaY = 0;
	if (InputHandler::Instance()->testKey(SDL_SCANCODE_W))
		deltaY = -2;
	if (InputHandler::Instance()->testKey(SDL_SCANCODE_A))
		deltaX = -2;
	if (InputHandler::Instance()->testKey(SDL_SCANCODE_S))
		deltaY = 2;
	if (InputHandler::Instance()->testKey(SDL_SCANCODE_D))
		deltaX = 2;
	 x += deltaX;
	 y += deltaY;
}

void MovableBlock::clean()
{

}