#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Enemy::Update()
{
    y += 1;
    x += 1;
    currentFrame = int(((SDL_GetTicks() / 100) % 6));
}
void Enemy::Clean()
{
}