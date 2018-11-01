#include "InputHandler.h"
#include "Game.h"
#include "Vector2D.h"
#include <iostream>

InputHandler* InputHandler::pInstance = nullptr;

InputHandler::InputHandler()
{
    mousePosition = new Vector2D(0.0f, 0.0f);
    for (int i = 0; i < 3; i++)
    {
        mouseButtonStates.push_back(false);
    }
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
        if (event.type == SDL_MOUSEMOTION)
        {
            mousePosition->SetX(event.motion.x);
            mousePosition->SetY(event.motion.y);
        }
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                mouseButtonStates[LEFT] = true;
            }
            if (event.button.button == SDL_BUTTON_MIDDLE)
            {
                mouseButtonStates[MIDDLE] = true;
            }
            if (event.button.button == SDL_BUTTON_RIGHT)
            {
                mouseButtonStates[RIGHT] = true;
            }
        }
        else if (event.type == SDL_MOUSEBUTTONUP)
        {
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                mouseButtonStates[LEFT] = false;
            }
            if (event.button.button == SDL_BUTTON_MIDDLE)
            {
                mouseButtonStates[MIDDLE] = false;
            }
            if (event.button.button == SDL_BUTTON_RIGHT)
            {
                mouseButtonStates[RIGHT] = false;
            }
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

bool InputHandler::GetMouseButtonState(int buttonNumber)
{
    return mouseButtonStates[buttonNumber];
}

Vector2D* InputHandler::GetMousePosition()
{
    return mousePosition;
}