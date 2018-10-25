#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams)
{
    this->x = pParams->GetX();
    this->y = pParams->GetY();
    this->width = pParams->GetWidth();
    this->height = pParams->GetHeight();
    this->textureID = pParams->GetTextureID();
    this->currentRow = 1;
    this->currentFrame = 0;
}

void SDLGameObject::Draw()
{
    TextureManager::Instance()->DrawFrame(textureID, x, y, width, height, currentRow, currentFrame, Game::Instance()->GetRenderer());
}

void SDLGameObject::Update()
{
}

void SDLGameObject::Clean()
{
}