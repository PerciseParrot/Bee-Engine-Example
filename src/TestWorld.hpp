#pragma once

#include "Bee/Entity.hpp"
#include "Bee/Graphics/HUDObject.hpp"
#include "Bee/World/World.hpp"

#include "Player.hpp"
#include "TextEntity.hpp"

class TestWorld : public World
{
public:
    TestWorld();
    virtual void onLoad();
    virtual void onUnload();
    virtual void update();
    virtual ~TestWorld();

private:
    uint32_t lastHUDUpdateTime = 0;
    TextEntity* textEntity;
    Player* player;
    HUDObject* frameTimeHUD;
    HUDObject* xPosHUD;
    HUDObject* yPosHUD;
    HUDObject* tileDataHUD;
};