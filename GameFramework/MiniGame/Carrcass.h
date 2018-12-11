#ifndef Carrcass_h
#define Carrcass_h
#include "SDLGameObject.h"

class Carrcass : public SDLGameObject
{
public:
    Carrcass(const LoaderParams& pParams);
    virtual void Draw();
    virtual void Update();
    virtual void Clean();

    Uint32 TimeToDestroy;
};

#endif