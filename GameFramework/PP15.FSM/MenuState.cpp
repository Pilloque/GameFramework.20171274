#include "MenuState.h"
#include <iostream>

MenuState* MenuState::pInstance = nullptr;
const std::string MenuState::menuID = "MENU";

void MenuState::Update()
{
    // nothing for now
}

void MenuState::Render()
{
    // nothing for now
}

bool MenuState::OnEnter()
{
    std::cout << "entering MenuState\n";
    return true;
}

bool MenuState::OnExit()
{
    std::cout << "exiting MenuState\n";
    return true;
}
