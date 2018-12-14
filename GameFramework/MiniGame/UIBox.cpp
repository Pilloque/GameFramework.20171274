#include "UIBox.h"
#include "TextureManager.h"

UIBox::UIBox(const LoaderParams& pParams) : SDLGameObject(pParams)
{
}

void UIBox::Draw()
{
    TextureManager::Instance()->Draw(textureID, int(position.GetX() + 0.5f), int(position.GetY() + 0.5f), width, height, scale, SDL_FLIP_NONE);
}

void UIBox::Update()
{

}

void UIBox::Clean()
{
    SDLGameObject::Clean();
}