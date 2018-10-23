#ifndef Game_h
#define Game_h
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

class GameObject;
class Monster;

class Game
{
public:
	Game() {}
	~Game() {}
	bool Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void Render();
	void Update();
	void HandleEvents();
	void Clean();
	bool Running() { return isRunning; }

private:
	SDL_Window * pWindow;
	SDL_Renderer* pRenderer;
	SDL_Texture* pTexture;
	bool isRunning;

    std::vector<GameObject*> gameObjects;
    Monster* monsterFast;
    Monster* monsterSlow;
};
#endif Game_h