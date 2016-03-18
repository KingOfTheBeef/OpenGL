#include <iostream>
#include "Game.h"
#include "MainMenuState.h"


Game* Game::s_Game = 0;

Game* Game::Instance()
{
	if (!s_Game)
		s_Game = new Game();
	return s_Game;
}

Game::Game()
{
	m_gameStates.push_back(new MainMenuState);
	m_gameStates.back()->load();
	running = true;
}

void Game::update()
{
	// for (int i = m_gameStates.size(); i > 0; i--)
	m_gameStates.back()->update();
	Game::deleteState();
}

void Game::draw()
{
	m_gameStates.back()->draw();
}

void Game::clean()
{

}

void Game::pushState(BaseGameState* newState)
{
	m_gameStates.push_back(newState);
	m_gameStates.back()->load();
}

void Game::popState()
{
	m_gameStates.back()->exit();
	m_gameStates.back()->isDeleted(true);
	stateBin.push_back(m_gameStates.back());
	m_gameStates.pop_back();
	m_gameStates.back()->gainedFocus();
}

void Game::changeState(BaseGameState* newState)
{
	m_gameStates.back()->isDeleted(true);
	stateBin.push_back(m_gameStates.back());
	m_gameStates.pop_back();
	Game::pushState(newState);
	std::cout << "1) Current State Stack Size: " << m_gameStates.size() << std::endl;
}

void  Game::deleteState()
{
	for (int i = 0; i < stateBin.size(); i++)
	{
		delete(stateBin[i]);
		stateBin.erase(stateBin.begin() + i);
	}

	/*
	if (m_gameStates.front()->isDeleted())
	{
		std::cout << "We are Deleting" << std::endl;
		m_gameStates.front()->exit();
		m_gameStates.erase(m_gameStates.begin());
		std::cout << "2) Current State Stack Size: " << m_gameStates.size() << std::endl;
	}
	*/
}