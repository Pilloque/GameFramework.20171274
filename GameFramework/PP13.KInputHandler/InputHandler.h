#ifndef InputHandler_h
#define InputHandler_h
#include <SDL.h>



class InputHandler
{
public:
    static InputHandler* Instance()
    {
        if (pInstance == nullptr)
        {
            pInstance = new InputHandler();
        }
        return pInstance;
    }
    void Update();
    void Clean();
    bool IsKeyDown(SDL_Scancode key);

private:
    InputHandler();
    ~InputHandler() {}
    static InputHandler* pInstance;
    const Uint8* keystates;
};
#endif