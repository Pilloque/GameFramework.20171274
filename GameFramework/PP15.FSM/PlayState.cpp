#include "PlayState.h"
#include <iostream>

PlayState* PlayState::pInstance = nullptr;
const std::string PlayState::playID = "PLAY";

void PlayState::Update()
{
    // nothing for now
}
void PlayState::Render()
{
    // nothing for now
}
bool PlayState::OnEnter()
{
    std::cout << "entering PlayState\n";
    return true;
}

bool PlayState::OnExit()
{
    std::cout << "exiting PlayState\n";
    return true;
}