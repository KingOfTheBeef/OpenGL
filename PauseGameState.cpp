#include "PauseGameState.h"
#include "Drawer.h"
#include "Button.h"
#include "Game.h"
#include "MainMenuState.h"
#include "InputHandler.h"

void PauseGameState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	for (int i = 0; i < m_buttonObjects.size(); i++)
	{
		m_buttonObjects[i]->update();
		if (m_buttonObjects[i]->checkClicked() && m_buttonObjects[i]->getButtonID() == "exitButton")
		{
			Game::Instance()->popState();
			Game::Instance()->changeState(new MainMenuState());
			InputHandler::Instance()->resetMouseButtons();
		}
	}
	if (!InputHandler::Instance()->testKey(SDL_SCANCODE_P) && b_PKeyDown)
		b_PKeyDown = false;

	if (InputHandler::Instance()->testKey(SDL_SCANCODE_P) && !b_PKeyDown)
	{
		Game::Instance()->popState();
	}

	if (exitButtonClicked)
	{
		std::cout << "Hello.." << std::endl;
	}
}

void PauseGameState::draw()
{
	Drawer::drawGameObject(0, 0, 600, 400, "background");
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	for (int i = 0; i < m_buttonObjects.size(); i++)
	{
		m_buttonObjects[i]->draw();
	}
}

void PauseGameState::load()
{
	Drawer::registerTexture("exitbutton", "exitbutton.png");
	Button* button = new Button(200, 100, 200, 100, "exitbutton", "exitButton");
	m_buttonObjects.push_back(button);
	b_PKeyDown = true;
	exitButtonClicked = false;
}

void PauseGameState::exit()
{
	Drawer::unregisterTexture("exitbutton");
	// Drawer::unregisterTexture("background");
}