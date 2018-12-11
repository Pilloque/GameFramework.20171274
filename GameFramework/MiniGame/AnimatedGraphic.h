#ifndef AnimatedGraphic_h
#define AnimatedGraphic_h
#include "SDLGameObject.h"

class AnimatedGraphic : public SDLGameObject
{
public:
    AnimatedGraphic(const LoaderParams& pParams, int animSpeed, int numFrames);
    virtual void Update();

private:
    const int animSpeed;
    const int numFrames;
};

#endif