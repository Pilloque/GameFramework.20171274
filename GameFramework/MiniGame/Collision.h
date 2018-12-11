#ifndef Collision_h
#define Collision_h
#include "GameObject.h"
#include "SDLGameObject.h"
#include "Vector2D.h"

class Collision
{
public:
    static bool AABB(SDLGameObject* p1, SDLGameObject* p2)
    {
        float leftA = p1->GetPosition().GetX();
        float rightA = p1->GetPosition().GetX() + p1->GetWidth() * p1->GetScale();
        float topA = p1->GetPosition().GetY();
        float bottomA = p1->GetPosition().GetY() + p1->GetHeight() * p1->GetScale();

        float leftB = p2->GetPosition().GetX();
        float rightB = p2->GetPosition().GetX() + p2->GetWidth() * p2->GetScale();
        float topB = p2->GetPosition().GetY();
        float bottomB = p2->GetPosition().GetY() + p2->GetHeight() * p2->GetScale();

        //If any of the sides from A are outside of B
        if (bottomA <= topB) { return false; }
        if (topA >= bottomB) { return false; }
        if (rightA <= leftB) { return false; }
        if (leftA >= rightB) { return false; }

        return true;
    }

    static bool AABB(GameObject* p1, GameObject* p2)
    {
        return AABB(dynamic_cast<SDLGameObject*>(p1), dynamic_cast<SDLGameObject*>(p2));
    }
};

#endif