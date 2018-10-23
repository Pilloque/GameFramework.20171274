#ifndef Monster_h
#define Monster_h
#include "GameObject.h"

class Monster : public GameObject
{
public:
    void Draw(SDL_Renderer* pRenderer);
    void Update();
    void SetVelocity(int vel);

private:
    const int directionCycle = 2000;
    unsigned int nextShift;
    int xvel = 1;
};


#endif