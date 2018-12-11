#include "Animal.h"
#include "TextureManager.h"
#include "Camera.h"
#include "Enemy.h"
#include <iostream>

Animal::Animal(const LoaderParams& pParams) : SDLGameObject(pParams)
{
    state = FREE;
    enemy = nullptr;
    if (rand() % 2 == 1)
    {
        velocity.SetX((rand() % 3) * 0.8f + 1.6f);
    }
    else
    {
        velocity.SetX(-((rand() % 3) * 0.8f + 1.6f));
    }
}

void Animal::Draw()
{
    if (velocity.GetX() < 0)
    {
        TextureManager::Instance()->DrawFrame(textureID, int(position.GetX() - Camera::Instance()->GetX() + 0.5f), int(position.GetY() + 0.5f), width, height, currentRow, currentFrame, scale, SDL_FLIP_HORIZONTAL);
    }
    else
    {
        TextureManager::Instance()->DrawFrame(textureID, int(position.GetX() - Camera::Instance()->GetX() + 0.5f), int(position.GetY() + 0.5f), width, height, currentRow, currentFrame, scale);
    }
}

void Animal::Update()
{
    switch (state)
    {
    case FREE:
        currentFrame = int((SDL_GetTicks() / 100) % 6);
        SDLGameObject::Update();
        break;
    case HUNTED:
        position = enemy->GetPosition() + Vector2D(0, 16);
        if (position.GetY() < -100)
        {
            Destroy();
            return;
        }
        break;
    default:
        break;
    }
}

void Animal::Clean()
{
    SDLGameObject::Clean();
}

void Animal::Destroy()
{
    if (enemy != nullptr)
    {
        enemy->SetAnimal(nullptr);
    }
    SDLGameObject::Destroy();
}

void Animal::HuntedBy(Enemy* enemy_)
{
    state = HUNTED;
    enemy = enemy_;
    velocity.Zero();
}