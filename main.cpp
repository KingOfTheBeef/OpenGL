// Battle Royale

#include <iostream>
#include <vector>
#include "SDL.h"
#include "Drawer.h"
#include "InputHandler.h"
#include "Game.h"

const int FPS = 60;
const float DELAY_TIME = 1000.0f / FPS;

int main(int argc, char *args[])
{
	Uint32 frameStart, frameTime;

	std::cout << "Entry Point Success" << std::endl;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* m_mainWindow = SDL_CreateWindow("Battle Royale Version 1.xx", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer* m_renderer = SDL_CreateRenderer(m_mainWindow, -1, 0);
	Drawer::setRenderer(m_renderer);
	Game::Instance();


	// load
	{
		bool running = true;
		while (running)
		{
			frameStart = SDL_GetTicks();

			InputHandler::Instance()->update();
			running = Game::Instance()->checkRunning();
			Game::Instance()->update();

			SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
			SDL_RenderClear(m_renderer);
			Game::Instance()->draw();
			SDL_RenderPresent(m_renderer);


			frameTime = SDL_GetTicks() - frameStart;
			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}
		Game::Instance()->clean();
	}

	return 0;
}
