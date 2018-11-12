#ifndef SDLGameObject_h
#define SDLGameObject_h
#include "GameObject.h"

class SDLGameObject : public GameObject
{
public:
    SDLGameObject(const LoaderParams* pParams);
    virtual void Draw();
    virtual int Update();
    virtual void Clean();
    virtual int OnCollision(const GameObject& collider);

    virtual Vector2D GetPosition() const { return position; }
    virtual int GetWidth() const { return width; }
    virtual int GetHeight() const { return height; }
    virtual std::string GetTag() const { return tag; }

protected:
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;
    int width;
    int height;
    int currentRow;
    int currentFrame;
    std::string textureID;
    std::string tag;

    
};
#endif SDLGameObject_h