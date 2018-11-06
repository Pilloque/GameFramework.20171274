#include "Player.h"
#include "InputHandler.h"
#include "Game.h"
#include "Hoseo.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Player::Update()
{
    velocity = Vector2D(0.0f, 0.0f);
    HandleInput();
    currentFrame = int((SDL_GetTicks() / 100) % 6);
    SDLGameObject::Update();
}

void Player::Clean()
{
}

void Player::HandleInput()
{
    if (InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_RIGHT) || InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_D))
    {
        velocity.SetX(2);
    }
    if (InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_LEFT) || InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_A))
    {
        velocity.SetX(-2);
    }
    if (InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_UP) || InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_W))
    {
        velocity.SetY(-2);
    }
    if (InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_DOWN) || InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_S))
    {
        velocity.SetY(2);
    }
    if (InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_SPACE) || InputHandler::Instance()->GetMouseButtonState(LEFT))
    {
        if (SDL_GetTicks() > nextFire)
        {
            Game::Instance()->GenerateObject(new Hoseo(new LoaderParams(position.GetX(), position.GetY(), 100, 100, "hoseo"), *InputHandler::Instance()->GetMousePosition(), 10.0f));
            nextFire = SDL_GetTicks() + fireRate;
        }
    }
}