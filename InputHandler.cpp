#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::ThisInputHandler = 0;

void InputHandler::update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case (SDL_MOUSEMOTION) :
			updateMouseMotion(event);
			break;
		case (SDL_MOUSEBUTTONDOWN) :
			updateMouseButtonDown(event);
			break;
		case (SDL_MOUSEBUTTONUP) :
			updateMouseButtonUp(event);
			break;
		case (SDL_QUIT) :
			Game::Instance()->stopRunning();
			break;
		}
		updateKeyboard();
	}
}

void InputHandler::updateKeyboard()
{
	keyboard = SDL_GetKeyboardState(0);
}

void InputHandler::updateMouseMotion(SDL_Event pEvent)
{
	mouseX = pEvent.motion.x;
	mouseY = pEvent.motion.y;
}

void InputHandler::updateMouseButtonDown(SDL_Event pEvent)
{
	if (pEvent.button.button == SDL_BUTTON_LEFT)
		mouseButtons[MOUSE_LEFT] = true;
	else if (pEvent.button.button == SDL_BUTTON_RIGHT)
		mouseButtons[MOUSE_RIGHT] = true;
	else if (pEvent.button.button == SDL_BUTTON_MIDDLE)
		mouseButtons[MOUSE_MIDDLE] = true;
}

void InputHandler::updateMouseButtonUp(SDL_Event pEvent)
{
	if (pEvent.button.button == SDL_BUTTON_LEFT)
		mouseButtons[MOUSE_LEFT] = false;
	else if (pEvent.button.button == SDL_BUTTON_RIGHT)
		mouseButtons[MOUSE_RIGHT] = false;
	else if (pEvent.button.button == SDL_BUTTON_MIDDLE)
		mouseButtons[MOUSE_MIDDLE] = false;
}

bool InputHandler::testMouseButton(int pWhichButton)
{
	if (pWhichButton <= 3 && pWhichButton >= 0)
	{
		return mouseButtons[pWhichButton];
	}

	return false;
}

bool InputHandler::testKey(SDL_Scancode pScancode)
{
	if (keyboard[pScancode])
		return keyboard[pScancode];
	return false;
}

int InputHandler::getMouseX()
{
	return mouseX;
}

int InputHandler::getMouseY()
{
	return mouseY;
}

void InputHandler::resetMouseButtons()
{
	for (int i = 0; i < MAXBUTTONS; i++)
	{
		mouseButtons[i] = false;
	}
}