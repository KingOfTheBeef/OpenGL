
#ifndef __BASEGAMESTATE__
#define __BASEGAMESTATE__
class BaseGameState
{
public:
	BaseGameState() { deleted = false; }
	bool isDeleted() { return deleted; }
	void isDeleted(bool pDeleted) { deleted = pDeleted; }
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void load() = 0;
	virtual void exit() = 0;
	virtual void gainedFocus() {}
protected:
	bool deleted;
};
#endif