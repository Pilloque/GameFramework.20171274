#include "Enemy.h"
#include "InputHandler.h"
#include "Animal.h"
#include <iostream>

Enemy::Enemy(const LoaderParams& pParams) : SDLGameObject(pParams)
{
    state = APPROACH;
    animal = nullptr;
    velocity.SetX(0.5f * (rand() % 3) - 0.5f);
    velocity.SetY(2);
}

void Enemy::Draw()
{
    SDLGameObject::Draw();
}

void Enemy::Update()
{
    switch (state)
    {
    case APPROACH:
        if (position.GetY() > 390)
        {
            velocity.Zero();
            state = HUNT;
        }
        break;
    case RUN:
        if (position.GetY() < -100)
        {
            Destroy();
            return;
        }
        break;
    default:
        break;
    }

    SDLGameObject::Update();
}

void Enemy::Clean()
{
    SDLGameObject::Clean();
}

void Enemy::Destroy()
{
    if (animal != nullptr)
    {
        animal->Destroy();
    }
    SDLGameObject::Destroy();
}

void Enemy::SetStateRun()
{
    state = RUN;
    velocity.SetX(0.5f * (rand() % 3) - 0.5f);
    velocity.SetY(-2);
}