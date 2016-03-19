#include <string>
#include <SDL.h>
#include "Structure.h"

class Barrel : public Structure
{
public:
	Barrel(int pX, int pY);

	virtual void update();
	virtual void draw();
	virtual void clean() {}
	virtual void explode();
	virtual void onCollision();
private:
	enum states{
		stable = 0,
		exploding = 1,
		deleting = 2
	};

	std::string textureID;
	int state;
	unsigned int start, current;
};