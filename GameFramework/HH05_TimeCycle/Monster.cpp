#include "Monster.h"
#include "TextureManager.h"

void Monster::Update()
{
    if (SDL_GetTicks() > nextTurn)
    {
        xvel = -xvel;
        nextTurn = SDL_GetTicks() + turnCycle;
    }
    x += xvel;
    currentFrame = int((SDL_GetTicks() / 100) % 4);
}

void Monster::SetVelocity(int vel)
{
    this->xvel = (-1) * vel;
}