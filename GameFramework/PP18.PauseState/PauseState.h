#ifndef PauseState_h
#define PauseState_h
#include "GameState.h"

class PauseState : public GameState
{
public:
    ~PauseState() {}
    static PauseState* Instance()
    {
        if (pInstance == nullptr)
        {
            pInstance = new PauseState();
        }
        return pInstance;
    }
    virtual void Update();
    virtual void Render();
    virtual bool OnEnter();
    virtual bool OnExit();
    virtual std::string GetStateID() const { return pauseID; }
private:
    PauseState() {}
    static PauseState* pInstance;
    static void PauseToMain();
    static void ResumePlay();
    static const std::string pauseID;
};

#endif