#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Player::Update()
{
    currentFrame = int((SDL_GetTicks() / 100) % 6);
    acceleration.SetX(1.0f);
    acceleration.SetY(0.0f);
    SDLGameObject::Update();
}

void Player::Clean()
{
}