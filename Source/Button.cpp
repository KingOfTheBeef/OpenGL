#include "Button.h"
#include "Drawer.h"
#include "InputHandler.h"

Button::Button(int pX, int pY, int pWidth, int pHeight, char pTextureID[] ,char pButtonID[])
{
	x = pX;
	y = pY;
	width = pWidth;
	height = pHeight;
	state = 1;
	toDelete = false;
	clicked = false;
	buttonID = pButtonID;
	textureID = pTextureID;
}

void Button::draw()
{
	Drawer::drawFrame(x, y, width, height, textureID, 1, state - 1);
}

void Button::update()
{
	if (InputHandler::Instance()->getMouseX() > x && InputHandler::Instance()->getMouseX() < x + width && InputHandler::Instance()->getMouseY() > y && InputHandler::Instance()->getMouseY() < y + height)
		state = MouseOver;
	else
		state = MouseOut;
	if (InputHandler::Instance()->testMouseButton(MOUSE_LEFT) && state == MouseOver)
		clicked = true;
	else
		clicked = false;
}
void Button::clean() {}

