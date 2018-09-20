#include "Game.h"
#include <SDL_image.h>

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		if (fullscreen)
		{
			m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_FULLSCREEN_DESKTOP);
		}
		else
		{
			m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		}

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		SDL_Surface* pTempSurface = IMG_Load("../assets/animate-alpha.png");
		m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
		SDL_FreeSurface(pTempSurface);
        m_sourceRectangle.w = 128;
        m_sourceRectangle.h = 82;

        m_destinationRectangle.x = m_sourceRectangle.x = 0;
        m_destinationRectangle.y = m_sourceRectangle.y = 0;
        m_destinationRectangle.w = m_sourceRectangle.w;
        m_destinationRectangle.h = m_sourceRectangle.h;

        SDL_SetRenderDrawColor(m_pRenderer, 0, 40, 60, 255);

		m_bRunning = true;
	}
	else
	{
		return false;
	}
	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_RIGHT] && posx < 500)
    {
        posx += 0.1f;
        m_sourceRectangle.x = 128 * int((SDL_GetTicks() / 100) % 6);
    }
    else if (state[SDL_SCANCODE_LEFT] && posx > 0)
    {
        posx -= 0.1f;
        m_sourceRectangle.x = 128 * int((SDL_GetTicks() / 100) % 6);
    }
    else if (state[SDL_SCANCODE_DOWN] && posy < 480)
    {
        posy += 0.1f;
        m_sourceRectangle.x = 128 * int((SDL_GetTicks() / 100) % 6);
    }
    else if (state[SDL_SCANCODE_UP] && posy > 0)
    {
        posy -= 0.1f;
        m_sourceRectangle.x = 128 * int((SDL_GetTicks() / 100) % 6);
    }
    m_destinationRectangle.x = (int)posx;
    m_destinationRectangle.y = (int)posy;
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
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
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}