#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Enemy::Update()
{
    position += Vector2D(1.0f, 1.0f);

    currentFrame = int(((SDL_GetTicks() / 100) % 6));
}
void Enemy::Clean()
{
}