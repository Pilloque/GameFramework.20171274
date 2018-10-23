#include "Enemy.h"

void Enemy::Update()
{
    x += 1;
    y += 1;
    currentFrame = int((SDL_GetTicks() / 100) % 6);
}