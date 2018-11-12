#ifndef Game_h
#define Game_h
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

class GameObject;

class Game
{
public:
	~Game() {}
    static Game* Instance()
    {
        if (pInstance == 0)
        {
            pInstance = new Game();
            return pInstance;
        }
        return pInstance;
    }
	bool Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void GenerateObject(GameObject* gameObj);
    void DestroyObject(GameObject* gameObj);
	void Render();
	void Update();
	void Clean();
	void HandleEvents();
    void CheckCollision();
	bool Running() { return isRunning; }
    void Quit() { isRunning = false; }
    
    SDL_Renderer* GetRenderer() const { return pRenderer; }

private:
    Game() {}
    static Game* pInstance;

	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
	bool isRunning;

    std::vector<GameObject*> gameObjects;
};
#endif Game_h