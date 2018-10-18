#include "Enemy.h"

void Enemy::Load(int x, int y, int width, int height, std::string textureID)
{
    GameObject::Load(x, y, width, height, textureID);
}

void Enemy::Draw(SDL_Renderer* pRenderer)
{
    GameObject::Draw(pRenderer);
}

void Enemy::Update()
{
    x += 1;
    y += 1;
    currentFrame = int((SDL_GetTicks() / 100) % 6);
}