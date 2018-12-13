#include "TextPrinter.h"
#include "Game.h"
#include <SDL_image.h>

TextPrinter* TextPrinter::pInstance = nullptr;

void TextPrinter::Init()
{
}

bool TextPrinter::Load(std::string fileName, std::string id)
{
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
	if (pTempSurface == 0)
	{
		return false;
	}
	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(Game::Instance()->GetRenderer(), pTempSurface);
	SDL_FreeSurface(pTempSurface);

	if (pTexture != 0)
	{
		charMap[id] = pTexture;
		return true;
	}

	return false;
}

void TextPrinter::Draw(std::string id, int x, int y, int width, int height, float scale)
{
	Draw(id, x, y, width, height, scale, 0);
}

void TextPrinter::Draw(std::string id, int x, int y, int width, int height, float scale, double angle)
{
	SDL_Rect srcRect;
	SDL_Rect dstRect;

	srcRect.x = 0;
	srcRect.y = 0;
	dstRect.x = x;
	dstRect.y = y;

	srcRect.w = width;
	srcRect.h = height;
	dstRect.w = int(width * scale);
	dstRect.h = int(height * scale);

	SDL_RenderCopyEx(Game::Instance()->GetRenderer(), charMap[id], &srcRect, &dstRect, angle, 0, SDL_FLIP_NONE);
}

void TextPrinter::ClearFromCharMap(std::string id)
{
	SDL_DestroyTexture(charMap[id]);
	charMap.erase(id);
}