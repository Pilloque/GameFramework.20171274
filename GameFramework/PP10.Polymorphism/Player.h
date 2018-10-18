#ifndef Player_h
#define Player_h
#include "GameObject.h"

class Player : public GameObject
{
public:
    //void Load(int x, int y, int width, int height, std::string textureID);
    //void Draw(SDL_Renderer* pRenderer);
    void Update();
    void Clean();
};
#endif