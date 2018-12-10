#include "Player.h"
#include "InputHandler.h"
#include "Camera.h"

Player::Player(const LoaderParams& pParams) : SDLGameObject(pParams)
{
}

void Player::Draw()
{
    SDLGameObject::Draw();
}

void Player::Update()
{
    HandleInput();
    //Camera::Instance()->SetX(position.GetX() - 432);
    Camera::Instance()->Follow(position.GetX() - 432 + 45, 0.1f);
    currentFrame = int(((SDL_GetTicks() / 100) % 5));

    velocity += acceleration;
    position += velocity;
}

void Player::Clean()
{
    SDLGameObject::Clean();
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