#ifndef Aim_h
#define Aim_h
#include "SDLGameObject.h"

class Aim : public SDLGameObject
{
public:
    Aim(const LoaderParams* pParams);
    virtual void Draw();
    virtual void Update();
    virtual void Clean();
};

#endif