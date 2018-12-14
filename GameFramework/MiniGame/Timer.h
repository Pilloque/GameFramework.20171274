#ifndef Timer_h
#define Timer_h
#include <string>

class Timer
{
public:
    ~Timer() {}
    static Timer* Instance()
    {
        if (pInstance == nullptr)
        {
            pInstance = new Timer();
        }
        return pInstance;
    }

    void StartTimer();
    std::string GetTime();
    std::string GetOldTime();

private:
    Timer() {}
    static Timer* pInstance;

    unsigned int startTime;
    std::string oldTime;
};

#endif