#ifndef Enemy_h
#define Enemy_h
#include "SDLGameObject.h"

enum enemy_state
{
    APPROACH = 0,
    HUNT = 1,
    RUN = 2
};

class Animal;

class Enemy : public SDLGameObject
{
public:
    Enemy(const LoaderParams& pParams);
    virtual void Draw();
    virtual void Update();
    virtual void Clean();
    virtual void Destroy();
    void SetStateRun();
    void SetAnimal(Animal* animal_) { animal = animal_; }
    enemy_state GetState() const { return state; }

private:
    Animal* animal;
    enemy_state state;
};

#endif