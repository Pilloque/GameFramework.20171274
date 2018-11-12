#ifndef GameObject_h
#define GameObject_h
#include <SDL.h>
#include <string>
#include "Vector2D.h"

class LoaderParams;

class GameObject
{
public:
    virtual void Draw() = 0;
    virtual int Update() = 0;
    virtual void Clean() = 0;
    virtual int OnCollision(const GameObject& collider) = 0;

    virtual Vector2D GetPosition() const = 0;
    virtual int GetWidth() const = 0;
    virtual int GetHeight() const = 0;
    virtual std::string GetTag() const = 0;
protected:
    GameObject(const LoaderParams* pParams) {}
    virtual ~GameObject() {}
};
#endif