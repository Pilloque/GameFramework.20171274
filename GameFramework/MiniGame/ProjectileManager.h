#ifndef ProjectileManager_h
#define ProjectileManager_h
#include "Player.h"
#include <vector>
#include <memory>

class ProjectileManager
{
public:
    ProjectileManager(Player& player_, std::vector<std::unique_ptr<GameObject>>& missiles_) : player(player_), missiles(missiles_) {}
    void HandleInput();

private:
    Player& player;
    std::vector<std::unique_ptr<GameObject>>& missiles;
};

#endif