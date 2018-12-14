#ifndef UIBox_h
#define UIBox_h
#include "SDLGameObject.h"

class UIBox : public SDLGameObject
{
public:
    UIBox(const LoaderParams& pParams);
    virtual void Draw();
    virtual void Update();
    virtual void Clean();
};

#endif