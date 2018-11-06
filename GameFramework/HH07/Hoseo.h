#ifndef Hoseo_h
#define Hoseo_h
#include "SDLGameObject.h"
#include "LoaderParams.h"

class Hoseo : public SDLGameObject
{
public:
    Hoseo(const LoaderParams* pParams, float speed, float direction);
    virtual void Update();
    virtual void Clean();
private:
    void HandleInput();
};

#endif