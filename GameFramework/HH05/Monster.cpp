#include "Monster.h"
#include "TextureManager.h"

void Monster::Draw(SDL_Renderer* pRenderer)
{
    TextureManager::Instance()->DrawFrame(textureID, x, y, width, height, currentRow, currentFrame, pRenderer);
}

void Monster::Update()
{
    if (SDL_GetTicks() > nextShift)
    {
        x = -x;
        nextShift = SDL_GetTicks() + directionCycle;
    }
    x += xvel;
    currentFrame = int((SDL_GetTicks() / 100) % 6);
}

void Monster::SetVelocity(int vel)
{
    this->xvel = vel;
}