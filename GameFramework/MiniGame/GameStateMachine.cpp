#include "GameStateMachine.h"
#include "Camera.h"

void GameStateMachine::ChangeState(GameState *pState)
{
    if (pState != NULL)
    {
        if (currentState != NULL)
        {
            prevState = currentState;
            currentState->OnExit();

            Camera::Instance()->SetX(0);
        }
        currentState = pState;
        currentState->OnEnter();
    }
}

void GameStateMachine::PopState()
{
    ChangeState(prevState);
}

void GameStateMachine::Update()
{
    if (currentState != NULL)
        currentState->Update();
}

void GameStateMachine::Render()
{
    if (currentState != NULL)
        currentState->Render();
}