#include <SDL_image.h>
#include "Drawer.h"

SDL_Renderer* Drawer::renderer = 0;
std::map<std::string, SDL_Texture*> Drawer::textureMap;

void Drawer::setRenderer(SDL_Renderer* pRenderer)
{
	Drawer::renderer = pRenderer;
}

void Drawer::registerTexture(std::string pTextureID, char pFilename[])
{

	SDL_Surface* pTemporarySurface = IMG_Load(pFilename);
	textureMap[pTextureID] = SDL_CreateTextureFromSurface(renderer, pTemporarySurface);
	SDL_FreeSurface(pTemporarySurface);
}

void Drawer::unregisterTexture(std::string pTextureID)
{
	std::map<std::string, SDL_Texture*>::iterator iter = Drawer::textureMap.find(pTextureID);

	if (iter == Drawer::textureMap.end())
	{
		std::cout << "Could not unregister TextureID (Does not exist): " << pTextureID << std::endl;
		return;
	}
	Drawer::textureMap.erase(iter);
}

void Drawer::drawGameObject(int pX, int pY, int pWidth, int pHeight, std::string pTextureID, bool pFlip)
{
	SDL_Rect srcRect, destRect;
	srcRect.x = 0;
	srcRect.y = 0;
	destRect.x = pX;
	destRect.y = pY;
	srcRect.w = destRect.w =pWidth;
	srcRect.h = destRect.h = pHeight;

	SDL_RenderCopyEx(Drawer::renderer, Drawer::textureMap[pTextureID], &srcRect, &destRect, 0, 0, (pFlip) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

void Drawer::drawFrame(int pX, int pY, int pWidth, int pHeight, std::string pTextureID, int pRow, int pFrame, bool pFlip)
{
	SDL_Rect srcRect, destRect;
	srcRect.x = pWidth * (pFrame);
	srcRect.y = pHeight * (pRow - 1);
	destRect.x = pX;
	destRect.y = pY;
	srcRect.w = destRect.w = pWidth;
	srcRect.h = destRect.h = pHeight;

	SDL_RenderCopyEx(Drawer::renderer, Drawer::textureMap[pTextureID], &srcRect, &destRect, 0, 0, (pFlip) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE); 
}

void Drawer::drawRect(SDL_Rect* rect, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
{
	SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
	SDL_RenderDrawRect(renderer, rect);
}