#include "Game.h"
#include "TextureManager.h"

TextureManager* TextureManager::pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
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

        TextureManager::Instance()->Load("../assets/Background.png", "background", pRenderer);
        TextureManager::Instance()->Load("../assets/Trees.png", "trees", pRenderer);
        TextureManager::Instance()->Load("../assets/Orange Dog.png", "dog", pRenderer);

        SDL_SetRenderDrawColor(pRenderer, 0, 40, 60, 255);

		isRunning = true;
	}
	else
	{
		return false;
	}
	return true;
}

void Game::render()
{
	SDL_RenderClear(pRenderer);
    TextureManager::Instance()->Draw("background", 0, 0, 80 * 8, 60 * 8, pRenderer);
    TextureManager::Instance()->Draw("trees", 0, 0, 80 * 8, 60 * 8, pRenderer);
    TextureManager::Instance()->Draw("dog", 400, 360, 52 * 3, 32 * 3, pRenderer);
	SDL_RenderPresent(pRenderer);
}

void Game::update()
{
    currentFrame1 = int((SDL_GetTicks() / 150) % 6);
    currentFrame2 = int((SDL_GetTicks() / 75) % 6);
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(pWindow);
	SDL_DestroyRenderer(pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
		}
	}
}