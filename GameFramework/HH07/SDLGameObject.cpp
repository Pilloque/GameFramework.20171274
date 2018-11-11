#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams), position(pParams->GetX(), pParams->GetY()), velocity(0.0f, 0.0f), acceleration(0.0f, 0.0f)
{
    this->width = pParams->GetWidth();
    this->height = pParams->GetHeight();
    this->textureID = pParams->GetTextureID();
    this->currentRow = 1;
    this->currentFrame = 0;
}

void SDLGameObject::Draw()
{
    TextureManager::Instance()->DrawFrame(textureID, int(position.GetX() + 0.5), int(position.GetY() + 0.5), width, height, currentRow, currentFrame, Game::Instance()->GetRenderer());
}

int SDLGameObject::Update()
{
    velocity += acceleration;
    position += velocity;
    
    return 0;
}

void SDLGameObject::Clean()
{
}