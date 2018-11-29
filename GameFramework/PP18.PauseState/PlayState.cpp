#include "PlayState.h"
#include "PauseState.h"
#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "Player.h"
#include <iostream>

PlayState* PlayState::pInstance = nullptr;
const std::string PlayState::playID = "PLAY";

void PlayState::Update()
{
    if (InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_ESCAPE))
    {
        Game::Instance()->GetStateMachine()->ChangeState(PauseState::Instance());
    }
    for (std::vector<GameObject*>::size_type i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->Update();
    }
}

void PlayState::Render()
{
    for (std::vector<GameObject*>::size_type i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->Draw();
    }
}

bool PlayState::OnEnter()
{
    if (!TextureManager::Instance()->Load("../assets/helicopter.png", "helicopter", Game::Instance()->GetRenderer()))
    {
        return false;
    }

    GameObject* player = new Player(new LoaderParams(100, 100, 128, 55, "helicopter"));
    gameObjects.push_back(player);
    std::cout << "entering PlayState\n";

    return true;
}

bool PlayState::OnExit()
{
    for (std::vector<GameObject*>::size_type i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->Clean();
    }
    gameObjects.clear();

    TextureManager::Instance()->ClearFromTextureMap("helicopter");
    std::cout << "exiting PlayState\n";

    return true;
}