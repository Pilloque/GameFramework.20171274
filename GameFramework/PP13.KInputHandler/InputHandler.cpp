#include "InputHandler.h"
#include "Game.h"
#include <iostream>

InputHandler* InputHandler::pInstance = nullptr;

InputHandler::InputHandler()
{
}

void InputHandler::Clean()
{
    //std::cout << "cleaning game\n";
    //SDL_DestroyWindow(pWindow);
    //SDL_DestroyRenderer(Game::GetRenderer());
    //SDL_Quit();
}

void InputHandler::Update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            Game::Instance()->Quit();
        }
        if (event.type == SDL_KEYUP)
        {
            keystates = SDL_GetKeyboardState(0);
        }
        if (event.type == SDL_KEYDOWN)
        {
            keystates = SDL_GetKeyboardState(0);
        }
    }
}

bool InputHandler::IsKeyDown(SDL_Scancode key)
{
    if (keystates != 0)
    {
        if (keystates[key] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}