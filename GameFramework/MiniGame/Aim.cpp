#include "Aim.h"
#include "InputHandler.h"

Aim::Aim(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Aim::Draw()
{
    SDLGameObject::Draw();
}

void Aim::Update()
{
    position = InputHandler::Instance()->GetMousePosition();
}

void Aim::Clean()
{
    SDLGameObject::Clean();
}
