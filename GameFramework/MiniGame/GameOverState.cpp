#include "GameOverState.h"
#include "States.h"
#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "AnimatedGraphic.h"
#include "MenuButton.h"
#include <iostream>

GameOverState* GameOverState::pInstance = nullptr;
const std::string GameOverState::gameOverID = "GAMEOVER";

bool GameOverState::OnEnter()
{
    if (!TextureManager::Instance()->Load("../assets/gameover.png", "gameovertext"))
    {
        return false;
    }
    if (!TextureManager::Instance()->Load("../assets/main.png", "mainbutton"))
    {
        return false;
    }
    if (!TextureManager::Instance()->Load("../assets/restart.png", "restartbutton"))
    {
        return false;
    }

    gameObjects.emplace_back(std::make_unique<AnimatedGraphic>(LoaderParams(864 / 2 - 95, 100, 190, 30, "gameovertext"), 2));
    gameObjects.emplace_back(std::make_unique<MenuButton>(LoaderParams(864 / 2 - 100, 200, 200, 80, "mainbutton"), GameOverToMain));
    gameObjects.emplace_back(std::make_unique<MenuButton>(LoaderParams(864 / 2 - 100, 300, 200, 80, "restartbutton"), RestartPlay));

    std::cout << "entering GameOverState\n";

    return true;
}

bool GameOverState::OnExit()
{
    for (std::vector<GameObject*>::size_type i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->Clean();
    }
    gameObjects.clear();
    TextureManager::Instance()->ClearFromTextureMap("gameovertext");
    TextureManager::Instance()->ClearFromTextureMap("mainbutton");
    TextureManager::Instance()->ClearFromTextureMap("restartbutton");
    InputHandler::Instance()->Reset();
    std::cout << "exiting GameOverState\n";

    return true;
}

void GameOverState::GameOverToMain()
{
    Game::Instance()->GetStateMachine()->ChangeState(MenuState::Instance());
}

void GameOverState::RestartPlay()
{
    Game::Instance()->GetStateMachine()->ChangeState(PlayState::Instance());
}