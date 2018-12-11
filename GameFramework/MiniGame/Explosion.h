#ifndef Explosion_h
#define Explosion_h
#include "SDLGameObject.h"

class Explosion : public SDLGameObject
{
public:
    Explosion(const LoaderParams& pParams);
    virtual void Draw();
    virtual void Update();
    virtual void Clean();

private:
    Uint32 nextFrameTime;
    const unsigned int frameSpeed;
};

#endif