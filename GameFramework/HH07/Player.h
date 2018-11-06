#ifndef Player_h
#define Player_h
#include "SDLGameObject.h"
#include "LoaderParams.h"
#include <vector>

class Player : public SDLGameObject
{
public:
    Player(const LoaderParams* pParams);
    virtual void Update();
    virtual void Clean();
private:
    void HandleInput();
    Uint32 nextFire = 0;
    const Uint32 fireRate = 500;
};


#endif