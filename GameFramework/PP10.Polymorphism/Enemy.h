#ifndef Enemy_h
#define Enemy_h
#include "GameObject.h"

class Enemy : public GameObject
{
public:
    //void Load(int x, int y, int width, int height, std::string textureID);
    //void Draw(SDL_Renderer* pRenderer);
    void Update();
    void Clean();
};
#endif