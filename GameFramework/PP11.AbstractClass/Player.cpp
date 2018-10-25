#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Player::Update()
{
    x -= 1;
    currentFrame = int((SDL_GetTicks() / 100) % 6);
}

void Player::Clean()
{
}