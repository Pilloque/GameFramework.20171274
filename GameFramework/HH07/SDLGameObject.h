#ifndef SDLGameObject_h
#define SDLGameObject_h
#include "GameObject.h"
#include "Vector2D.h"
#include <string>

class SDLGameObject : public GameObject
{
public:
    SDLGameObject(const LoaderParams* pParams);
    virtual void Draw();
    virtual int Update();
    virtual void Clean();

protected:
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;
    int width;
    int height;
    int currentRow;
    int currentFrame;
    std::string textureID;

    
};
#endif SDLGameObject_h