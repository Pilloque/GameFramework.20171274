#include "Hoseo.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "Game.h"

Hoseo::Hoseo(const LoaderParams* pParams, Vector2D mousePos, float speed) : SDLGameObject(pParams)
{
    Vector2D direction = mousePos - Vector2D(pParams->GetWidth() / 2, pParams->GetHeight() / 2) - this->position;
    direction.Normalize();
    velocity = direction * speed;
}

void Hoseo::Draw()
{
    TextureManager::Instance()->Draw(textureID, int(position.GetX() + 0.5), int(position.GetY() + 0.5), width, height, Game::Instance()->GetRenderer());
}

int Hoseo::Update()
{
    //HandleInput();
    SDLGameObject::Update();
    if (this->position.GetX() > 640 || this->position.GetY() > 480
        || this->position.GetX() < 0 || this->position.GetY() < 0)
    {
        Game::Instance()->DestroyObject(this);
        delete this;
        return 1;
    }
    return 0;
}

void Hoseo::Clean()
{
}

void Hoseo::HandleInput()
{

}