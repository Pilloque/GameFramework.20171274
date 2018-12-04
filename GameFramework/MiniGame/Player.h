#ifndef Player_h
#define Player_h
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
    Player(const LoaderParams* pParams);
    virtual void Draw();
    virtual void Update();
    virtual void Clean();

private:
	void HandleInput();

    const float speed = 0.3f;
};

#endif