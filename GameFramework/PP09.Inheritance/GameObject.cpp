#include "GameObject.h"
#include "TextureManager.h"

void GameObject::Load(int x, int y, int width, int height, std::string textureID)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->textureID = textureID;
    this->currentRow = 1;
    this->currentFrame = 1;
}

void GameObject::Draw(SDL_Renderer* pRenderer)
{
    TextureManager::Instance()->DrawFrame(textureID, x, y, width, height, currentRow, currentFrame, pRenderer);
}

void GameObject::Update()
{
    x += 1;
}

void GameObject::Clean()
{

}