#ifndef Missile_h
#define Missile_h
#include "SDLGameObject.h"

class Missile :public SDLGameObject
{
public:
    Missile(const LoaderParams& pParams, double angle);
    virtual void Draw();
    virtual void Update();
    virtual void Clean();

private:
    double angle;
};

#endif