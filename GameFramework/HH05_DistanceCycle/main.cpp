#include "Game.h"

void FrameDelay(int maxFPS);

Game* g_game = 0;

int main(int argc, char* argv[])
{
    g_game = new Game();
    g_game->Init("HH05", 100, 100, 640, 480, false);

    while (g_game->Running())
    {
        g_game->HandleEvents();
        g_game->Update();
        g_game->Render();

        FrameDelay(144);
    }
    g_game->Clean();
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