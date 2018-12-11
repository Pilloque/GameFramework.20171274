#include "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams& pParams, int animSpeed, int numFrames) : SDLGameObject(pParams), animSpeed(animSpeed), numFrames(numFrames)
{
}

void AnimatedGraphic::Update()
{
    if (animSpeed != 0)
    {
        currentFrame = int((SDL_GetTicks() / (1000 / animSpeed)) % numFrames);
    }
}