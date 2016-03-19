#include <vector>
#include "BaseGameState.h"


class Game
{
public:
	static Game* Instance();
	void update();
	void draw();
	void clean();

	// state based
	void pushState(BaseGameState* newState);
	void changeState(BaseGameState* newState);
	void popState();
	BaseGameState* getCurrentState() { return m_gameStates.back(); }
	void stopRunning() { running = false; }
	bool checkRunning() { return running; }

private:
	Game();
	void deleteState();
	std::vector<BaseGameState*> m_gameStates;
	std::vector<BaseGameState*> stateBin;
	static Game* s_Game;
	bool running;
};