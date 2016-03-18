#include <vector>
#include "GameObject.h"
#include "BaseGameState.h"
#include "MovableBlock.h"

class PlayGameState : public BaseGameState
{
public:
	virtual void update();
	virtual void draw();
	virtual void load();
	virtual void exit();
	virtual void gainedFocus();
	void deleteObjects();
private:
	std::vector<GameObject*> m_gameObjects;
	std::vector<GameObject*> m_projectiles;
	MovableBlock* player;
	bool b_PKeyDown;
	bool b_Space;
};