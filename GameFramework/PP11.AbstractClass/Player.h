#ifndef Player_h
#define Player_h
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
    Player(const LoaderParams* pParams);
    virtual void Update();
    virtual void Clean();
};


#endif