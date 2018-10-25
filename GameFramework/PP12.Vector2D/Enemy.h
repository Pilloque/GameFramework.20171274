#ifndef Enemy_h
#define Enemy_h
#include "SDLGameObject.h"
#include "LoaderParams.h"

class Enemy : public SDLGameObject
{
public:
    Enemy(const LoaderParams* pParams);
    virtual void Update();
    virtual void Clean();
};

#endif