#include "Missile.h"
#include "TextureManager.h"
#include "Camera.h"

Missile::Missile(const LoaderParams& pParams, double angle) : SDLGameObject(pParams), angle(angle)
{
    acceleration = Vector2D(-SDL_cosf(float(angle * M_PI / 180)), -SDL_sinf(float(angle * M_PI / 180))) * 0.1f;
}

void Missile::Draw()
{
    TextureManager::Instance()->Draw(textureID, int(position.GetX() - Camera::Instance()->GetX() + 0.5f), int(position.GetY() + 0.5f), width, height, scale, angle, SDL_FLIP_HORIZONTAL);
}

void Missile::Update()
{
    velocity += acceleration;
    position += velocity;
}

void Missile::Clean()
{
    SDLGameObject::Clean();
}