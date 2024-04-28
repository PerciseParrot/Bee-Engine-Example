#pragma once

#include <Bee/Bee.hpp>

#include "Entities/Player.hpp"
#include "Entities/Teleporter.hpp"

class TestWorld : public World
{
public:
    TestWorld();
    virtual void init();
    virtual void onLoad();
    virtual void onUnload();
    virtual void update();
    virtual ~TestWorld();

private:
    uint32_t lastHUDUpdateTime = 0;
    Teleporter* teleporter;
    Player* player;
    HUDObject* frameTimeHUD;
    HUDObject* xPosHUD;
    HUDObject* yPosHUD;
    HUDObject* tileDataHUD;
};