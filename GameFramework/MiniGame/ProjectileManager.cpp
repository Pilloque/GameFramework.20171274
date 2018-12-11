#include "ProjectileManager.h"
#include "InputHandler.h"
#include "Missile.h"

void ProjectileManager::HandleInput()
{
    if (InputHandler::Instance()->GetMouseButtonState(LEFT) || InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_SPACE))
    {
        static Uint32 nextFire = 0u;
        if (SDL_GetTicks() > nextFire)
        {
            Vector2D playerPos = player.GetPosition() + Vector2D(0, 16.0f);
            Vector2D direction = InputHandler::Instance()->GetMousePositionOnCamera() - playerPos;
            double angle = SDL_atan2(-direction.GetY(), -direction.GetX()) * 180 / M_PI;
            missiles.emplace_back(std::make_unique<Missile>(LoaderParams(int(playerPos.GetX()), int(playerPos.GetY()), 63, 16, "missile"), angle));
            nextFire = SDL_GetTicks() + 300;
        }
    }
}