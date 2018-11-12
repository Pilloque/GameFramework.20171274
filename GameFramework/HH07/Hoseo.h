#ifndef Hoseo_h
#define Hoseo_h
#include "SDLGameObject.h"
#include "LoaderParams.h"

class Hoseo : public SDLGameObject
{
public:
    Hoseo(const LoaderParams* pParams, const Vector2D mousePos, float speed);
    virtual void Draw();
    virtual int Update();
    virtual void Clean();
    virtual int OnCollision(const GameObject& collider);

private:
    void HandleInput();
};

#endif