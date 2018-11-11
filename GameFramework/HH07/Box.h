#ifndef Box_h
#define Box_h
#include "SDLGameObject.h"
#include "LoaderParams.h"

class Box : public SDLGameObject
{
public:
    Box(const LoaderParams* pParams);
    virtual int Update();
    virtual void Clean();

private:
};

#endif