#include "Timer.h"
#include <SDL.h>

Timer* Timer::pInstance = nullptr;

void Timer::StartTimer()
{
    startTime = SDL_GetTicks();
}

std::string Timer::GetTime()
{
    unsigned int second;
    unsigned int minute;
    std::string strSecond;
    std::string strMinute;
    Uint32 currentTime;
    
    currentTime = SDL_GetTicks() - startTime;
    second = (currentTime / 1000) % 60;
    minute = currentTime / 1000 / 60;

    if (second < 10)
    {
        strSecond = '0' + std::to_string(second);
    }
    else
    {
        strSecond = std::to_string(second);
    }

    if (minute < 10)
    {
        strMinute = '0' + std::to_string(minute);
    }
    else
    {
        strMinute = std::to_string(minute);
    }

    oldTime = strMinute + ':' + strSecond;
    return oldTime;
}

std::string Timer::GetOldTime()
{
    return oldTime;
}