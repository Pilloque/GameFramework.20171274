#include "Box.h"
#include "InputHandler.h"
#include <iostream>

Box::Box(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

int Box::Update()
{
    currentFrame = int(((SDL_GetTicks() / 100) % 2));
    SDLGameObject::Update();

    return 0;
}
void Box::Clean()
{
}