#ifndef TextureManager_h
#define TextureManager_h
#include <SDL.h>
#include <string>
#include <map>

class TextureManager
{
public:
    ~TextureManager() {}

    bool Load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
    void Draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void DrawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    static TextureManager* Instance()
    {
        if (pInstance == 0)
        {
            pInstance = new TextureManager();
            return pInstance;
        }
        return pInstance;
    }

private:
    static TextureManager* pInstance;
    TextureManager() {}

    std::map<std::string, SDL_Texture*> textureMap;
};

//typedef TextureManager TheTextureManager;
//코드가 더러워지는 것 같아서 지웠습니다.
#endif