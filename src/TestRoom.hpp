#pragma once

#include "Bee/Graphics/HUDObject.hpp"
#include "Bee/World/World.hpp"

#include "Player.hpp"

class TestRoom : public World
{
public:
    TestRoom();
    virtual void onLoad();
    virtual void onUnload();
    virtual void update();
    virtual ~TestRoom();

private:
    uint32_t lastHUDUpdateTime = 0;
    Player* player;
    HUDObject* frameTimeHUD;
    HUDObject* xPosHUD;
    HUDObject* yPosHUD;
    HUDObject* tileDataHUD;
};