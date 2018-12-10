#include "Background.h"
#include "Camera.h"

Background::Background(const LoaderParams& pParams) : SDLGameObject(pParams)
{
}

void Background::Draw()
{
    SDLGameObject::Draw();
}

void Background::Update()
{
    if (position.GetX() < Camera::Instance()->GetX() - 864)
    {
        position += Vector2D(864 * 2, 0);
    }
    else if (position.GetX() > Camera::Instance()->GetX() + 864)
    {
        position -= Vector2D(864 * 2, 0);
    }
}

void Background::Clean()
{
    SDLGameObject::Clean();
}
