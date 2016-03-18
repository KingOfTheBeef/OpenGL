#include <vector>
#include "GameObject.h"
#include "BaseGameState.h"
#include "Button.h"
class PauseGameState : public BaseGameState
{
public:
	virtual void update();
	virtual void draw();
	virtual void load();
	virtual void exit();
private:
	std::vector<Button*> m_buttonObjects;
	std::vector<GameObject*> m_gameObjects;
	bool b_PKeyDown;
	bool exitButtonClicked;
};