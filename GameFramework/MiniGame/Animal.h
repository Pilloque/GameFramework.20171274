#ifndef Animal_h
#define Animal_h
#include "SDLGameObject.h"

class Animal : public SDLGameObject
{
public:
    Animal(const LoaderParams& pParams);
    virtual void Draw();
    virtual void Update();
    virtual void Clean();
};

#endif