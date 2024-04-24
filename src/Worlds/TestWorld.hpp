#pragma once

#include <Bee/Entity.hpp>
#include <Bee/Graphics/HUDObject.hpp>
#include <Bee/World/World.hpp>

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
    float viewportScale = 1.0f;
    uint32_t lastHUDUpdateTime = 0;
    Teleporter* teleporter;
    Player* player;
    HUDObject* frameTimeHUD;
    HUDObject* xPosHUD;
    HUDObject* yPosHUD;
    HUDObject* tileDataHUD;
};