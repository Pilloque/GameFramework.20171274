#ifndef SDLGameObject_h
#define SDLGameObject_h
#include "GameObject.h"
#include <string>

class SDLGameObject : public GameObject
{
public:
    SDLGameObject(const LoaderParams* pParams);
    virtual void Draw();
    virtual void Update();
    virtual void Clean();

protected:
    int x;
    int y;
    int width;
    int height;
    int currentRow;
    int currentFrame;
    std::string textureID;
};

#endif SDLGameObject_h