/*

// load
Drawer::setRenderer(m_renderer);
Drawer::registerTexture("arrow", "arrow.png");
Drawer::registerTexture("player", "soldier.bmp");
Drawer::registerTexture("bullet", "bullet.png");
Drawer::registerTexture("barrel", "barrel.png");
Drawer::registerTexture("explode", "explode.png");
Drawer::registerTexture("playbutton", "playbutton.png");
SDL_Rect testRect;
testRect.x = 100;
testRect.y = 100;
testRect.h = 100;
testRect.w = 100;
std::vector<GameObject*> m_gameObjects;

MovableBlock* player = new MovableBlock(250, 300, 38, 53, "player");
m_gameObjects.push_back(player);
GameObject* barrel = new Barrel(200, 200);
m_gameObjects.push_back(barrel);
GameObject* button = new Button(100, 100);
m_gameObjects.push_back(button);


{
	bool quit = false;
	while (!quit)
	{
		frameStart = SDL_GetTicks();

		InputHandler::Instance()->update(quit);
		// SPACE
		if (InputHandler::Instance()->testKey(SDL_SCANCODE_SPACE))
		{
			spacePressed = true;
		}
		else if ((!InputHandler::Instance()->testKey(SDL_SCANCODE_SPACE)) && spacePressed)
		{
			GameObject* arrow = new Arrow(player->getX() + 10, player->getY() + 5, 31, 5, "arrow", player->getDeltaX() > 0 ? ARROWLEFT : ARROWRIGHT);
			m_gameObjects.push_back(arrow);
			spacePressed = false;
		}
		// ENTER
		if (InputHandler::Instance()->testKey(SDL_SCANCODE_RETURN))
		{
			returnPressed = true;
		}
		else if ((!InputHandler::Instance()->testKey(SDL_SCANCODE_RETURN)) && returnPressed)
		{
			GameObject* bullet = new Bullet(player->getX() + 10, player->getY() + 5, 25, 20, "bullet");
			m_gameObjects.push_back(bullet);
			returnPressed = false;
		}
		//player->setDeltaY((InputHandler::Instance()->getMouseY() - player->getY()) / 10);
		for (int i = 0; i < m_gameObjects.size(); i++)
		{
			m_gameObjects[i]->update();
			if (dynamic_cast<Button*> (m_gameObjects[i]))
			{
				if (dynamic_cast<Button*> (m_gameObjects[i])->checkClicked())
				{
					if (barrel != 0)
					{
						Barrel* barrel2 = dynamic_cast<Barrel*> (barrel);
						barrel2->explode();
						barrel = 0;
					}
				}
			}
		}

		SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
		SDL_RenderClear(m_renderer);
		for (int i = 0; i < m_gameObjects.size(); i++)
		{
			m_gameObjects[i]->draw();
		}
		// Drawer::drawRect(&testRect);

		SDL_RenderPresent(m_renderer);

		// Cleaning
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

		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}
	}
}
Drawer::unregisterTexture("player");
player->clean();
delete(player);

return 0;
}

double SQUARE(double num)
{
	return num * num;
}
*/