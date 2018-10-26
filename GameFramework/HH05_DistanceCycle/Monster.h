#ifndef Monster_h
#define Monster_h
#include "GameObject.h"

class Monster : public GameObject
{
public:
    void Update();
    void SetVelocity(int vel);

private:
    const int turnCycle = 400;
    int displacement;
    int xvel = 1;
};
#endif