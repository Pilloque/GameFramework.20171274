#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Box.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "Collision.h"
#include <iostream>

Game* Game::pInstance = 0;

bool Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        if (fullscreen)
        {
            pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_FULLSCREEN_DESKTOP);
        }
        else
        {
            pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
        }

        if (pWindow != 0)
        {
            pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
        }

        isRunning = true;

        if (!TextureManager::Instance()->Load("../assets/animate-alpha.png", "animate", pRenderer))
        {
            return false;
        }
        if (!TextureManager::Instance()->Load("../assets/hoseo.png", "hoseo", pRenderer))
        {
            return false;
        }
        if (!TextureManager::Instance()->Load("../assets/box.png", "box", pRenderer))
        {
            return false;
        }

        GenerateObject(new Player(new LoaderParams(100, 100, 128, 82, "animate", "player")));
        GenerateObject(new Box(new LoaderParams(500, 50, 100, 100, "box", "box")));
        GenerateObject(new Box(new LoaderParams(500, 200, 100, 100, "box", "box")));
        GenerateObject(new Box(new LoaderParams(350, 350, 100, 100, "box", "box")));
        GenerateObject(new Box(new LoaderParams(200, 350, 100, 100, "box", "box")));
        GenerateObject(new Box(new LoaderParams(50, 350, 100, 100, "box", "box")));

        SDL_SetRenderDrawColor(pRenderer, 0, 40, 60, 255);

    }
    else
    {
        return false;
    }
    return true;
}

void Game::GenerateObject(GameObject* gameObj)
{
    gameObjects.push_back(gameObj);
}

void Game::DestroyObject(GameObject* gameObj)
{
    std::cout << "오브젝트 제거됨\n";
    std::vector<GameObject*>::iterator it;
    it = find(gameObjects.begin(), gameObjects.end(), gameObj);
    gameObjects.erase(it);
}

void Game::Render()
{
    SDL_RenderClear(pRenderer);
    for (std::vector<GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
    {
        gameObjects[i]->Draw();
    }
    SDL_RenderPresent(pRenderer);
}

void Game::Update()
{
    std::vector<GameObject*>::size_type i = 0;
    while (i < gameObjects.size())
    {
        if (gameObjects[i]->Update())
        {
            continue;
        }

        i++;
    }
}

void Game::Clean()
{
    InputHandler::Instance()->Clean();
}

void Game::HandleEvents()
{
    InputHandler::Instance()->Update();
}

void Game::CheckCollision()
{
    for (std::vector<GameObject*>::size_type i = 0; i < gameObjects.size() - 1; i++)
    {
        std::vector<GameObject*>::size_type j = i + 1;
        while (j < gameObjects.size())
        {
            if (Collision::AABB(*gameObjects[i],*gameObjects[j]))
            {
                if (gameObjects[i]->OnCollision(*gameObjects[j])
                    || gameObjects[j]->OnCollision(*gameObjects[i]))
                {
                    continue;
                }
            }

            j++;
        }
    }
}