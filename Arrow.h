#include "GameObject.h"
#include "Projectile.h"

#define ARROWLEFT true
#define ARROWRIGHT false

class Arrow : public Projectile
{
public:
	Arrow(int x, int y, int width, int height, std::string pTextureID, bool pDirection);

	virtual void update();
	virtual void draw();
	virtual void clean();
private:

	int direction;
};