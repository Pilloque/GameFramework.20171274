#ifndef Game_h
#define Game_h
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Game
{
public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return isRunning; }

private:
	SDL_Window * pWindow;
	SDL_Renderer* pRenderer;
	SDL_Texture* pTexture;
	bool isRunning;
    int currentFrame1;
    int currentFrame2;
};
#endif Game_h