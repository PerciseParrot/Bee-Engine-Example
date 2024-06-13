#pragma once

#include <Bee/Bee.hpp>

#include "Entities/Player.hpp"
#include "Entities/Teleporter.hpp"

class Farm : public World
{
public:
    Farm();
    void onLoad() override;
    void onUnload() override;
    void update() override;
    ~Farm() override;

private:
    Player* player{};
    Teleporter* teleporter{};
};