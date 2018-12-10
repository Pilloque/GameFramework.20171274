#include "MenuState.h"
#include "Game.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "PlayState.h"
#include <iostream>

MenuState* MenuState::pInstance = nullptr;
const std::string MenuState::menuID = "MENU";

bool MenuState::OnEnter()
{
    if (!TextureManager::Instance()->Load("../assets/button.png", "playbutton"))
    {
        return false;
    }
    if (!TextureManager::Instance()->Load("../assets/exit.png", "exitbutton"))
    {
        return false;
    }

    gameObjects.emplace_back(std::make_unique<MenuButton>(LoaderParams(864 / 2 - 200, 120, 400, 100, "playbutton"), MenuToPlay));
    gameObjects.emplace_back(std::make_unique<MenuButton>(LoaderParams(864 / 2 - 200, 320, 400, 100, "exitbutton"), ExitFromMenu));

    std::cout << "entering MenuState\n";

    return true;
}

bool MenuState::OnExit()
{
    for (std::vector<GameObject*>::size_type i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->Clean();
    }
    gameObjects.clear();
    TextureManager::Instance()->ClearFromTextureMap("playbutton");
    TextureManager::Instance()->ClearFromTextureMap("exitbutton");
    std::cout << "exiting MenuState\n";

    return true;
}

void MenuState::MenuToPlay()
{
    Game::Instance()->GetStateMachine()->ChangeState(PlayState::Instance());
}

void MenuState::ExitFromMenu()
{
    Game::Instance()->Quit();
}