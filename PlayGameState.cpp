#include "PlayGameState.h"
#include "Drawer.h"
#include "MovableBlock.h"
#include "PauseGameState.h"
#include "InputHandler.h"
#include "Game.h"
#include "Arrow.h"
#include "GameObject.h"
#include "Barrel.h"

bool testCollision(GameObject* object1, GameObject* object2);

void PlayGameState::update()
{
	for (int i = 0; i < m_projectiles.size(); i++)
	{
		m_projectiles[i]->update();
	}
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
		if (m_gameObjects[i]->getID() == "BARREL")
		{
			for (int j = 0; j < m_projectiles.size(); j++)
			{
				if (testCollision(m_gameObjects[i], m_projectiles[j]))
				{
					m_gameObjects[i]->onCollision();
				}
			}
		}
	}

	/*
	if (m_gameObjects[i]->getID() == "BARREL")
	{
		for (int j = 0; j < m_projectiles.size(); j++)
		{
			if (m_projectiles[j] != 0 || !m_projectiles[j]->checkDelete())
			{
				if (testCollision(m_gameObjects[i], m_projectiles[j]))
				{
					Barrel* barrel = dynamic_cast<Barrel*> (m_gameObjects[i]);
					barrel->explode();
				}
			}
		}
	}
	*/

	if (!InputHandler::Instance()->testKey(SDL_SCANCODE_P) && b_PKeyDown)
		b_PKeyDown = false;

	if (InputHandler::Instance()->testKey(SDL_SCANCODE_P) && !b_PKeyDown)
	{
		Game::Instance()->pushState(new PauseGameState());
	}

	if (InputHandler::Instance()->testKey(SDL_SCANCODE_SPACE))
		b_Space = true;

	if (!InputHandler::Instance()->testKey(SDL_SCANCODE_SPACE) && b_Space)
	{
		GameObject* arrow = new Arrow(player->getX() + 20, player->getY() + 10, 31, 5, "arrow", player->getDeltaX() < 0 ? ARROWRIGHT : ARROWLEFT);
		// m_gameObjects.push_back(arrow);
		m_projectiles.push_back(arrow);
		b_Space = false;
	}
}

void PlayGameState::draw()
{
	Drawer::drawGameObject(0, 0, 600, 400, "background");
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	for (int i = 0; i < m_projectiles.size(); i++)
	{
		m_projectiles[i]->draw();
	}

	deleteObjects();
}

void PlayGameState::deleteObjects()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		if (m_gameObjects[i]->checkDelete())
		{
			m_gameObjects[i]->clean();
			delete(m_gameObjects[i]);
			m_gameObjects[i] = 0;
			m_gameObjects.erase(m_gameObjects.begin() + i);
		}
	}
	for (int i = 0; i < m_projectiles.size(); i++)
	{
		if (m_projectiles[i]->checkDelete())
		{
			m_projectiles[i]->clean();
			delete(m_projectiles[i]);
			m_projectiles[i] = 0;
			m_projectiles.erase(m_projectiles.begin() + i);
		}
	}
}

void PlayGameState::load()
{
	Drawer::registerTexture("background", "playgamebackground.jpg");
	Drawer::registerTexture("player", "soldier.bmp");
	Drawer::registerTexture("arrow", "arrow.png");
	Drawer::registerTexture("barrel", "barrel.png");
	Drawer::registerTexture("explode", "explode.png");
	MovableBlock* tPlayer = new MovableBlock(100, 100, 38, 53, "player");
	player = tPlayer;
	m_gameObjects.push_back(player);
	GameObject* barrel = new Barrel(400, 300);
	m_gameObjects.push_back(barrel);
	b_Space = false;
}

void PlayGameState::exit()
{
	Drawer::unregisterTexture("background");
	Drawer::unregisterTexture("player");
}

void PlayGameState::gainedFocus()
{
	b_PKeyDown = true;
	b_Space = false;
}

bool testCollision(GameObject* object1, GameObject* object2)
{
	if (!object1->checkDelete() || !object2->checkDelete())
	{
		if (object1->getBoundingBox().x + object1->getBoundingBox().w < object2->getBoundingBox().x)
			return false;
		if (object1->getBoundingBox().x > object2->getBoundingBox().x + object2->getBoundingBox().w)
			return false;
		if (object1->getBoundingBox().y + object1->getBoundingBox().h < object2->getBoundingBox().y)
			return false;
		if (object1->getBoundingBox().y > object2->getBoundingBox().y + object2->getBoundingBox().h)
			return false;
		std::cout << "object 2 = " << object2->getBoundingBox().x << std::endl;
		return true;
	}
	return false;
}