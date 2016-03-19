#include <vector>
#include "BaseGameState.h"
#include "GameObject.h"

class MainMenuState : public BaseGameState
{
public:
	virtual void update();
	virtual void draw();
	virtual void load();
	virtual void exit();
private:
	void deleteGameObjects();
	std::vector<GameObject*> gameObjects;

};