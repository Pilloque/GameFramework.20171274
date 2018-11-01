#ifndef InputHandler_h
#define InputHandler_h
#include <SDL.h>
#include <vector>

class Vector2D;

enum mouse_buttons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

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
    bool GetMouseButtonState(int buttonNumber);
    Vector2D* GetMousePosition();

private:
    InputHandler();
    ~InputHandler() {}
    static InputHandler* pInstance;
    const Uint8* keystates;

    std::vector<bool> mouseButtonStates;
    Vector2D* mousePosition;
};
#endif