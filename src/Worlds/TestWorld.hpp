#pragma once

#include <Bee/Bee.hpp>

#include "Entities/Player.hpp"
#include "Entities/Teleporter.hpp"

class TestWorld : public World
{
public:
    TestWorld();
    void onLoad() override;
    void onUnload() override;
    void update() override;
    ~TestWorld() override;

private:
    uint32_t lastHUDUpdateTime = 0;
    Teleporter* teleporter;
    Player* player;
    HUDObject* frameTimeHUD;
    HUDObject* xPosHUD;
    HUDObject* yPosHUD;
    HUDObject* tileDataHUD;
};