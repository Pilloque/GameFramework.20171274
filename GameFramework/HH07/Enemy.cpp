#include "Enemy.h"
#include "InputHandler.h"
#include <iostream>

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Enemy::Update()
{
    //velocity = Vector2D(0.0f, 0.0f);
    HandleInput();
    //position += Vector2D(1.0f, 1.0f);
    currentFrame = int(((SDL_GetTicks() / 100) % 6));
    SDLGameObject::Update();
}
void Enemy::Clean()
{
}

void Enemy::HandleInput()
{
    Vector2D* vec = InputHandler::Instance()->GetMousePosition();
    velocity = ((*vec - Vector2D(width / 2, height / 2)) - position) / 50;
    if (InputHandler::Instance()->GetMouseButtonState(LEFT))
    {
        velocity += Vector2D(1.0f, 0.0f);
    }
}