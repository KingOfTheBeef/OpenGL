#include <SDL.h>
#include <utility>

enum
{
	MOUSE_LEFT = 0,
	MOUSE_RIGHT = 1,
	MOUSE_MIDDLE = 2,
	MAXBUTTONS = 3
};

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (!ThisInputHandler)
			ThisInputHandler = new InputHandler();
		return ThisInputHandler;
	}

	void update();

	bool testKey(SDL_Scancode scancode);
	int getMouseX();
	int getMouseY();
	// Use enums to test button
	bool testMouseButton(int pWhichButton);
	void resetMouseButtons();
	
private:
	InputHandler() {};

	void updateKeyboard();
	void updateMouseMotion(SDL_Event);
	void updateMouseButtonUp(SDL_Event);
	void updateMouseButtonDown(SDL_Event);

	const Uint8* keyboard;
	int mouseX, mouseY;
	bool mouseButtons[MAXBUTTONS];
	//std::pair<int, int> mouseCoordiantes;

	static InputHandler* ThisInputHandler;
};