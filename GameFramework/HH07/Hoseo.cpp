#include "Hoseo.h"
#include "InputHandler.h"
#define PI 3.1415926535897932384626433832795

Hoseo::Hoseo(const LoaderParams* pParams, float speed, float direction) : SDLGameObject(pParams)
{

    velocity = Vector2D(speed * SDL_cos(direction * PI / 180), speed * SDL_sin(direction * PI / 180));
}

void Hoseo::Update()
{
    //HandleInput();
    SDLGameObject::Update();
}

void Hoseo::Clean()
{
}

void Hoseo::HandleInput()
{

}