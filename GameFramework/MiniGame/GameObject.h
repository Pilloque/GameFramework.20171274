#ifndef GameObject_h
#define GameObject_h
//#include <iostream>

class LoaderParams;

class GameObject
{
public:
    virtual void Draw() = 0;
    virtual void Update() = 0;
    virtual void Clean() = 0;

    void Destroy() { active = false; }
    bool IsActive() const { return active; }
    //~GameObject()
    //{
    //    std::cout << "Áö¿öÁü\n";
    //}

protected:
    GameObject(const LoaderParams& pParams) {}

    bool active = true;
};

#endif