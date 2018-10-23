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
    const int turnCycle = 2000;
    unsigned int nextTurn;
    int xvel = -1;
};


#endif