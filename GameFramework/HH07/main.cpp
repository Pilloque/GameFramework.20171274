#include "Game.h"
#include <iostream>

void FrameDelay(int maxFPS);

int main(int argc, char* argv[])
{
    std::cout << "Game init attempt..." << std::endl;
    if (Game::Instance()->Init("HH07", 100, 100, 640, 480, false))
    {
        std::cout << "Game init success!\n";
        while (Game::Instance()->Running())
        {
            Game::Instance()->CheckCollision();
            Game::Instance()->HandleEvents();
            Game::Instance()->Update();
            Game::Instance()->Render();
            FrameDelay(144);
        }
    }
    else
    {
        std::cout << "Game init failure - " << SDL_GetError() << std::endl;
        return -1;
    }
    std::cout << "Game closing..." << std::endl;
    Game::Instance()->Clean();
    return 0;
}

void FrameDelay(int maxFPS)
{
    static const int latency = int((float)1000 / maxFPS + 0.5f);
    static unsigned int frameStart;
    static int frameTime;

    frameTime = SDL_GetTicks() - frameStart;
    if (frameTime < latency)
    {
        SDL_Delay(latency - frameTime);
    }
    frameStart = SDL_GetTicks();
}