#pragma once

#include <Bee/World/World.hpp>

#include "Entities/Player.hpp"
#include "Entities/Teleporter.hpp"

class Farm : public World
{
public:
    virtual void init();
    virtual void onLoad();
    virtual void onUnload();
    virtual void update();
    virtual ~Farm();

private:
    Player* player;
    Teleporter* teleporter;
};