#ifndef __BUTTON__
#define __BUTTON__

#include <string>
#include "GameObject.h"

class Button : public GameObject
{
public:
	Button(int x, int y, int width, int height, char textureID[], char buttonID[] = "UNDEFINED");
	virtual void update();
	virtual void draw();
	virtual void clean();
	virtual bool checkClicked() { return clicked; }
	virtual std::string getButtonID() { return buttonID; }

private:
	enum state{
		MouseOut = 1,
		MouseOver = 2
	};
	int state;
	bool clicked;
	std::string buttonID, textureID;
};
#endif