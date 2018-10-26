#include "Monster.h"
#include "TextureManager.h"

void Monster::Update()
{
    if (displacement > 256 || displacement < 0)
    {
        xvel = -xvel;
    }
    x += xvel;
    displacement += xvel;

    currentFrame = int((SDL_GetTicks() / 100) % 4);
}

void Monster::SetVelocity(int vel)
{
    this->xvel = vel;
}