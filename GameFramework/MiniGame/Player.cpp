#include "Player.h"
#include "InputHandler.h"
#include <iostream>

constexpr float PI = 3.1415926535897932384626433832795f;

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Player::Draw()
{
    SDLGameObject::Draw();
}

void Player::Update()
{
    HandleInput();
    currentFrame = int(((SDL_GetTicks() / 100) % 5));
    SDLGameObject::Update();
}

void Player::Clean()
{
}

void Player::HandleInput()
{
    Vector2D direction;

    if (InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_RIGHT) || InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_D))
    {
        direction.SetX(1.0f);
    }
    else if (InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_LEFT) || InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_A))
    {
        direction.SetX(-1.0f);
    }

    if (InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_UP) || InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_W))
    {
        direction.SetY(-1.0f);
    }
    else if (InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_DOWN) || InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_S))
    {
        direction.SetY(1.0f);
    }
    velocity += direction.Normalized() * speed;
    velocity *= 0.92f;
}