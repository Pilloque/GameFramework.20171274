#ifndef PlayState_h
#define PlayState_h
#include "GameState.h"

class PlayState : public GameState
{
public:
    ~PlayState() {}
    static PlayState* Instance()
    {
        if (pInstance == nullptr)
        {
            pInstance = new PlayState();
        }
        return pInstance;
    }
    virtual void Update();
    virtual void Render();
    virtual bool OnEnter();
    virtual bool OnExit();
    virtual std::string GetStateID() const { return playID; }
private:
    PlayState() {}
    static PlayState* pInstance;
    static const std::string playID;
};

#endif