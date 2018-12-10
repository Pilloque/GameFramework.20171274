#ifndef Background_h
#define Background_h
#include "SDLGameObject.h"

class Background : public SDLGameObject
{
public:
    Background(const LoaderParams* pParams);
    virtual void Draw();
    virtual void Update();
    virtual void Clean();
};

#endif