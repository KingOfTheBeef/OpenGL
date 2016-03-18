#include "MainMenuState.h"
#include "Drawer.h"
#include "Button.h"
#include "Game.h"
#include "PlayGameState.h"

void MainMenuState::load()
{
	Drawer::registerTexture("playbutton", "playbutton.png");
	Drawer::registerTexture("exitbutton", "exitbutton.png");
	Drawer::registerTexture("mainmenubackground", "background.jpg");

	GameObject* button = new Button(200, 80, 200, 100, "playbutton", "playgame");
	gameObjects.push_back(button);
	button = new Button(200, 200, 200, 100, "exitbutton" ,"exitgame");
	gameObjects.push_back(button);
}

void MainMenuState::update()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->update();
		if (Button* tempButton = dynamic_cast<Button*> (gameObjects[i]))
		{
			if (tempButton->checkClicked())
			{
				if (tempButton->getButtonID() == "playgame")
				{
					std::cout << "Play Game Button Pressed" << std::endl;
					Game::Instance()->changeState(new PlayGameState);
				}
				else if (tempButton->getButtonID() == "exitgame")
				{
					std::cout << "Exit Game Button Pressed" << std::endl;
					Game::Instance()->stopRunning();
				}
			}
		}
	}
}

void MainMenuState::deleteGameObjects()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i]->checkDelete())
		{
			gameObjects[i]->clean();
			delete(gameObjects[i]);
			gameObjects.erase(gameObjects.begin() + i);
		}
	}
}

void MainMenuState::draw()
{
	Drawer::drawGameObject(0, 0, 600, 400, "mainmenubackground");
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->draw();
	}
}

void MainMenuState::exit()
{
	Drawer::unregisterTexture("playbutton");	Drawer::unregisterTexture("exitbutton");
	Drawer::unregisterTexture("mainmenubackground");
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->clean();
		delete(gameObjects[i]);
		gameObjects.erase(gameObjects.begin() + i);
	}
}