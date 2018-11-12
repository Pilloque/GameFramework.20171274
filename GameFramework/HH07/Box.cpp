#include "Box.h"
#include "InputHandler.h"
#include <iostream>

Box::Box(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

int Box::Update()
{
    //currentFrame = int(((SDL_GetTicks() / 100) % 2));
    SDLGameObject::Update();

    return 0;
}
void Box::Clean()
{
}

int Box::OnCollision(const GameObject& collider)
{
    if (collider.GetTag() == "hoseo" && currentFrame != 1)
    {
        currentFrame = 1;
    }
    return 0;
}
