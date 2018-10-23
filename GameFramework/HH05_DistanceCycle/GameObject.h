#ifndef GameObject_h
#define GameObject_h
#include <SDL.h>
#include <string>

class GameObject
{
public:
    virtual void Load(int x, int y, int width, int height, std::string textureID);
    virtual void Draw(SDL_Renderer* pRenderer);
    virtual void Update();
    virtual void Clean();
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