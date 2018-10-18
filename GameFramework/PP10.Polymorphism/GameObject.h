#ifndef GameObject_h
#define GameObject_h
#include <SDL.h>
#include <string>

class GameObject
{
public:
    void Load(int x, int y, int width, int height, std::string textureID);
    void Draw(SDL_Renderer* pRenderer);
    void Update();
    void Clean();
protected:
    std::string textureID;
    int currentFrame;
    int currentRow;
    int x;
    int y;
    int width;
    int height;
};

#endif