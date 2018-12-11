#include "Carrcass.h"

Carrcass::Carrcass(const LoaderParams& pParams) : SDLGameObject(pParams)
{
    acceleration.SetY(0.4f);
    TimeToDestroy = SDL_GetTicks() + 500u;
}

void Carrcass::Draw()
{
    SDLGameObject::Draw();
}

void Carrcass::Update()
{
    if (SDL_GetTicks() > TimeToDestroy)
    {
        Destroy();
    }

    if (position.GetY() < 410.0f)
    {
        SDLGameObject::Update();
    }
    else if (position.GetY() > 410.0f)
    {
        acceleration.Zero();
        velocity.Zero();
        position.SetY(410.0f);
    }

}

void Carrcass::Clean()
{
    SDLGameObject::Clean();
}