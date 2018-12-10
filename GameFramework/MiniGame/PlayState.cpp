#include "PlayState.h"
#include "States.h"
#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "Camera.h"
#include "SDLGameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Animal.h"
#include "Missile.h"
#include "Aim.h"
#include "Background.h"
#include <iostream>

PlayState* PlayState::pInstance = nullptr;
const std::string PlayState::playID = "PLAY";

void PlayState::Update()
{
    if (InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_ESCAPE))
    {
        Game::Instance()->GetStateMachine()->ChangeState(PauseState::Instance());
        return;
    }
    if (InputHandler::Instance()->GetMouseButtonState(LEFT) || InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_SPACE))
    {
        static Uint32 nextFire = 0u;
        if (SDL_GetTicks() > nextFire)
        {
            Vector2D playerPos = static_cast<SDLGameObject*>(player.get())->GetPosition();
            Vector2D direction = InputHandler::Instance()->GetMousePositionOnCamera() - playerPos;
            double angle = SDL_atan2(-direction.GetY(), -direction.GetX()) * 180 / M_PI;
            std::cout << angle <<std::endl;
            missiles.emplace_back(std::make_unique<Missile>(LoaderParams(int(playerPos.GetX()), int(playerPos.GetY()), 63, 16, "missile"), angle));
            nextFire = SDL_GetTicks() + 300;
        }
    }

    for (auto& objects : backgrounds)
    {
        objects->Update();
    }
    player->Update();
    for (auto& objects : enemies)
    {
        objects->Update();
    }
    for (auto& objects : animals)
    {
        objects->Update();
    }
    for (auto& objects : missiles)
    {
        objects->Update();
    }
    for (auto& objects : ui)
    {
        objects->Update();
    }
    //if (CheckCollision(dynamic_cast<SDLGameObject*>(gameObjects[0]), dynamic_cast<SDLGameObject*>(gameObjects[1])))
    //{
    //    Game::Instance()->GetStateMachine()->ChangeState(GameOverState::Instance());
    //}
}

void PlayState::Render()
{
    for (auto& objects : backgrounds)
    {
        objects->Draw();
    }
    player->Draw();
    for (auto& objects : enemies)
    {
        objects->Draw();
    }
    for (auto& objects : animals)
    {
        objects->Draw();
    }
    for (auto& objects : missiles)
    {
        objects->Draw();
    }
    for (auto& objects : ui)
    {
        objects->Draw();
    }
}

bool PlayState::OnEnter()
{
    if (!TextureManager::Instance()->Load("../assets/minigame_background.png", "background"))
    {
        return false;
    }
    if (!TextureManager::Instance()->Load("../assets/helicopter.png", "helicopter"))
    {
        return false;
    }
    if (!TextureManager::Instance()->Load("../assets/helicopter2.png", "helicopter2"))
    {
        return false;
    }
    if (!TextureManager::Instance()->Load("../assets/animate-alpha.png", "animal"))
    {
        return false;
    }
    if (!TextureManager::Instance()->Load("../assets/missile.png", "missile"))
    {
        return false;
    }
    if (!TextureManager::Instance()->Load("../assets/aim.png", "aim"))
    {
        return false;
    }

    backgrounds[0] = std::make_unique<Background>(LoaderParams(0, 0, 432, 270, 2, "background"));
    backgrounds[1] = std::make_unique<Background>(LoaderParams(864, 0, 432, 270, 2, "background"));
    player = std::make_unique<Player>(LoaderParams(100, 100, 128, 55, 0.7f, "helicopter"));
    enemies.emplace_back(std::make_unique<Enemy>(LoaderParams(300, 300, 128, 55, 0.7f, "helicopter2")));
    ui.emplace_back(std::make_unique<Aim>(LoaderParams(0, 0, 11, 11, 2, "aim")));
    for (int i = 0; i < 8; i++)
    {
        animals.emplace_back(std::make_unique<Animal>(LoaderParams(i * 100, 400, 128, 82, "animal")));
    }

    SDL_ShowCursor(SDL_DISABLE);
    Camera::Instance()->SetX(100);

    std::cout << "entering PlayState\n";

    return true;
}

bool PlayState::OnExit()
{
    backgrounds[0].reset();
    backgrounds[1].reset();
    player.reset();
    enemies.clear();
    animals.clear();
    missiles.clear();
    ui.clear();

    TextureManager::Instance()->ClearFromTextureMap("background");
    TextureManager::Instance()->ClearFromTextureMap("helicopter");
    TextureManager::Instance()->ClearFromTextureMap("helicopter2");
    TextureManager::Instance()->ClearFromTextureMap("missile");
    TextureManager::Instance()->ClearFromTextureMap("aim");

    SDL_ShowCursor(SDL_ENABLE);

    std::cout << "exiting PlayState\n";

    return true;
}

bool PlayState::CheckCollision(SDLGameObject* p1, SDLGameObject* p2)
{
    float leftA, leftB;
    float rightA, rightB;
    float topA, topB;
    float bottomA, bottomB;

    leftA = p1->GetPosition().GetX();
    rightA = p1->GetPosition().GetX() + p1->GetWidth() * p1->GetScale();
    topA = p1->GetPosition().GetY();
    bottomA = p1->GetPosition().GetY() + p1->GetHeight() * p1->GetScale();

    //Calculate the sides of rect B
    leftB = p2->GetPosition().GetX();
    rightB = p2->GetPosition().GetX() + p2->GetWidth() * p2->GetScale();
    topB = p2->GetPosition().GetY();
    bottomB = p2->GetPosition().GetY() + p2->GetHeight() * p2->GetScale();

    //If any of the sides from A are outside of B
    if (bottomA <= topB) { return false; }
    if (topA >= bottomB) { return false; }
    if (rightA <= leftB) { return false; }
    if (leftA >= rightB) { return false; }

    return true;
}