#include "Aim.h"
#include "TextureManager.h"
#include "InputHandler.h"

Aim::Aim(const LoaderParams& pParams) : SDLGameObject(pParams)
{
}

void Aim::Draw()
{
    TextureManager::Instance()->Draw(textureID, int(position.GetX() + 0.5f) - 5 * scale, int(position.GetY() + 0.5f) - 5 * scale, width, height, scale, SDL_FLIP_NONE);
}

void Aim::Update()
{
    position = InputHandler::Instance()->GetMousePosition();
}

void Aim::Clean()
{
    SDLGameObject::Clean();
}
