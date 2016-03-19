#include <SDL.h>
#include <string>
#include <iostream>
#include <map>


static class Drawer
{
public:
	static void drawGameObject(int pX, int pY, int pWidth, int pHeight, std::string pTextureID, bool pFlip = false);
	static void drawFrame(int pX, int pY, int pWidth, int pHeight, std::string pTextureID, int pRow, int pFrame, bool pFlip = false);
	static void drawRect(SDL_Rect* rect, Uint8 red = 0, Uint8 green = 0, Uint8 blue = 0, Uint8 alpha = 255);

	static void setRenderer(SDL_Renderer* pRenderer);
	static void registerTexture(std::string pTextureID, char pFilename[]);
	static void unregisterTexture(std::string pTextureID);

private:
	static SDL_Renderer* renderer;
	static std::map<std::string, SDL_Texture*> textureMap;
};