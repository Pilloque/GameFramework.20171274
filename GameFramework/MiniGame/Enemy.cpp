#include "Enemy.h"
#include "InputHandler.h"

Enemy::Enemy(const LoaderParams& pParams) : SDLGameObject(pParams)
{
    velocity.SetX(0.001f);
    velocity.SetY(2);
}

void Enemy::Draw()
{
    SDLGameObject::Draw();
}

void Enemy::Update()
{
    currentFrame = int(((SDL_GetTicks() / 100) % 5));
    if (position.GetY() < 0)
    {
        velocity.SetY(2);
    }
    else if (position.GetY() > 400)
    {
        velocity.SetY(-2);
    }
    SDLGameObject::Update();
}

void Enemy::Clean()
{
    SDLGameObject::Clean();
}