#include "Projectile.h"

class Bullet : public Projectile
{
public:
	Bullet(int x, int y, int width, int height, std::string pTextureID);

	virtual void update();
	virtual void draw();
	virtual void clean();
private:

	int direction;
};