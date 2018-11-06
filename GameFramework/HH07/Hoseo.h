#ifndef Hoseo_h
#define Hoseo_h
#include "SDLGameObject.h"
#include "LoaderParams.h"

class Hoseo : public SDLGameObject
{
public:
    Hoseo(const LoaderParams* pParams, const Vector2D mousePos, float speed);
    virtual void Draw();
    virtual void Update();
    virtual void Clean();
private:
    void HandleInput();
};

#endif