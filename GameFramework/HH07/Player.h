#ifndef Player_h
#define Player_h
#include "SDLGameObject.h"
#include "LoaderParams.h"

class Player : public SDLGameObject
{
public:
    Player(const LoaderParams* pParams);
    virtual void Update();
    virtual void Clean();
private:
    void HandleInput();
    std::vector<GameObject*> balls;
};


#endif